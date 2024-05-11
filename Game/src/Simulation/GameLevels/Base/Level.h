#ifndef SPACESHIPBP_LEVEL_H
#define SPACESHIPBP_LEVEL_H

#include "LevelCreatorsStorage.h"
#include "LevelBase.h"

template <class UserLevel, ConfigLevel ConfigLevels::*configLevelMemberPtr>
class Level: public LevelBase
{
protected:
    Level()
    {
        // Because unused static field IS_REGISTERED will be deleted from template instantiation
        // https://timsong-cpp.github.io/cppwp/n4868/temp.spec#temp.inst-11
        if(!IS_REGISTERED)
        { return; }
    }
    static inline bool IS_REGISTERED = LevelCreatorsStorage::GetInstance().RegisterLevel<UserLevel, configLevelMemberPtr>();
};

#endif //SPACESHIPBP_LEVEL_H
