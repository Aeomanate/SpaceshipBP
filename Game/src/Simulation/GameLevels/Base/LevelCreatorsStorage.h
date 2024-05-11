#ifndef SPACESHIPBP_LEVELCREATORSSTORAGE_H
#define SPACESHIPBP_LEVELCREATORSSTORAGE_H

#include <functional>
#include <unordered_map>
#include "Core/Storage/Config/GeneralConfig.h"
#include "LevelBase.h"
#include "Utility/Singleton.h"

const GeneralConfig& getConfig();

class LevelCreatorsStorage: public Singleton<LevelCreatorsStorage>
{
    template <class UserLevel, ConfigLevel ConfigLevels::*configLevelMemberPtr>
    friend class Level;

    using LevelCreatorNullBasedFunc = std::function<LevelBase::LevelPtr()>;
    using LevelCreatorPrevBasedFunc = std::function<LevelBase::LevelPtr(LevelBase::LevelPtr)>;
    using MapKey = std::string_view;

public:
    template <class PrevLevel = int>
    LevelBase::LevelPtr Create(const ConfigLevel& configLevel, PrevLevel&& prevLevel = {})
    {
        if constexpr(!std::is_same_v<PrevLevel, int>)
        { return prevBased[*configLevel.name](std::move(prevLevel)); }
        else
        { return nullBased[*configLevel.name](); }
    }

private:
    template <class UserLevel>
    void AddLevelCreatorNullBased(const ConfigLevel& configLevel)
    {
        nullBased.try_emplace(*configLevel.name, [] {
            return std::make_unique<UserLevel>();
        });
    }

    template <class UserLevel>
    void AddLevelCreatorPrevBased(const ConfigLevel& configLevel)
    {
        prevBased.try_emplace(*configLevel.name, [] (LevelBase::LevelPtr prevLevel) {
            return std::make_unique<UserLevel>(std::move(prevLevel));
        });
    }

    template <class UserLevel, ConfigLevel ConfigLevels::*configLevelPtr>
    bool RegisterLevel()
    {
        AddLevelCreatorNullBased<UserLevel>(getConfig().simulation.configLevels.*configLevelPtr);
        AddLevelCreatorPrevBased<UserLevel>(getConfig().simulation.configLevels.*configLevelPtr);
        return true;
    }

private:
    std::unordered_map<MapKey, LevelCreatorNullBasedFunc> nullBased;
    std::unordered_map<MapKey, LevelCreatorPrevBasedFunc> prevBased;
};

#endif //SPACESHIPBP_LEVELCREATORSSTORAGE_H
