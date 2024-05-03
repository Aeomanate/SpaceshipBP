#ifndef SPACESHIPBP_IMPLSTDJSONCONVERTERS_H
#define SPACESHIPBP_IMPLSTDJSONCONVERTERS_H

#include <string>
#include <enum.h>
#include "ImplMacroses.h"

namespace Serialization::Internal
{
    template <class UserType>
    concept BetterEnumType = requires (UserType enumValue) {
        decltype(+enumValue)::_integral;
    };

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

        template <BetterEnumType SomeEnum>
        SERI_fromJson(SomeEnum, someEnum)
        {
            auto enumOpt = decltype(+someEnum)::_from_string_nothrow(json.GetString());
            if(enumOpt)
            {
                someEnum = *enumOpt;
            }
        }
        template <BetterEnumType SomeEnum>
        SERI_toJson(SomeEnum, someEnum)
        {
            return rapidjson::Value(rapidjson::StringRef((+someEnum)._to_string()));
        }
    };
}

#endif //SPACESHIPBP_IMPLSTDJSONCONVERTERS_H
