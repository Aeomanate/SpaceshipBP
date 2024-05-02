#ifndef SPACESHIPBP_CQUEUEBASE_H
#define SPACESHIPBP_CQUEUEBASE_H

#include <queue>
#include "Simulation/ECS/Component.h"

template <class T>
struct CQueueBase: public ECS::SimpleComponent<std::queue<T>>
{

};

#endif //SPACESHIPBP_CQUEUEBASE_H
