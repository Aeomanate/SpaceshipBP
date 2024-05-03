#ifndef SPACESHIPBP_SERIALIZABLE_IMPL_H
#define SPACESHIPBP_SERIALIZABLE_IMPL_H

#include <string>
#include <unordered_set>
#include <vector>
#include <type_traits>
#include <fstream>
#include <functional>
#include <cassert>
#include <rapidjson/encodedstream.h>
#include <rapidjson/document.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/prettywriter.h>
#include <rapidjson/istreamwrapper.h>
#include "ImplStdJsonConverters.h"
#include "Utility/Logger/Logger.h"

namespace Serialization
{
    using JsonVal = rapidjson::Value;
    using JsonDoc = rapidjson::Document;
    using AllocType = JsonDoc::AllocatorType;

    /// Main concepts that must be implemented by UserSeriType for to/from json conversion availability
    template<class UserType, class ExternalJsonConverters>
    concept HasFromJsonUserCast = requires(UserType& userValue)
    { { ExternalJsonConverters::fromJson(userValue, JsonVal()) } -> std::convertible_to<void>; };

    template<class UserType, class ExternalJsonConverters>
    concept HasToJsonUserCast = requires(UserType& userValue, AllocType& allocator)
    { { ExternalJsonConverters::toJson(userValue, allocator) } -> std::convertible_to<JsonVal>; };

    template <class UserType>
    concept RapidJsonType =
        std::is_same_v<UserType, int32_t>
        || std::is_same_v<UserType, int64_t>
        || std::is_same_v<UserType, uint32_t>
        || std::is_same_v<UserType, uint64_t>
        || std::is_same_v<UserType, double>
        || std::is_same_v<UserType, float>
        || std::is_same_v<UserType, bool>;


    template <class UserType, class UserDefinedJsonConversionSet>
    class SerializableVariable;
    template <class UserDefinedJsonConversionSet>
    class SerializableStruct;

    namespace Internal
    {
        // Base converter templates for literal types
        template<RapidJsonType SomeLiteralType>
        void fromJsonLiteral(SomeLiteralType& userValue, const JsonVal& initializer)
        { userValue = initializer.template Get<SomeLiteralType>(); }

        template<RapidJsonType SomeLiteralType>
        JsonVal toJsonLiteral(const SomeLiteralType& userValue, AllocType&)
        { return JsonVal(userValue); }

        // Composition: SerializableStruct in SerializableStruct
        // or SerializableVariable in SerializableStruct
        template <class SeriStruct>
        concept SerializableComposition =
        requires (const SeriStruct& cVal, SeriStruct& rVal, const JsonVal& initializer, AllocType& allocator)
        {
            rVal.SetFromJson(initializer);
            static_cast<JsonVal>(cVal, allocator);
        };

        template<SerializableComposition SerializableStruct>
        void fromJsonComposite(SerializableStruct& serializableStruct, const JsonVal& initializer)
        { serializableStruct.SetFromJson(initializer); }

        template<SerializableComposition SerializableStruct>
        JsonVal toJsonComposite(const SerializableStruct& serializableStruct, AllocType&)
        { return static_cast<JsonVal>(serializableStruct); }


        // Compile-time helper for choosing right converter function based on passed type (custom or literal)
        template<class UserType, class ExternalJsonConverters>
        struct Converter
        {
            using FromJsonFuncPtrType = void (*)(UserType&, const JsonVal&);
            using ToJsonFuncPtrType = JsonVal(*)(const UserType&, AllocType&);

            static constexpr FromJsonFuncPtrType GetFromJson()
            {
                if constexpr (HasFromJsonUserCast<UserType, StdConverters>)
                { return &StdConverters::fromJson; }
                else if constexpr (SerializableComposition<UserType>)
                { return &fromJsonComposite; }
                else if constexpr (RapidJsonType<UserType>)
                { return &fromJsonLiteral; }
                else if constexpr (HasFromJsonUserCast<UserType, ExternalJsonConverters>)
                { return &ExternalJsonConverters::fromJson; }
                else
                {
                    static_assert(false, "This user type must define a fromJsonLiteral converter");
                }
            }

            static constexpr ToJsonFuncPtrType GetToJson()
            {
                if constexpr (HasToJsonUserCast<UserType, StdConverters>)
                { return &StdConverters::toJson; }
                else if constexpr (SerializableComposition<UserType>)
                { return &toJsonComposite; }
                else if constexpr (RapidJsonType<UserType>)
                { return &toJsonLiteral; }
                else if constexpr (HasToJsonUserCast<UserType, ExternalJsonConverters>)
                { return &ExternalJsonConverters::toJson; }
                else
                {
                    static_assert(false, "This user type must define a toJson converter");
                }
            }
        };

        // For converting visitor function to lambda correctly
        template <typename Return, typename... Args>
        struct LambdaTraitsImpl {
            LambdaTraitsImpl(std::template function<Return(Args...)>) {}
            using return_type = Return;
            using arg_types = std::tuple<Args...>;

            template <size_t i>
            using ArgType = typename std::tuple_element<i, arg_types>::type;
        };

        template <typename Lambda>
        struct LambdaTraits
        : public decltype(LambdaTraitsImpl(std::function{ std::declval<Lambda>()}))
        {};
    };


    enum class SeriObjectType
    {
        UNDEFINED,
        VARIABLE,
        STRUCT
    };

    /// A base class for any serializable variable for both user-defined and literal type
    class SerializableBase
    {
        template <class UserType, class UserDefinedJsonConversionSet>
        friend class SerializableVariable;
        template <class UserDefinedJsonConversionSet>
        friend class SerializableStruct;

    public: // Main methods
        explicit SerializableBase(const char* name)
            : name { name }
        { }

        virtual ~SerializableBase() = default;

        operator std::string()
        {
            rapidjson::StringBuffer buffer;
            rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(buffer);
            writer.SetFormatOptions(rapidjson::kFormatSingleLineArray);

            ToJson().Accept(writer);

            return buffer.GetString();
        }

        template <class OStream>
        friend OStream& operator<< (OStream&& out, SerializableBase& serializable)
        {
            assert(out && "Out thread is corrupted");
            out << static_cast<std::string>(serializable);
            return out;
        }

        template <class IStream>
        friend IStream& operator>> (IStream&& in, SerializableBase& serializable)
        {
            rapidjson::IStreamWrapper inStreamWrapper = in;
            rapidjson::AutoUTFInputStream<unsigned, rapidjson::IStreamWrapper> encodedStream = inStreamWrapper;

            JsonDoc document;
            document.ParseStream(encodedStream);
            StoreNewDocumentAllocator(document.GetAllocator());

            serializable.isParseError = document.HasParseError();
            if(serializable.isParseError)
            {
                in.setstate(std::ios_base::failbit);
                return in;
            }

            const JsonVal& jsonRoot = document.GetObject();
            JsonVal::ConstMemberIterator currentStructObjectIt = jsonRoot.FindMember(serializable.name.c_str());
            if(currentStructObjectIt == jsonRoot.MemberEnd())
            {
                serializable.isParseError = true;
                in.setstate(std::ios_base::failbit);
                return in;
            }
            const JsonVal& currentStructJson = currentStructObjectIt->value;

            // TODO Make versioning for each json field definition
            if(!serializable.SetFromJson(currentStructJson))
            {
                serializable.isParseError = true;
                in.setstate(std::ios_base::failbit);
                return in;
            }

            return in;
        }

        static bool HasParseError()
        { return isParseError; }

        template <class UserType, class ExternalConversions>
        SerializableVariable<UserType, ExternalConversions>& AsSeriVar()
        {
            return static_cast<SerializableVariable<UserType, ExternalConversions>&>(*this);
        }
        template <class SeriStruct>
        SeriStruct& AsSeriStruct()
        {
            return static_cast<SeriStruct&>(*this);
        }

    protected: // Convert methods
        JsonDoc ToJson()
        {
            assert(!isToJsonDocumentRan && "ToJson() conversion ran twice recursively");

            isToJsonDocumentRan = true;

            JsonDoc document;
            StoreNewDocumentAllocator(document.GetAllocator());
            JsonVal value = *this;
            document.SetObject().AddMember(rapidjson::StringRef(name.c_str()), value, *docAllocator);

            isToJsonDocumentRan = false;

            return document;
        }

        virtual operator JsonVal() = 0;

        virtual bool SetFromJson(const JsonVal& externalValue) = 0;

        // Store allocator for all converting-to-json process
        // TODO For multithreading it must be checked for stored once because user can call
        //      ToJson()->Document when another ToJson()->Document is already running
        static inline void StoreNewDocumentAllocator(AllocType& allocator)
        {
            docAllocator = &allocator;
        }

    protected:
        // Each stored object via this wrapper must have a filename for to json conversion
        std::string name = "Need to be replaced";

        static inline AllocType* docAllocator = nullptr;

        static inline bool isToJsonDocumentRan = false;

        // TODO Differentiate parse errors for better diagnostic
        static inline bool isParseError = false;

        SeriObjectType seriObjectType = SeriObjectType::UNDEFINED;
    };

    /// Each struct in which contains SerializableVariable's must be derived from this class
    /// It keep a set of addresses of nested SerializableVariable's
    /// for simplify looping through them and serialize/deserialize them without any user actions
    /// But it won't work if your struct will be like SerializableStruct... :: PlainStruct :: SerializableStruct...
    template <class ExternalConversions>
    class SerializableStruct : public SerializableBase
    {
    public:
        inline SerializableStruct(const char* name): SerializableBase(name)
        {
            seriObjectType = SeriObjectType::STRUCT;
        }

        inline void EnableMemberSerialization(SerializableBase* structMember)
        {
            members.emplace_back(structMember);
        }

        template <class UserType>
        void AssignToMember(size_t index, UserType&& userValue)
        {
            members[index]->AsSeriVar<UserType, ExternalConversions>() = std::move(userValue);
        }

        /// Visit each either SeriVar or UserSeriStruct inside an outer UserSeriStruct.
        /// Just pass a lambda with an appropriate ref-parameter.
        /// Parameter type must be the reference to either UserSeriStruct or UserSeriStruct::SeriVarType_xxx
        template<
            class VisitorFunc,
            class VisitorParamRef = typename Internal::LambdaTraits<VisitorFunc>::template ArgType<0>,
            class VisitorParam = std::remove_cvref_t<VisitorParamRef>
        >
        requires
            std::is_reference_v<VisitorParamRef> &&
            (
                std::is_base_of_v<SerializableStruct, VisitorParam> ||
                std::is_base_of_v<SerializableVariable<typename VisitorParam::ObjectType, ExternalConversions>, VisitorParam>
            )
        void Visit(VisitorFunc visitor) const
        {
            constexpr const bool isVisitStructs = std::derived_from<VisitorParam, SerializableStruct>;

            SeriObjectType selectedObjectType;
            if constexpr (isVisitStructs)
            { selectedObjectType = SeriObjectType::STRUCT; }
            else
            { selectedObjectType = SeriObjectType::VARIABLE; }

            for (SerializableBase* member: members)
            {
                if(member->seriObjectType != selectedObjectType)
                { continue; }

                if constexpr(isVisitStructs)
                { visitor(member->AsSeriStruct<VisitorParam>()); }
                else
                { visitor(member->AsSeriVar<typename VisitorParam::ObjectType, ExternalConversions>()); }
            }
        }

        /// When you want to find certain object in the SeriStruct
        /// isFound is a unary comparator that must accept a reference to finding object
        /// e.g. (const SeriStructType& seriStructVal)
        template<
            class VisitorPredicate,
            class VisitorParamRef = typename Internal::LambdaTraits<VisitorPredicate>::template ArgType<0>,
            class VisitorParam = std::remove_cvref_t<VisitorParamRef>
        >
        VisitorParamRef Find(VisitorPredicate isFound) const
        {
            std::remove_reference_t<VisitorParamRef>* seriObjPtr = nullptr;

            Visit([&seriObjPtr, &isFound] (VisitorParamRef member) {
                if(isFound(member))
                {
                    seriObjPtr = &member;
                    return;
                }
            });

            return *seriObjPtr;
        }

    protected:
        operator JsonVal() override
        {
            JsonVal value(rapidjson::kObjectType);
            for (SerializableBase* serializable: members)
            {
                JsonVal nestedValue  = *serializable;
                value.AddMember(rapidjson::StringRef(serializable->name.c_str()), nestedValue, *docAllocator);
            }
            return value;
        }

        bool SetFromJson(const JsonVal& currentStructJson) override
        {
            bool isSetupSuccess = true;

            for (SerializableBase* member: members)
            {
                if (auto it = currentStructJson.FindMember(member->name.c_str()); it != currentStructJson.MemberEnd())
                {
                    isSetupSuccess &= member->SetFromJson(it->value);
                }
            }

            return isSetupSuccess;
        }

    protected:
        std::vector<SerializableBase*> members;
    };


    /// Each plain data struct must use it for be available for serialization.
    /// Concepts HasFromJsonUserCast<UserSeriType>, HasToJsonUserCast<UserSeriType> must be satisfied
    template <class UserType, class ExternalConversions>
    class SerializableVariable : public SerializableBase
    {
    public:
        using ObjectType = UserType;

    public:
        // SerializableVariable declared in SerializableStruct
        template<class NestedObjectType>
        SerializableVariable(const char* name, NestedObjectType&& nestedObject,
                             SerializableStruct<ExternalConversions>* outerSerializableStruct)
        : SerializableBase(name)
        , nestedObject { nestedObject }
        {
            outerSerializableStruct->EnableMemberSerialization(this);
            seriObjectType = SeriObjectType::VARIABLE;
        }

        // SerializableVariable declared alone
        template<class NestedObjectType>
        SerializableVariable(const char* name, NestedObjectType&& nestedObjectType)
        : SerializableBase(name)
        , nestedObject { nestedObjectType }
        {
            seriObjectType = SeriObjectType::VARIABLE;
        }


        operator JsonVal() override
        { return Internal::Converter<ObjectType, ExternalConversions>::GetToJson()(nestedObject, *docAllocator); }

        operator const ObjectType&() const
        { return nestedObject; }

        const ObjectType& operator*() const
        { return nestedObject; }
        ObjectType& operator*()
        { return nestedObject; }

        const ObjectType* operator->() const
        { return &nestedObject; }
        ObjectType* operator->()
        { return &nestedObject; }

        bool operator==(const SerializableVariable& other) const
        { return this->nestedObject == other.nestedObject; }

        template <class UserInitializer>
        requires std::is_convertible_v<UserInitializer, ObjectType>
        SerializableVariable& operator=(UserInitializer&& userValue)
        {
            // TODO Prevent at runtime assigning to nestedObject other type than UserSeriType
            nestedObject = std::move(userValue);
            return *this;
        }

    protected:
        bool SetFromJson(const JsonVal& externalValue) override
        {
            Internal::Converter<ObjectType, ExternalConversions>::GetFromJson()(nestedObject, externalValue);
            return true;
        }

    private:
        ObjectType nestedObject;
    };
}

#endif //SPACESHIPBP_SERIALIZABLE_IMPL_H
