#ifndef SPACESHIPBP_LEVELCREATORSSTORAGE_H
#define SPACESHIPBP_LEVELCREATORSSTORAGE_H

#include <functional>
#include <unordered_map>
#include "Core/Storage/Config/GeneralConfig.h"
#include "LevelBase.h"

struct LevelCreatorsStorage
{
    using LevelCreatorNullBasedFunc = std::function<LevelBase::LevelPtr()>;
    using LevelCreatorPrevBasedFunc = std::function<LevelBase::LevelPtr(LevelBase::LevelPtr)>;
    using MapKey = std::string_view;

public:
    template <class UserLevel>
    LevelCreatorsStorage(ConfigLevel ConfigLevels::*configLevelPtr, UserLevel*)
    {
        const GeneralConfig& getConfig();
        AddLevelCreatorNullBased<UserLevel>(getConfig().simulation.configLevels.*configLevelPtr);
        AddLevelCreatorPrevBased<UserLevel>(getConfig().simulation.configLevels.*configLevelPtr);
    }

    template <class PrevLevel = int>
    static inline LevelBase::LevelPtr Create(const ConfigLevel& configLevel, PrevLevel&& prevLevel = {})
    {
        if constexpr(!std::is_same_v<PrevLevel, int>)
        { return prevBased[*configLevel.name](std::move(prevLevel)); }
        else
        { return nullBased[*configLevel.name](); }
    }

private:
    template <class UserLevel>
    static inline void AddLevelCreatorNullBased(const ConfigLevel& configLevel)
    {
        nullBased.try_emplace(*configLevel.name, [] {
            return std::make_unique<UserLevel>();
        });
    }

    template <class UserLevel>
    static inline void AddLevelCreatorPrevBased(const ConfigLevel& configLevel)
    {
        prevBased.try_emplace(*configLevel.name, [] (LevelBase::LevelPtr prevLevel) {
            return std::make_unique<UserLevel>(std::move(prevLevel));
        });
    }

private:
    static inline std::unordered_map<MapKey, LevelCreatorNullBasedFunc> nullBased;
    static inline std::unordered_map<MapKey, LevelCreatorPrevBasedFunc> prevBased;
};

#endif //SPACESHIPBP_LEVELCREATORSSTORAGE_H
