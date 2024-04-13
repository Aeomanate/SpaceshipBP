#ifndef SPACESHIPBP_MENUMANAGER_H
#define SPACESHIPBP_MENUMANAGER_H

#include <stack>
#include <memory>

#include "Utility/EventsHandling/ListenersEmitters.h"
#include "UI/Menus/BaseMenu.h"

class MenuManager
{
public:
    MenuManager();

    template <class MenuType>
    void SpawnMenu();

    BaseMenu* TopMenu();

public: // Emitters
    SIMPLE_EMITTER(LastMenuClosed);

public: // Public listeners
    SIMPLE_LISTENER(CloseMenuRequest);

private: // Private listeners


private:
    std::stack<std::unique_ptr<BaseMenu>> menuStack;
};

#include "TemplateSpecializes.h"

#endif //SPACESHIPBP_MENUMANAGER_H
