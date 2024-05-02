#ifndef SPACESHIPBP_ENTITY_H
#define SPACESHIPBP_ENTITY_H

#include <type_traits>
#include "Component.h"

namespace ECS
{
    template <class UserComponent>
    using ResolveComponentBase = Component<typename UserComponent::ValueType>;

    class Entity
    {

    public:
        template <class UserComponent, class... Params>
        requires BeComponent<UserComponent>
        UserComponent& Claim(Params&&... initFieldsPack)
        {
            using BaseOfUserComponent = ResolveComponentBase<UserComponent>;
            return static_cast<UserComponent&>(BaseOfUserComponent::Claim(this, std::forward<Params>(initFieldsPack)...));
        }

        template <class UserComponent>
        requires BeComponent<UserComponent>
        Entity& Reject()
        {
            using BaseOfUserComponent = ResolveComponentBase<UserComponent>;
            BaseOfUserComponent::Reject(this);
            return *this;
        }

        template <class UserComponent>
        requires BeComponent<UserComponent>
        std::optional<UserComponent> TryGetDataAs()
        {
            return ResolveComponentBase<UserComponent>::template TryGetDataAs<UserComponent>(this);
        }

        template <class UserComponent>
        requires BeComponent<UserComponent>
        UserComponent& Get()
        {
            return ResolveComponentBase<UserComponent>::Data(this);
        }
    };

}


#endif //SPACESHIPBP_ENTITY_H
