#ifndef SPACESHIPBP_SDEBUGINFO_H
#define SPACESHIPBP_SDEBUGINFO_H


#include "Simulation/ECS/System.h"

class SDebugInfo: public ECS::System
{
public:
    void Update(float configTexture) override;

};


#endif //SPACESHIPBP_SDEBUGINFO_H
