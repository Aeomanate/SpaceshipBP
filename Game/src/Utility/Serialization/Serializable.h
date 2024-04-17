#ifndef SPACESHIPBP_SERIALIZABLE_H
#define SPACESHIPBP_SERIALIZABLE_H

#include <string>
#include <unordered_set>
#include <type_traits>
#include <fstream>
#include <rapidjson/encodedstream.h>
#include <rapidjson/document.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/prettywriter.h>
#include <rapidjson/istreamwrapper.h>
#include "StdJsonConverters.h"

namespace Serialization
{

    namespace Internal
    {
        /// Main concepts that must be observed by UserType to/from json conversion availability
        template<class UserType, class ExternalJsonConverters>
        concept HasFromJsonUserCast =
        requires(UserType& userValue)
        {
            { ExternalJsonConverters::fromJson(userValue, rapidjson::Value()) } -> std::convertible_to<void>;
        };
        template<class UserType, class ExternalJsonConverters>
        concept HasToJsonUserCast =
        requires(UserType& userValue)
        {
            { ExternalJsonConverters::toJson(userValue) } -> std::convertible_to<rapidjson::Value>;
        };

        // Base template for literal types
        template<class MustBeRapidJsonBuiltInType>
        void fromJsonInternal(MustBeRapidJsonBuiltInType& userValue, const rapidjson::Value& initializer)
        { userValue = initializer.template Get<MustBeRapidJsonBuiltInType>(); }

        template<class MustBeRapidJsonBuiltInType>
        rapidjson::Value toJsonInternal(const MustBeRapidJsonBuiltInType& userValue)
        { return rapidjson::Value(userValue); }

        // Compile-time helper for choosing right converter function based on passed type (custom or literal)
        template<class UserType, class ExternalJsonConverters>
        class Converter
        {
            using FromJsonFuncPtrType = void (*)(UserType&, const rapidjson::Value&);
            using ToJsonFuncPtrType = rapidjson::Value(*)(const UserType&);

            static constexpr auto GetFromJsonConverter() -> FromJsonFuncPtrType
            {
                if constexpr (HasFromJsonUserCast<UserType, ExternalJsonConverters>)
                { return &ExternalJsonConverters::fromJson; }
                else if constexpr (HasFromJsonUserCast<UserType, StdConverters>)
                { return &StdConverters::fromJson; }
                else
                {
                    static_assert(std::is_arithmetic_v<UserType> || std::is_same_v<UserType, bool>,
                        "Custom user type must define a fromJson converter");
                    return &fromJsonInternal<UserType>;
                };
            }

            static constexpr auto GetToJsonConverter() -> ToJsonFuncPtrType
            {
                if constexpr (HasToJsonUserCast<UserType, ExternalJsonConverters>)
                { return &ExternalJsonConverters::toJson; }
                else if constexpr (HasToJsonUserCast<UserType, StdConverters>)
                { return &StdConverters::toJson; }
                else
                {
                    static_assert(std::is_arithmetic_v<UserType> || std::is_same_v<UserType, bool>,
                        "Custom user type must define a toJson converter");
                    return &toJsonInternal<UserType>;
                };
            }

        public:
            inline static constexpr const FromJsonFuncPtrType fromJson = GetFromJsonConverter();
            inline static constexpr const ToJsonFuncPtrType toJson = GetToJsonConverter();
        };
    };

    /// A base class for any serializable variable for both user-defined and literal type
    class SerializableBase
    {
        template <class Type, class UserDefinedJsonConversionSet>
        friend class SerializableVariable;
        friend class SerializableStruct;

    public: // Main methods
        SerializableBase() = default;

        SerializableBase(const char* name)
            : name { name }
        { }

        inline operator std::string()
        {
            rapidjson::StringBuffer buffer;
            rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(buffer);
            writer.SetIndent(' ', 2);
            writer.SetFormatOptions(rapidjson::kFormatSingleLineArray);

            ToJson().Accept(writer);

            return buffer.GetString();
        }

        template <class OStream>
        friend OStream& operator<< (OStream&& out, SerializableBase& serializable)
        {
            return out << static_cast<std::string>(serializable);
        }

        template <class IStream>
        friend IStream& operator>> (IStream&& in, SerializableBase& serializable)
        {
            rapidjson::IStreamWrapper inStreamWrapper = in;
            rapidjson::AutoUTFInputStream<unsigned, rapidjson::IStreamWrapper> encodedStream = inStreamWrapper;

            rapidjson::Document document;
            document.ParseStream(encodedStream);
            StoreNewDocumentAllocator(document.GetAllocator());

            serializable.isParseError = document.HasParseError();
            if(serializable.isParseError)
            {
                in.setstate(std::ios_base::failbit);
                return in;
            }

            serializable.SetFromJson(document.GetObject());

            return in;
        }

        bool HasParseError() const { return isParseError; }

    protected:
        /// Don't call it for SerializableVariable while we in the ToJson() SerializableStruct call-stack
        rapidjson::Document ToJson()
        {
            if(isToJsonDocumentRan)
            {
                #ifndef NDEBUG
                static_cast<void(*)()>(nullptr)();
                #endif
            }

            isToJsonDocumentRan = true;

            rapidjson::Document document;
            StoreNewDocumentAllocator(document.GetAllocator());

            rapidjson::Value value = *this;
            document.SetObject().AddMember(rapidjson::StringRef(name), value, *documentAllocator);

            isToJsonDocumentRan = false;

            return document;
        }

        virtual operator rapidjson::Value() = 0;

        virtual void SetFromJson(const rapidjson::Value& externalValue) = 0;

    protected:
        // Each stored object via this wrapper must have a name for to json conversion
        const char* name = nullptr;

        // Store allocator for all converting-to-json process
        // TODO For multithreading it must be checked for stored once because user can call
        //      ToJson()->Document when another ToJson()->Document is already running
        inline static void StoreNewDocumentAllocator(rapidjson::MemoryPoolAllocator<>& allocator)
        { documentAllocator = &allocator; }
        inline static rapidjson::MemoryPoolAllocator<>* documentAllocator = nullptr;

        inline static bool isToJsonDocumentRan = false;
        bool isParseError = false;
    };

    /// Each plain data struct must use it for be available for serialization
    /// Concepts HasFromJsonUserCast<Type>, HasToJsonUserCast<Type> must be satisfied
    template <class Type, class UserDefinedJsonConversionSet>
    class SerializableVariable : public SerializableBase
    {
    public:
        template<class... Params>
        SerializableVariable(const char* name, Params&& ... params)
        : SerializableBase(name)
        , object { std::forward<Params>(params)... }
        { }

        operator const Type&() const
        { return object; }

        operator rapidjson::Value() override
        { return Internal::Converter<Type, UserDefinedJsonConversionSet>::toJson(object); }

    protected:
        void SetFromJson(const rapidjson::Value& externalValue) override
        {
            if(auto it = externalValue.FindMember(name); it != externalValue.MemberEnd())
            { Internal::Converter<Type, UserDefinedJsonConversionSet>::fromJson(object, it->value); }
        }

    private:
        Type object;
    };

    /// Each struct in which contains SerializableVariable's must be derived from this class
    /// It keep a set of addresses of nested SerializableVariable's
    /// for simplify looping through them and serialize/deserialize them without any user actions
    /// But it won't work if your struct will be like SerializableStruct... :: PlainStruct :: SerializableStruct...
    class SerializableStruct : public SerializableBase
    {
    public:
        void SetFromJson(const rapidjson::Value& valueExternal) override
        {
            for (SerializableBase* member: membersSet)
            {
                if (auto it = valueExternal.FindMember(member->name); it != valueExternal.MemberEnd())
                { member->SetFromJson(it->value); }
            }
        }

    protected:
        inline void EnableMemberSerialization(SerializableBase& structMember)
        {
            membersSet.insert(&structMember);
        }

        operator rapidjson::Value() override
        {
            rapidjson::Value value;
            for (SerializableBase* serializable: membersSet)
            {
                rapidjson::Value nestedValue  = *serializable;
                value.AddMember(rapidjson::StringRef(name), nestedValue, *documentAllocator);
            }
            return value;
        }

    protected:
        std::unordered_set<SerializableBase*> membersSet;
    };
}

#endif //SPACESHIPBP_SERIALIZABLE_H
