#ifndef SPACESHIPBP_SVISUALATTENUATIONCONTROLLER_H
#define SPACESHIPBP_SVISUALATTENUATIONCONTROLLER_H


#include "Simulation/ECS/System.h"

class SVisualAttenuationController: public ECS::System
{
public:
    void Update(float dt) override;

};


#endif //SPACESHIPBP_SVISUALATTENUATIONCONTROLLER_H
