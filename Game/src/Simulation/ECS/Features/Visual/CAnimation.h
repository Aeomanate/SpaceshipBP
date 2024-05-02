#ifndef SPACESHIPBP_CANIMATION_H
#define SPACESHIPBP_CANIMATION_H


#include "SFML/Graphics.hpp"
#include "Simulation/ECS/Component.h"
#include "Utility/Visual/FrameByFrame.h"

struct CAnimation: public ECS::SimpleComponent<FrameByFrame>
{

};


#endif //SPACESHIPBP_CANIMATION_H
