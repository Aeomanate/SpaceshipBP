#ifndef SPACESHIPBP_CQUEUEBASE_H
#define SPACESHIPBP_CQUEUEBASE_H

#include <queue>
#include "Simulation/ECS/Component.h"

template <class T>
struct CQueueBase: public ECS::Component<CQueueBase<T>>
{
public:
    std::queue<T> queue;
};

#endif //SPACESHIPBP_CQUEUEBASE_H
