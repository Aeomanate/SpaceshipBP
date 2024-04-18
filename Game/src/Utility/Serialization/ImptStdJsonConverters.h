#ifndef SPACESHIPBP_IMPTSTDJSONCONVERTERS_H
#define SPACESHIPBP_IMPTSTDJSONCONVERTERS_H

#include <string>
#include "ImplMacroses.h"

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
    };
}

#endif //SPACESHIPBP_IMPTSTDJSONCONVERTERS_H
