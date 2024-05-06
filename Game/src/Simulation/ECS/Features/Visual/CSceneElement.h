#ifndef SPACESHIPBP_CSCENEELEMENT_H
#define SPACESHIPBP_CSCENEELEMENT_H


#include "SFML/Graphics.hpp"
#include "Simulation/ECS/Component.h"
#include "Utility/Visual/FrameByFrame.h"

struct CSceneElement: public ECS::Component<CSceneElement>
{
    FrameByFrame sprite;

    enum ZOrder
    {
        UNDEFINED,
        BACKGROUND,
        CRASHED_ASTEROIDS,
        PLAYER,
        ASTEROIDS
    } order = UNDEFINED;

    bool operator< (const CSceneElement& other) const
    {
        return order < other.order;
    }
};


#endif //SPACESHIPBP_CSCENEELEMENT_H
