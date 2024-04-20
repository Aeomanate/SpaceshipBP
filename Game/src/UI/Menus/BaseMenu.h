#ifndef SPACESHIPBP_BASEMENU_H
#define SPACESHIPBP_BASEMENU_H

#include <SFML/Graphics.hpp>

#include "Core/EventsHandling/ListenersEmitters.h"
#include "Utility/Updatable.h"

class BaseMenu: public sf::Drawable, public Updatable
{
public:
    BaseMenu();

public: // SFML interface
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

public: // Update interface
    void Update(float dt) override;

public: // Emitters
    SIMPLE_EMITTER(CloseRequest);

protected: // Listeners
    DATA_LISTENER(KeyPressed, sf::Event::KeyEvent);


private:
    sf::RenderTexture renderTexture;
};


#endif //SPACESHIPBP_BASEMENU_H
