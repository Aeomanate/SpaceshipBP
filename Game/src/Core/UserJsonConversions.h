#ifndef SPACESHIPBP_USERJSONCONVERSIONS_H
#define SPACESHIPBP_USERJSONCONVERSIONS_H

#include <string>
#include "rapidjson/document.h"
#include "Utility/Serialization/Serializable.h"

#include "SFML/Window/VideoMode.hpp"

struct UserJsonConversions {
    static inline void fromJson(sf::VideoMode& videoMode, const rapidjson::Value& value)
    {
        auto wit = value.FindMember("Width");
        auto hit = value.FindMember("Height");
        if(wit != value.MemberEnd() && hit != value.MemberEnd())
        {
            videoMode.width = wit->value.Get<decltype(sf::VideoMode().width)>();
            videoMode.width = hit->value.Get<decltype(sf::VideoMode().height)>();
        }
    }

    static inline rapidjson::Value toJson(const sf::VideoMode& videoMode)
    {
        rapidjson::Value value(rapidjson::kObjectType);

        value["Width"] = videoMode.width;
        value["Height"] = videoMode.height;

        return value;
    }
};

#endif //SPACESHIPBP_USERJSONCONVERSIONS_H
