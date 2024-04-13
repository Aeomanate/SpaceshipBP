#ifndef SPACESHIPBP_CONFIGSIMULATION_H
#define SPACESHIPBP_CONFIGSIMULATION_H

#include "Serializable.h"

struct ConfigSimulation: public Serializable
{
    void SaveTo(rapidjson::Value& value) override;
    void LoadFrom(const rapidjson::Value& value) override;


};
#endif //SPACESHIPBP_CONFIGSIMULATION_H
