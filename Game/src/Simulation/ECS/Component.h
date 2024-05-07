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
        friend class Entity;

    public:
        using KeyType = Entity*;
        using KeyTypeConst = const Entity*;
        using ValueType = UserComponent;
        using EntityWithDataStorage = std::unordered_map<KeyType, ValueType>;
        using Iterator = EntityWithDataStorage::iterator;
        using ConstIterator = EntityWithDataStorage::const_iterator;
        struct KeyValuePtrs { KeyType entity; UserComponent* component; };
        struct KeyValueConstPtrs { KeyTypeConst entity; const UserComponent* component; };

    public:
        static inline auto All()
        { return rv::all(entitiesWithData); }

        template <class Comparator = std::less<KeyValuePtrs>>
        static inline auto AllSorted(Comparator comparator = { })
        {
            // TODO Need to upgrade for concurrency execution
            static std::vector<KeyValuePtrs> all;
            all.clear();
            all.reserve(entitiesWithData.size());

            std::ranges::transform(entitiesWithData, std::back_inserter(all), [] (auto& it) {
                return KeyValuePtrs{ it.first, static_cast<UserComponent*>(&it.second) };
            });

            std::ranges::sort(all, comparator);
            return rv::all(all);
        }

        friend bool operator< (const KeyValuePtrs& entry1, const KeyValuePtrs& entry2) {
            return *entry1.component < *entry2.component;
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

        template <class FieldT, std::convertible_to<FieldT> Convertible>
        UserComponent& SetMember(FieldT UserComponent::*fieldPtr, Convertible&& value)
        {
            UserComponent& userComponentPtr = static_cast<UserComponent&>(*this);
            userComponentPtr.*fieldPtr = std::forward<Convertible>(value);
            return userComponentPtr;
        }

    protected:
        template <class Derived = UserComponent>
        static inline std::optional<Derived*> TryGetDataAs(Entity* entity)
        {
            if(auto it = entitiesWithData.find(entity); it != entitiesWithData.end())
            {
                return { static_cast<Derived*>(&it->second) };
            }
            else
            {
                return std::nullopt;
            }
        }

    private:
        static inline EntityWithDataStorage entitiesWithData;
    };

    template <class UserComponent>
    concept ECSComponent = requires {
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
