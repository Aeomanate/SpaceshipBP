#ifndef SPACESHIPBP_SCOLLISIONDETECTOR_H
#define SPACESHIPBP_SCOLLISIONDETECTOR_H


#include "Simulation/ECS/System.h"

class SCollisionDetector: public ECS::System
{
public:
    void Update(float dt) override;

};


#endif //SPACESHIPBP_SCOLLISIONDETECTOR_H
