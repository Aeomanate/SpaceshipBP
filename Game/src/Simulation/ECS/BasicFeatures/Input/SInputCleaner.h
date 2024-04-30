#ifndef SPACESHIPBP_SINPUTCLEANER_H
#define SPACESHIPBP_SINPUTCLEANER_H


#include "Simulation/ECS/System.h"

class SInputCleaner: public ECS::System
{
protected:
    void Update(float dt) override;

public:

};


#endif //SPACESHIPBP_SINPUTCLEANER_H
