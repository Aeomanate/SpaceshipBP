#ifndef SPACESHIPBP_SYSTEM_H
#define SPACESHIPBP_SYSTEM_H


#include "Utility/Updatable.h"

namespace ECS
{
    class System : public Updatable
    {
    protected:
        enum class Order
        {
            PRE_GAMEPLAY,
            GAMEPLAY,
            POST_GAMEPLAY
        };

    public:
        inline System(Order order = Order::GAMEPLAY)
        : order { order }
        { }

        virtual ~System() = default;

        bool operator< (const System& other) const
        {
            return this->order < other.order;
        }

    private:
        Order order;
    };
}

#endif //SPACESHIPBP_SYSTEM_H
