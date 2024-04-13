#ifndef SPACESHIPBP_MENUMANAGERTEMPLATEIMPL_H
#define SPACESHIPBP_MENUMANAGERTEMPLATEIMPL_H

template <class MenuType>
void MenuManager::SpawnMenu()
{
    menuStack.push(std::make_unique<MenuType>());
}

#endif //SPACESHIPBP_MENUMANAGERTEMPLATEIMPL_H
