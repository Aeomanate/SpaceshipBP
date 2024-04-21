#ifndef SPACESHIPBP_APPLICATION_H
#define SPACESHIPBP_APPLICATION_H

#include <unordered_map>
#include "SFML/Graphics.hpp"
#include "Core/EventsHandling/ListenersEmitters.h"
#include "Simulation/Simulation.h"
#include "Utility/Singleton.h"
#include "LowLevelApplication.h"
#include "Core/MenuManager/MenuManager.h"
#include "Core/Storage/RootLocalization.h"
#include "Core/Storage/RootConfig.h"
#include "Utility/MemoryTextureStorage/TextureProvider.h"
#include "Utility/Math/Random/Random.h"

class Application: public LowLevelApplication, public Singleton<Application>
{
    friend class Singleton<Application>;
public:
    void Init() override;
    ~Application() override;

public:
    static MenuManager& GetMenuManager();
    static const Simulation& GetSimulation();
    static const RootConfig& GetConfig();
    static const GeneralLocalization& GetLoc();
    static const TextureProvider& GetTextureProvider();
    static Random& GetRnd();

private: // Game-related methods
    void Draw() override;
    void Update() override;
    void FinishWork() override;

private: // Listeners
    SIMPLE_LISTENER(LastMenuClosed);
    DATA_LISTENER(KeyPressed, sf::Event::KeyEvent);

private: // Game-related objects
    MenuManager menuManager;
    Simulation simulation;
    TextureProvider textureProvider;
    Random random;

    RootConfig rootConfig;
    RootLocalization rootLocalization;
protected:
    void ListenersInit();
    Application();

};

#endif
