#ifndef SPACESHIPBP_CLEVELSTATE_H
#define SPACESHIPBP_CLEVELSTATE_H

#include "Simulation/ECS/Component.h"

enum class LevelState
{
    RAN,
    COMPLETED
};

struct CLevelState: public ECS::Component<CLevelState>
{
    LevelState state;
};

#endif //SPACESHIPBP_CLEVELSTATE_H
