#ifndef SPACESHIPBP_COMPONENT_H
#define SPACESHIPBP_COMPONENT_H

#include <unordered_map>
#include <ranges>
#include <algorithm>
#include <optional>
#include <cassert>

namespace ECS
{
    class Entity;
    namespace r = std::ranges;
    namespace rv = r::views;

    template <class DataT>
    struct ComponentUniqueData
    {
        ComponentUniqueData() = default;
        ComponentUniqueData(ComponentUniqueData&&) = default;
        ComponentUniqueData(const ComponentUniqueData&) = default;

        template <class T> requires
        requires { !std::same_as<DataT, T>; }
        ComponentUniqueData(T&& t)
        : value { std::forward<T>(t) }
        { }

        template <class T> requires
        requires { !std::same_as<DataT, T>; }
        ComponentUniqueData(const T& t)
        : value { t }
        { }

        operator auto& () { return value; }
        operator const auto& () const { return value; }

        auto* operator->() { return &value; }
        const auto* operator->() const { return &value; }

        auto& operator*() { return value; }
        const auto& operator*() const { return value; }

        using UserDataT = DataT;
        UserDataT value { };
    };

    struct ComponentUndefinedData
    {
        using UserDataT = void;
    };

    template<class UserComponent, class DataT = void>
    class Component: public std::conditional_t
        <
            std::is_same_v<DataT, void>,
            ComponentUndefinedData,
            ComponentUniqueData<DataT>
        >
    {
        friend class Entity;

    public:
        using KeyType = Entity*;
        using KeyTypeConst = const Entity*;
        using UserComponentT = UserComponent;
        using EntityWithDataStorage = std::unordered_map<KeyType, UserComponentT>;
        using Iterator = EntityWithDataStorage::iterator;
        using ConstIterator = EntityWithDataStorage::const_iterator;
        struct KeyValuePointers { KeyType entity; UserComponent* component; };
        struct KeyValueConstPointers { KeyTypeConst entity; const UserComponent* component; };

    public:
        static inline auto All()
        { return rv::all(entitiesWithData); }

        template <class Comparator = std::less<KeyValuePointers>>
        static inline auto AllSorted(Comparator comparator = { })
        {
            static std::vector<KeyValuePointers> all; // TODO Need to upgrade for concurrency execution
            all.clear();
            all.reserve(entitiesWithData.size());

            std::ranges::transform(entitiesWithData, std::back_inserter(all), [] (auto& it) {
                return KeyValuePointers{ it.first, static_cast<UserComponent*>(&it.second) };
            });

            std::ranges::sort(all, comparator);
            return rv::all(all);
        }

        static inline bool Empty()
        { return entitiesWithData.empty(); }

        friend bool operator< (const KeyValuePointers& entry1, const KeyValuePointers& entry2) {
            return *entry1.component < *entry2.component;
        }

        static inline auto Filter()
        {
            return rv::filter([] (auto node) {
                return entitiesWithData.contains(node.first);
            });
        }

        static inline UserComponentT& Data(KeyType key)
        { return entitiesWithData.find(key)->second; }

        static inline UserComponentT* TryGetFirstDataPtr()
        {
            Iterator it = entitiesWithData.begin();
            if(it != entitiesWithData.end())
            { return &it->second; }
            else
            { return nullptr; }
        }

        template <class... Params>
        static inline UserComponent& Claim(Entity* entity, Params&&... initFieldsPack)
        {
            UserComponent* userComponent;
            if constexpr (sizeof...(initFieldsPack) > 0)
            { userComponent = &entitiesWithData.emplace(entity, UserComponentT{ std::forward<Params>(initFieldsPack)...}).first->second; }
            else
            { userComponent = &entitiesWithData.emplace(entity, UserComponentT{}).first->second; }

            return *userComponent;
        }

        static inline void Reject(Entity* entity)
        { entitiesWithData.erase(entity); }

        template <class FieldT, std::convertible_to<FieldT> Convertible>
        UserComponent& SetMember(FieldT UserComponent::*fieldPtr, Convertible&& value)
        {
            UserComponent& userComponentPtr = static_cast<UserComponent&>(*this);
            userComponentPtr.*fieldPtr = std::forward<Convertible>(value);
            return userComponentPtr;
        }

    protected:
        template <class Derived = UserComponent>
        static inline Derived* TryGetDataPtrFor(Entity* entity)
        {
            if(auto it = entitiesWithData.find(entity); it != entitiesWithData.end())
            { return static_cast<Derived*>(&it->second); }
            else
            { return nullptr; }
        }

    private:
        static inline EntityWithDataStorage entitiesWithData;
    };

    template <class UserComponent>
    concept ECSComponent = requires {
        std::is_base_of_v<Component<typename UserComponent::UserComponentT, typename UserComponent::UserDataT>, UserComponent>;
    };
}

#define REF(somePtr) (assert(somePtr), *(somePtr))

#endif //SPACESHIPBP_COMPONENT_H
