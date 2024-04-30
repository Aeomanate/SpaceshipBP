#ifndef SPACESHIPBP_COMPONENT_H
#define SPACESHIPBP_COMPONENT_H

#include <unordered_map>
#include <ranges>


namespace ECS
{
    class Entity;
    namespace r = std::ranges;
    namespace rv = r::views;

    template<class Derived>
    class Component
    {
    public:
        using KeyType = Entity*;
        using ValueType = Derived;
        using EntityWithDataStorage = std::unordered_map<KeyType, ValueType>;

    public:
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

        static inline void Claim(Entity* entity)
        {
            entitiesWithData.insert({entity, ValueType{}});
        }

        static inline void Reject(Entity* entity)
        {
            entitiesWithData.erase(entity);
        }


    private:
        static inline EntityWithDataStorage entitiesWithData;
    };
}


#endif //SPACESHIPBP_COMPONENT_H
