#ifndef SPACESHIPBP_GAMEJSONCONVERSIONS_H
#define SPACESHIPBP_GAMEJSONCONVERSIONS_H

#include <string>
#include "rapidjson/document.h"
#include "Utility/Serialization/Serializable.h"

#include "SFML/Window/VideoMode.hpp"

struct GameJsonConversions
{
    SERI_fromJson(sf::VideoMode, videoMode)
    {
        auto wit = json.FindMember("Width");
        auto hit = json.FindMember("Height");
        if(wit != json.MemberEnd() && hit != json.MemberEnd())
        {
            videoMode.width = wit->value.Get<decltype(sf::VideoMode().width)>();
            videoMode.width = hit->value.Get<decltype(sf::VideoMode().height)>();
        }
    }

    SERI_toJson(sf::VideoMode, videoMode)
    {

        rapidjson::Value value(rapidjson::kObjectType);

        value.SERI_ADD("Width", videoMode.width);
        value.SERI_ADD("Height", videoMode.height);

        return value;
    }
};

#endif //SPACESHIPBP_GAMEJSONCONVERSIONS_H
