#ifndef SPACESHIPBP_STDJSONCONVERTERS_H
#define SPACESHIPBP_STDJSONCONVERTERS_H

#include <rapidjson/document.h>
#include <string>

namespace Serialization::Internal
{
    struct StdConverters
    {
        static inline rapidjson::Value toJson(const std::string& stdValue)
        {
            rapidjson::Value value;
            value.SetString(stdValue.c_str(), stdValue.size());
            return value;
        }

        static inline void fromJson(std::string& stdValue, const rapidjson::Value& value)
        {
            stdValue = value.GetString();
        }
    };
}

#endif //SPACESHIPBP_STDJSONCONVERTERS_H
