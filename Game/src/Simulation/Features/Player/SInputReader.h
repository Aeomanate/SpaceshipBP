#ifndef SPACESHIPBP_SINPUTREADER_H
#define SPACESHIPBP_SINPUTREADER_H

#include "Simulation/ECS/System.h"

class SInputReader: public ECS::System
{
protected:
    void Update(float dt) override;
};

#endif //SPACESHIPBP_SINPUTREADER_H
