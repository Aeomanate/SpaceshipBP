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
        using KeyType = Entity*;
        using ValueType = Derived;
        using EntityWithDataStorage = std::unordered_map<KeyType, ValueType>;
    public:
        inline static auto AllEntities()
        {
            return rv::all(entitiesWithData);
        }

        inline static auto Filter()
        {
            return rv::filter([] (auto node) {
                return entitiesWithData.contains(node.first);
            });
        }

        inline static ValueType& Data(KeyType key)
        {
            return entitiesWithData.find(key)->second;
        }

        inline static void Claim(Entity* entity, Derived&& data)
        {
            entitiesWithData.insert(entity, std::move(data));
        }

        inline static void Reject(Entity* entity)
        {
            entitiesWithData.erase(entity);
        }


    private:
        static inline EntityWithDataStorage entitiesWithData;
    };
}


#endif //SPACESHIPBP_COMPONENT_H
