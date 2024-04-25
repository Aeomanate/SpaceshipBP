#ifndef SPACESHIPBP_ENTITY_H
#define SPACESHIPBP_ENTITY_H

#include <type_traits>
#include "Component.h"

namespace ECS
{
    class Entity
    {
    public:

        template <class UserComponent>
        requires std::is_base_of_v<Component<typename UserComponent::ValueType>, UserComponent>
        Entity& ClaimComponent()
        {
            using DefinedUserComponent = Component<typename UserComponent::ValueType>;
            DefinedUserComponent::Claim(this);

            return *this;
        }

        template <class UserComponent>
        requires std::is_base_of_v<Component<typename UserComponent::ValueType>, UserComponent>
        Entity& RejectComponent()
        {
            using DefinedUserComponent = Component<typename UserComponent::ValueType>;
            DefinedUserComponent::Reject(this);

            return *this;
        }
    };

}


#endif //SPACESHIPBP_ENTITY_H
