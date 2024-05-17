#ifndef SPACESHIPBP_APPLICATION_H
#define SPACESHIPBP_APPLICATION_H

#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "Core/EventsHandling/ListenersEmitters.h"
#include "Utility/Singleton.h"
#include "LowLevelApplication.h"
#include "ObjectsAggregator/ObjectsAggregator.h"


class Application: public LowLevelApplication, public Singleton<Application>
{
    friend class Singleton<Application>;

public:
    Application& Init() override;

    template <class T>
    static inline T& GetAggregatedObject()
    { return std::get<T>(GetInstance().objectsAggregator.applicationObjects); }

private: // Game-related methods
    void Draw() override;
    void Update() override;
    void FinishWork() override;

private: // Listeners
    SIMPLE_LISTENER(LastMenuClosed);
    DATA_LISTENER(KeyPressed, sf::Event::KeyEvent);

protected:
    void InitListeners();
    void InitStorages();
    void InitGameRelated();

private:
    ObjectsAggregator<Application> objectsAggregator;
};

#endif
