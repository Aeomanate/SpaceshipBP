#ifndef SPACESHIPBP_APPLICATION_H
#define SPACESHIPBP_APPLICATION_H

#include <unordered_map>
#include "SFML/Graphics.hpp"
#include "Utility/EventsHandling/ListenersEmitters.h"
#include "Utility/MenuManager/MenuManager.h"
#include "Simulation/Simulation.h"
#include "Utility/Singleton.h"
#include "LowLevelApplication.h"

class Application: public LowLevelApplication, public Singleton<Application>
{
public:
    Application();

    MenuManager& GetMenuManager();
    Simulation const& GetSimulation() const;

private: // Game-related methods
    void Draw() override;
    void Update() override;

private: // Listeners
    SIMPLE_LISTENER(LastMenuClosed);

private: // Game-related objects
    MenuManager menuManager;
    Simulation simulation;

};

#endif
