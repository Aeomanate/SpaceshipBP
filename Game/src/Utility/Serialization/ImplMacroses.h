#ifndef SPACESHIPBP_IMPLMACROSES_H
#define SPACESHIPBP_IMPLMACROSES_H

#include <rapidjson/document.h>

// For reuse all of this macro you may redefine this before include this Serialization lib
// and maybe undef it at the end of the file for keep save original behaviour
#ifndef PROGRAM_WIDE_DEFAULT_JSON_CONVERSION_TYPE
namespace Serialization { struct EmptyUserConversions { }; }
#define PROGRAM_WIDE_DEFAULT_JSON_CONVERSION_TYPE Serialization::EmptyUserConversions
#endif

// The smallest letter for nice representing the comma
// for write comma in the macro-call.
#define o ,

// Enables serialization feature for built-in RapidJSON literals
// and 3P-libs types that doesn't have inner serialization definitions.
// Must be only struct member defined with SERI_S or SERI_ROOT_V
#define SERI_V(NonSerializableT, name, value) \
    using SeriVarType_##name = Serialization::SerializableVariable<NonSerializableT, ExternalJsonConversions>; \
    SeriVarType_##name name = { #name, NonSerializableT(value), this }

// For creating a std::string serializable variable
#define SERI_STR_V(Name, DefaultValue) \
    SERI_V(std::string, Name, DefaultValue)

// For making a struct serializable. It may contain a SERI_V definitions
// Refer to YourStructName as YourStructNameTemplate<YourJsonConversionSet>
//
// You can use your original YourStructName for refer to it if you set up it
// program-wide:
// #define PROGRAM_WIDE_DEFAULT_JSON_CONVERSION_TYPE YourJsonConversionSet
//
// Concatenation with ##Template is required for save original struct filename
#define SERI_S(YourStructName) \
    template <class ExternalJsonConversions> \
    struct YourStructName##Template; \
     \
    using YourStructName = \
    YourStructName##Template<PROGRAM_WIDE_DEFAULT_JSON_CONVERSION_TYPE>; \
     \
    template <class ExternalJsonConversions> \
    struct YourStructName##Template: public Serialization::SerializableStruct<ExternalJsonConversions>


// Each serializable struct must declare additional constructors
// for be able to handle its nested serializable variables/structs
#define SERI_C(YourStructName)                                                                                      \
    using SeriStructBase = Serialization::SerializableStruct<ExternalJsonConversions>;                              \
                                                                                                                    \
    /* For defining inner members that already have inner default initialization                                    \
     */                                                                                                             \
    inline constexpr YourStructName##Template(const char* name, SeriStructBase* outer)                              \
    : SeriStructBase::SerializableStruct(name)                                                                      \
    { outer->EnableMemberSerialization(this); }                                                                     \
                                                                                                                    \
    /* For root SerializableTemplate */                                                                             \
    inline constexpr YourStructName##Template(const char* name)                                                     \
    : SeriStructBase::SerializableStruct(name)                                                                      \
    { }                                                                                                             \
                                                                                                                    \
    /* Helper function for unfold parameter pack via enumerating each argument                                      \
     */                                                                                                             \
    template<class... Params, std::size_t... i>                                                                     \
    inline constexpr void __memberInitializer(std::index_sequence<i...>, Params&&... args)                          \
    {                                                                                                               \
        (                                                                                                           \
            ( this->template AssignToMember<Params>(i, std::forward<Params>(args)) ), ...                           \
        );                                                                                                          \
    }                                                                                                               \
                                                                                                                    \
    /* For case when you need to initialize each field of inner SeriStruct */                                       \
    template<class... Params, class Indexes = std::index_sequence_for<Params...>>                                   \
    inline constexpr YourStructName##Template(const char* name, SeriStructBase* outer, Params&& ... args)           \
    : YourStructName##Template(name, outer)                                                                         \
    {                                                                                                               \
        __memberInitializer(Indexes{}, std::forward<Params>(args)...);                                              \
    }


// For composite of folded SerializableStruct
#define SERI_COMPOSITE_V(SerializableT, name) \
    SerializableT##Template<ExternalJsonConversions> name = { #name, this }

// For composition when you need initialize each field of inner SerializableStruct
#define SERI_COMPOSITE_V_MEMBERS_INIT(SerializableStructT, name, ...) \
    SerializableStructT name = { #name, this, __VA_ARGS__ }


// For main variable definition of the serializable hierarchy
// TODO Make custom ConversionSet available for entire serializable hierarchy without global define of user struct
#define SERI_ROOT_V(SerializableT, name) \
    SerializableT##Template<PROGRAM_WIDE_DEFAULT_JSON_CONVERSION_TYPE> name = { #name "ROOT" }

// Simple declaration define for 3P-lib conversion function
// Use 'json' variable for operate on your 3P-lib type
#define SERI_fromJson(ThirdPartyType, thirdPartyValue) \
    static inline void fromJson(ThirdPartyType& thirdPartyValue, const rapidjson::Value& json)

// Simple define for 3P-lib conversion function declaration
// You must just return rapidjson::Value based on your 3P-lib type
#define SERI_toJson(ThirdPartyType, thirdPartyValue) \
    static inline rapidjson::Value                   \
    toJson(const ThirdPartyType& thirdPartyValue, rapidjson::Document::AllocatorType& allocator)

// For simplification AddMember function, invoke for rapidjson::Value() object:
// rapidjson::Value().SERI_Add(...)
#define SERI_ADD(tag, builtinObject) \
    AddMember(rapidjson::StringRef(tag), rapidjson::Value(builtinObject), allocator)

#endif //SPACESHIPBP_IMPLMACROSES_H
