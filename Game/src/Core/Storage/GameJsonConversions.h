#ifndef SPACESHIPBP_GAMEJSONCONVERSIONS_H
#define SPACESHIPBP_GAMEJSONCONVERSIONS_H

#include <type_traits>
#include <string>
#include <optional>
#include <SFML/Window/VideoMode.hpp>
#include "Utility/Serialization/Serializable.h"
#include "Core/Storage/Config/ConfigTextures.h"

template <class BetterEnumType>
concept BeBetterEnumType = requires (BetterEnumType enumValue) {
    decltype(+enumValue)::_integral;
};

struct GameJsonConversions
{
    SERI_fromJson(sf::VideoMode, videoMode)
    {
        auto wit = json.FindMember("Width");
        auto hit = json.FindMember("Height");
        if(wit != json.MemberEnd() && hit != json.MemberEnd())
        {
            videoMode.width = wit->value.Get<decltype(sf::VideoMode().width)>();
            videoMode.height = hit->value.Get<decltype(sf::VideoMode().height)>();
        }
    }
    SERI_toJson(sf::VideoMode, videoMode)
    {

        rapidjson::Value value(rapidjson::kObjectType);

        value.SERI_ADD("Width", videoMode.width);
        value.SERI_ADD("Height", videoMode.height);

        return value;
    }

    template <class T>
    SERI_fromJson(sf::Vector2<T>, vector2)
    {
        auto x = json.FindMember("x");
        auto y = json.FindMember("y");
        if(x != json.MemberEnd() && y != json.MemberEnd())
        {
            vector2.x = x->value.Get<T>();
            vector2.y = y->value.Get<T>();
        }
    }
    template <class T>
    SERI_toJson(sf::Vector2<T>, vector2)
    {
        rapidjson::Value value(rapidjson::kObjectType);

        value.SERI_ADD("x", vector2.x);
        value.SERI_ADD("y", vector2.y);

        return value;
    }

    template <class SomeEnum>
    requires BeBetterEnumType<SomeEnum>
    SERI_fromJson(SomeEnum, someEnum)
    {
        auto it = json.FindMember("x");
        if(it != json.MemberEnd())
        {
            auto enumOpt = decltype(+someEnum)::_from_string_nothrow(it->value.GetString());
            if(enumOpt)
            {
                someEnum = *enumOpt;
            }
        }
    }

    template <class SomeEnum>
    requires BeBetterEnumType<SomeEnum>
    SERI_toJson(SomeEnum, someEnum)
    {
        rapidjson::Value value(rapidjson::kObjectType);

        value.SERI_ADD_CSTR((+someEnum)._to_string(), (+someEnum)._to_string());

        return value;
    }
};

#endif //SPACESHIPBP_GAMEJSONCONVERSIONS_H
