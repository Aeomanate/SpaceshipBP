#ifndef SPACESHIPBP_SYSTEM_H
#define SPACESHIPBP_SYSTEM_H


#include "Utility/Updatable.h"

namespace ECS
{
    class System : public Updatable
    {
    public:
        virtual ~System() = default;

    };
}

#endif //SPACESHIPBP_SYSTEM_H
