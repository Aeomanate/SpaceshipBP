#ifndef SPACESHIPBP_SVISUALATTENUATION_H
#define SPACESHIPBP_SVISUALATTENUATION_H


#include "Simulation/ECS/System.h"

class SVisualAttenuation: public ECS::System
{
protected:
    void Update(float dt) override;

public:


};


#endif //SPACESHIPBP_SVISUALATTENUATION_H
