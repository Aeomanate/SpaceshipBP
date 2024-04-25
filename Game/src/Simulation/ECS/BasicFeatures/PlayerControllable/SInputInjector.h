#ifndef SPACESHIPBP_SINPUTINJECTOR_H
#define SPACESHIPBP_SINPUTINJECTOR_H


#include "Simulation/ECS/System.h"

class SInputInjector: public ECS::System
{
public:
    void Update(float dt) override;


};


#endif //SPACESHIPBP_SINPUTINJECTOR_H
