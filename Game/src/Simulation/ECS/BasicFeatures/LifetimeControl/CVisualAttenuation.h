#ifndef SPACESHIPBP_CVISUALATTENUATION_H
#define SPACESHIPBP_CVISUALATTENUATION_H

#include "Simulation/ECS/Component.h"

struct CVisualAttenuation: ECS::Component<CVisualAttenuation>
{
    float alphaValue = 1;
};

#endif //SPACESHIPBP_CVISUALATTENUATION_H
