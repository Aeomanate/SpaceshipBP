#ifndef SPACESHIPBP_SERIALIZABLE_H
#define SPACESHIPBP_SERIALIZABLE_H

#include <rapidjson/document.h>

class Serializable
{
public:
    virtual void SaveTo(rapidjson::Value& value) = 0;
    virtual void LoadFrom(const rapidjson::Value& value) = 0;
};

#endif //SPACESHIPBP_SERIALIZABLE_H
