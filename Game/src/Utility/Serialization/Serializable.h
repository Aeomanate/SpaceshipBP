#ifndef SPACESHIPBP_SERIALIZABLE_H
#define SPACESHIPBP_SERIALIZABLE_H

#include <string>
#include <unordered_set>
#include <type_traits>
#include <rapidjson/document.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/prettywriter.h>
#include "Utility/Serialization/SerializableExternalTypes.h"

namespace UserJsonConversions {
    inline void fromJson(sf::VideoMode& videoMode, const rapidjson::Value& value)
    {
        auto wit = value.FindMember("Width");
        auto hit = value.FindMember("Height");
        if(wit != value.MemberEnd() && hit != value.MemberEnd())
        {
            videoMode.width = wit->value.Get<decltype(sf::VideoMode().width)>();
            videoMode.width = hit->value.Get<decltype(sf::VideoMode().height)>();
        }
    }

    inline rapidjson::Value toJson(const sf::VideoMode& videoMode)
    {
        rapidjson::Value value(rapidjson::kObjectType);

        value["Width"] = videoMode.width;
        value["Height"] = videoMode.height;

        return value;
    }
}

namespace Converters
{
    namespace Concepts
    {
        template <typename LibType>
        class CheckGetExistsIn {
            typedef char yes[1];
            typedef char no[2];

            template <typename UserType>
            static yes& test(decltype(&LibType::template Get<UserType>));

            template <typename>
            static no& test(...);

        public:
            template <class UserType>
            static const bool forUserType = sizeof(test<UserType>(0)) == sizeof(yes);
        };

        template <class UserType>
        concept HasFromJsonCast = CheckGetExistsIn<rapidjson::Value>::forUserType<UserType>;

        template <class UserType>
        concept HasToJsonCast = requires {
            rapidjson::Value { UserType { } };
        };
    }


    template<class UserType>
    void fromJson(UserType& userValue, const rapidjson::Value& initializer)
    { userValue = initializer.template Get<UserType>(); }

    template<class UserType>
    auto toJson(const UserType& userValue)
    { return rapidjson::Value(userValue); }


    template <class UserType>
    using FromJsonFuncPtrType = void(*)(UserType&, const rapidjson::Value&);
    template <class UserType>
    using ToJsonFuncPtrType = rapidjson::Value(*)(const UserType&);


    template <class UserType, class = void>
    struct Distinct {
        static constexpr ToJsonFuncPtrType<UserType> toJson = &UserJsonConversions::toJson;
        static constexpr FromJsonFuncPtrType<UserType> fromJson = &UserJsonConversions::fromJson;
    };
    template <class UserType>
    struct Distinct<UserType,
        std::void_t<
            std::enable_if<Concepts::HasToJsonCast<UserType> && Concepts::HasFromJsonCast<UserType>, void>
        >> {
        static constexpr ToJsonFuncPtrType<UserType> toJson = &toJson;
        static constexpr FromJsonFuncPtrType<UserType> fromJson = &fromJson;
    };
};

template <class UserType>
inline auto attempt()
{
    rapidjson::Value json;
    UserType val;

    // All fine with this when do in directly without compile-time selecting
    // Converters::fromJson(val, json);
    // Converters::toJson(val);
    // UserJsonConversions::fromJson(val, json);
    // UserJsonConversions::toJson(val);

    // Compiles for sf::Uint32, but CLion says that it's error
    // But for sf::VideoMode got error
    Converters::Distinct<UserType>::fromJson(val, json);
    Converters::Distinct<UserType>::toJson(val);



    // Decide on compile-time what is need to be called works for literal types
    //if constexpr (Converters::HasFromJsonCast<UserType>)
    //{
    //    Converters::fromJson(val, json); // Error for sf::VideoMode
    //    /*
    //     error: 'Get' is not a member of 'rapidjson::internal::TypeHelper<rapidjson::GenericValue<rapidjson::UTF8<> >, sf::VideoMode>'
    //      1747 |     T Get() const { return internal::TypeHelper<ValueType, T>::Get(*this); }
    //           |                            ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~
    //     */
    //} else
    //{
    //    UserJsonConversions::fromJson(val, json);
    //}

    //if constexpr (Converters::HasToJsonCast<UserType>)
    //{
    //    return Converters::toJson(val);
    //} else
    //{
    //    return UserJsonConversions::toJson(val);
    //}
}

inline void f()
{
    //attempt<sf::Uint32>();
    //attempt<sf::VideoMode>();
}


class Serializable
{
public:
    Serializable() = default;

    Serializable(const char* name)
        : name { name }
    { }

    rapidjson::Document ToJson()
    {
        rapidjson::Document document;
        StoreNewDocumentAllocator(document.GetAllocator());
        document.SetObject().AddMember(rapidjson::StringRef(GetName()), static_cast<rapidjson::Value&&>(*this), *documentAllocator);

        return document;
    }

    virtual operator rapidjson::Value() = 0;

    inline operator std::string()
    {
        rapidjson::StringBuffer buffer;
        rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(buffer);
        writer.SetIndent(' ', 2);
        writer.SetFormatOptions(rapidjson::kFormatSingleLineArray);

        ToJson().Accept(writer);

        return buffer.GetString();
    }

    friend std::ostream& operator <<(std::ostream& out, Serializable& serializable)
    {
        return out << static_cast<std::string>(serializable);
    }

public:
    [[nodiscard]] inline const char* GetName() const
    { return name; };

    virtual void SetFromJson(const rapidjson::Value& valueExternal) = 0;

protected:
    inline static void StoreNewDocumentAllocator(rapidjson::MemoryPoolAllocator<>& allocator)
    { documentAllocator = &allocator; }


protected:
    const char* name = nullptr;

    // Pointer to allocator from rapidjson::Document instance
    inline static rapidjson::MemoryPoolAllocator<>* documentAllocator = nullptr;
};

template<class Type>
class SerializableVariable : public Serializable
{
public:
    template<class... Params>
    SerializableVariable(const char* name, Params&& ... params)
        : Serializable(name)
        , object { std::forward<Params>(params)... }
    { }

    void SetFromJson(const rapidjson::Value& externalValue) override
    {
        if(auto it = externalValue.FindMember(GetName()); it != externalValue.MemberEnd())
        {
            // Converters::Distinct<Type>::fromJson(object, it->value);
        }
    }

    operator const Type&() const
    {
        return object;
    }

    operator rapidjson::Value() override
    {
        return { };
        // return Converters::Distinct<Type>::toJson(object);
    }

private:
    Type object;
};


class SerializableStruct : public Serializable
{
public:
    void SetFromJson(const rapidjson::Value& valueExternal) override
    {
        for (Serializable* serializable: membersSet)
        {
            auto it = valueExternal.FindMember(serializable->Serializable::GetName());
            if (it != valueExternal.MemberEnd())
            {
                serializable->SetFromJson(it->value);
            }
        }
    }

    inline void EnableMemberSerialization(Serializable& structMember)
    {
        membersSet.insert(&structMember);
    }

    operator rapidjson::Value() override
    {
        rapidjson::Value value;
        for (Serializable* serializable: membersSet)
        {
            value.AddMember(rapidjson::StringRef(GetName()), rapidjson::Value(*serializable), *documentAllocator);
        }
        return value;
    }

protected:
    std::unordered_set<Serializable*> membersSet;
};

#endif //SPACESHIPBP_SERIALIZABLE_H
