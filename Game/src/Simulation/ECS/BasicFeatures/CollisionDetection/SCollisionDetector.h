#ifndef SPACESHIPBP_SCOLLISIONDETECTOR_H
#define SPACESHIPBP_SCOLLISIONDETECTOR_H


#include "Simulation/ECS/System.h"

class SCollisionDetector: public ECS::System
{
protected:
    void Update(float dt) override;

public:


};


#endif //SPACESHIPBP_SCOLLISIONDETECTOR_H
