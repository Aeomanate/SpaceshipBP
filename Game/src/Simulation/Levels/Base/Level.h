#ifndef SPACESHIPBP_LEVEL_H
#define SPACESHIPBP_LEVEL_H

#include <type_traits>
#include "LevelCreatorsStorage.h"
#include "LevelBase.h"

template <class UserLevel, ConfigLevel ConfigLevels::*configLevelMemberPtr>
class Level: public LevelBase
{
private:
    static inline LevelCreatorsStorage __ENABLE_LEVEL { configLevelMemberPtr, static_cast<UserLevel*>(nullptr) };
};


#endif //SPACESHIPBP_LEVEL_H
