#ifndef SPACESHIPBP_COMPONENT_H
#define SPACESHIPBP_COMPONENT_H

#include <unordered_map>
#include <ranges>
#include <algorithm>
#include <optional>


namespace ECS
{
    class Entity;
    namespace r = std::ranges;
    namespace rv = r::views;

    template<class UserComponent>
    class Component
    {
    public:
        using KeyType = Entity*;
        using ValueType = UserComponent;
        using EntityWithDataStorage = std::unordered_map<KeyType, ValueType>;
        using Iterator = EntityWithDataStorage::iterator;
        using ConstIterator = EntityWithDataStorage::const_iterator;

    public:
        static inline std::optional<ValueType> TryGetFirst()
        {
            Iterator it = entitiesWithData.begin();
            if(it != entitiesWithData.end()) {
                return { it->second };
            }
            else
            {
                return std::nullopt;
            }
        }

        static inline auto AllEntities()
        {
            return rv::all(entitiesWithData);
        }

        static inline auto Filter()
        {
            return rv::filter([] (auto node) {
                return entitiesWithData.contains(node.first);
            });
        }

        static inline ValueType& Data(KeyType key)
        {
            return entitiesWithData.find(key)->second;
        }

        template <class... Params>
        static inline UserComponent& Claim(Entity* entity, Params&&... initFieldsPack)
        {
            UserComponent* userComponent;
            if constexpr (sizeof...(initFieldsPack) > 0)
            {
                userComponent = &entitiesWithData.emplace(entity, ValueType{std::forward<Params>(initFieldsPack)...}).first->second;
            }
            else
            {
                userComponent = &entitiesWithData.emplace(entity, ValueType{}).first->second;
            }

            return *userComponent;
        }

        static inline void Reject(Entity* entity)
        {
            entitiesWithData.erase(entity);
        }

        template <class Derived = UserComponent>
        static inline std::optional<Derived> TryGetDataAs(Entity* entity)
        {
            if(auto it = entitiesWithData.find(entity); it != entitiesWithData.end())
            {
                return { static_cast<Derived&>(it->second) };
            }
            else
            {
                return std::nullopt;
            }
        }

        template <class FieldT, class ConvertibleToFieldT>
        requires std::convertible_to<ConvertibleToFieldT, FieldT>
        UserComponent& SetMember(FieldT UserComponent::*fieldPtr, ConvertibleToFieldT&& value)
        {
            UserComponent* userComponentPtr = static_cast<UserComponent*>(this);
            userComponentPtr->*fieldPtr = std::forward<ConvertibleToFieldT>(value);
            return *userComponentPtr;
        }

    private:
        static inline EntityWithDataStorage entitiesWithData;
    };

    template <class UserComponent>
    concept BeComponent = requires {
        std::is_base_of_v<Component<typename UserComponent::ValueType>, UserComponent>;
    };

    template <class T>
    struct SimpleComponent: public Component<SimpleComponent<T>>
    {
        template <class... Params>
        SimpleComponent(Params&&... valueInitPack)
        : value { std::forward<Params>(valueInitPack)... }
        { }

        template <class Derived>
        requires std::is_base_of_v<Component<T>, Derived>
        operator Derived&()
        {
            return static_cast<Derived&>(*this);
        }

        operator T&()
        { return value; }

        T* operator ->()
        { return &value; }

        T& operator *()
        { return value; }


        T value = { };
    };

}


#endif //SPACESHIPBP_COMPONENT_H
