#ifndef SPACESHIPBP_SVISUALATTENUATION_H
#define SPACESHIPBP_SVISUALATTENUATION_H


#include "Simulation/ECS/System.h"

class SVisualAttenuation: public ECS::System
{
public:
    void Update(float dt) override;

};


#endif //SPACESHIPBP_SVISUALATTENUATION_H
