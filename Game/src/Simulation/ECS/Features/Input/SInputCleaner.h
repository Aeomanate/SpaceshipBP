#ifndef SPACESHIPBP_SINPUTCLEANER_H
#define SPACESHIPBP_SINPUTCLEANER_H


#include "Simulation/ECS/System.h"

class SInputCleaner: public ECS::System
{
protected:
    void Update(float queueComponent) override;

public:
    SInputCleaner()
    : ECS::System(ECS::System::Order::POST_GAMEPLAY)
    { }
};


#endif //SPACESHIPBP_SINPUTCLEANER_H
