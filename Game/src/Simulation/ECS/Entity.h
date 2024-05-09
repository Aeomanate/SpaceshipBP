#ifndef SPACESHIPBP_ENTITY_H
#define SPACESHIPBP_ENTITY_H

#include <type_traits>
#include <utility>
#include "Component.h"

namespace ECS
{
    template <class UserComponent, class UserDataT>
    using ResolveComponentBaseImpl = Component<UserComponent, UserDataT>;
    template <class UserComponent>
    using ResolveBase = ResolveComponentBaseImpl<typename UserComponent::UserComponentT, typename UserComponent::UserDataT>;

    class Entity
    {
    public:
        explicit Entity(std::string name)
        : name { std::move(name) }
        { }

    public:
        template <ECSComponent UserComponent, class... Params>
        UserComponent& Claim(Params&&... initFieldsPack)
        {
            using BaseOfUserComponent = ResolveBase<UserComponent>;
            return static_cast<UserComponent&>(BaseOfUserComponent::Claim(this, std::forward<Params>(initFieldsPack)...));
        }

        template <ECSComponent UserComponent>
        Entity& Reject()
        {
            using BaseOfUserComponent = ResolveBase<UserComponent>;
            BaseOfUserComponent::Reject(this);
            return *this;
        }

        template <ECSComponent UserComponent>
        UserComponent* TryGetDataAs()
        { return ResolveBase<UserComponent>::template TryGetDataPtrFor<UserComponent>(this); }

        template <ECSComponent UserComponent>
        UserComponent& Get()
        { return ResolveBase<UserComponent>::Data(this); }

        template <ECSComponent UserComponent>
        bool Has()
        { return TryGetDataAs<UserComponent>(); }

    public:
        std::string name;
    };

}


#endif //SPACESHIPBP_ENTITY_H
