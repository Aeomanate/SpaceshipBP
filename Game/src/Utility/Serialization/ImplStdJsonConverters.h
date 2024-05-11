#ifndef SPACESHIPBP_IMPLSTDJSONCONVERTERS_H
#define SPACESHIPBP_IMPLSTDJSONCONVERTERS_H

#include <string>
#include "ImplMacroses.h"
#include "Utility/Visual/PositionInRectangle.h"

namespace Serialization::Internal
{
    struct StdConverters
    {
        SERI_fromJson(std::string, stdValue)
        {
            stdValue = json.GetString();
        }
        SERI_toJson(std::string, stdValue)
        {
            rapidjson::Value value(rapidjson::kObjectType);
            value.SetString(stdValue.c_str(), stdValue.size(), allocator);
            return value;
        }


        static inline void fromJson(PositionInRectagle& someEnum, const rapidjson::Value& json)
        {
            auto enumOpt = decltype(+someEnum)::_from_string_nothrow(json.GetString());
            if(enumOpt)
            {
                someEnum = *enumOpt;
            }
        }
        SERI_toJson(PositionInRectagle, someEnum)
        {
            return rapidjson::Value(rapidjson::StringRef((+someEnum)._to_string()));
        }
    };
}

#endif //SPACESHIPBP_IMPLSTDJSONCONVERTERS_H
