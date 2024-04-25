#ifndef SPACESHIPBP_MENULAYER_H
#define SPACESHIPBP_MENULAYER_H

#include <stack>
#include <memory>

#include "Core/EventsHandling/ListenersEmitters.h"
#include "UI/Menus/BaseMenu.h"

class MenuLayer
{
public:
    MenuLayer();

    template <class MenuType>
    void SpawnMenu()
    {
        menuStack.push(std::make_unique<MenuType>());
        listenerCloseMenuRequest.SubscribeEmitter(menuStack.top()->emitterCloseRequest);
    }

    BaseMenu* TopMenu();

public: // Emitters
    SIMPLE_EMITTER(LastMenuClosed);

public: // Public listeners
    SIMPLE_LISTENER(CloseMenuRequest);

private: // Private listeners


private:
    std::stack<std::unique_ptr<BaseMenu>> menuStack;
};

#endif //SPACESHIPBP_MENULAYER_H
