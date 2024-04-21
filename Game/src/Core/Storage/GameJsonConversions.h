#ifndef SPACESHIPBP_GAMEJSONCONVERSIONS_H
#define SPACESHIPBP_GAMEJSONCONVERSIONS_H

#include <string>
#include "rapidjson/document.h"
#include "Utility/Serialization/Serializable.h"

#include "SFML/Window/VideoMode.hpp"
#include "Core/Storage/Config/ConfigTextures.h"

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

};

#endif //SPACESHIPBP_GAMEJSONCONVERSIONS_H
