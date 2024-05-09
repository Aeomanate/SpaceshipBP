#ifndef SPACESHIPBP_SINPUTINJECTOR_H
#define SPACESHIPBP_SINPUTINJECTOR_H


#include <optional>
#include "SFML/Window/Event.hpp"
#include "Simulation/ECS/System.h"
#include "CInputMoveDirections.h"
#include "CInputMouseClicks.h"
#include "CInputMousePositions.h"

template <class CQueue, class InputDataT>
struct PendingAction
{
    std::optional<InputDataT> actionOpt;
};

struct PendingInputActions
{
    PendingAction<CInputMoveDirections, sf::Vector2f> moveDirection;
    PendingAction<CInputMouseClicks, sf::Vector2f> mouseClick;
    PendingAction<CInputMousePositions, sf::Vector2f> mousePos;
};

class SInputInjector: public ECS::System
{
protected:
    void Update(float dt) override;

public:
    SInputInjector()
    : ECS::System(ECS::System::Order::PRE_GAMEPLAY)
    { }

    void InjectMoveVector(sf::Vector2f direction);
    void InjectMouseClick(sf::Vector2f position);
    void InjectMousePosition(sf::Vector2f position);

private:
    PendingInputActions pendingInputActions;
};


#endif //SPACESHIPBP_SINPUTINJECTOR_H
