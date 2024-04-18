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
// for write comma in the macro-call. Why not?
// someNumber also would be nice, but it conflicts with something in other libs
// Who does use small 'o'? No one but me :D
#define o ,

// Enables serialization feature for built-in RapidJSON literals
// and 3P-libs types that doesn't have inner serialization definitions.
// Must be only struct member defined with SERI_S or SERI_ROOT_V
#define SERI_V(NonSerializableT, name, value) \
Serialization::SerializableVariable<NonSerializableT, ExternalJsonConversions> name = \
{ #name, NonSerializableT(value), this }

// For creating a std::string serializable variable
#define SERI_STR_V(Name, DefaultValue) SERI_V(std::string, Name, DefaultValue)

// For making a struct serializable. It may contain a SERI_V definitions
// Refer to YourStructName as YourStructNameTemplate<YourJsonConversionSet>
//
// You can use your original YourStructName for refer to it if you set up it
// program-wide:
// #define PROGRAM_WIDE_DEFAULT_JSON_CONVERSION_TYPE YourJsonConversionSet
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
#define SERI_C(YourStructName) \
inline YourStructName##Template(const char* name, Serialization::SerializableStruct<ExternalJsonConversions>* outer) \
: Serialization::SerializableStruct<ExternalJsonConversions>::SerializableStruct(name) \
{ outer->EnableMemberSerialization(this); } \
inline YourStructName##Template(const char* name) \
: Serialization::SerializableStruct<ExternalJsonConversions>::SerializableStruct(name) { }


// For composite SerializableStruct into SerializableVariable
#define SERI_COMPOSITE_V(SerializableT, name) \
SerializableT##Template<ExternalJsonConversions> name = { #name, this }

// For main variable definition of the serializable hierarchy
// TODO Make custom ConversionSet available for entire serializable hierarchy
#define SERI_ROOT_V(SerializableT, name) \
SerializableT##Template<PROGRAM_WIDE_DEFAULT_JSON_CONVERSION_TYPE> name = { #name "ROOT" }

// Simple declaration define for 3P-lib conversion function
// Use 'json' variable for operate on your 3P-lib type
#define SERI_fromJson(ThirdPartyType, thirdPartyValue) \
static inline void fromJson(ThirdPartyType& thirdPartyValue, const rapidjson::Value& json)

// Simple define for 3P-lib conversion function declaration
// You must just return rapidjson::Value based on your 3P-lib type
#define SERI_toJson(ThirdPartyType, thirdPartyValue) \
static inline rapidjson::Value toJson(const ThirdPartyType& thirdPartyValue, rapidjson::Document::AllocatorType& allocator)

// For simplification AddMember function, invoke for rapidjson::Value() object:
// rapidjson::Value().SERI_Add(...)
#define SERI_ADD(tag, literalObject) \
AddMember(rapidjson::StringRef(tag), rapidjson::Value(literalObject), allocator)

#endif //SPACESHIPBP_IMPLMACROSES_H
