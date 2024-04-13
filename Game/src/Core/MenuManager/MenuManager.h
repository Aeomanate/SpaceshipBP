#ifndef SPACESHIPBP_MENUMANAGER_H
#define SPACESHIPBP_MENUMANAGER_H

#include <stack>
#include <memory>

class BaseMenu;

class MenuManager
{

public: // MenuManager methods

    template <class MenuType>
    void SpawnMenu();

private:
    std::stack<std::unique_ptr<BaseMenu>> menuStack;
};

#include "MenuManagerTemplates.h"

#endif //SPACESHIPBP_MENUMANAGER_H
