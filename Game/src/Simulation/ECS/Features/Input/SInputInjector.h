#ifndef SPACESHIPBP_SINPUTINJECTOR_H
#define SPACESHIPBP_SINPUTINJECTOR_H


#include <optional>
#include "SFML/Window/Event.hpp"
#include "Simulation/ECS/System.h"
#include "CQueuePlayerMoveDirections.h"
#include "CQueueMouseClicks.h"
#include "CQueueMouseMoves.h"

template <class CQueue, class ActionT>
concept ActionQueueConcept = requires {
    std::is_base_of_v<CQueueBase<ActionT>, CQueue>;
};

template <class CQueue, class ActionT>
requires ActionQueueConcept<CQueue, ActionT>
struct PendingAction
{
    std::optional<ActionT> actionOpt;
};

struct PendingInputActions
{
    PendingAction<CQueuePlayerMoveDirections, sf::Vector2f> moveDirection;
    PendingAction<CQueueMouseClicks, sf::Vector2f> mouseClick;
    PendingAction<CQueueMouseMoves, sf::Vector2f> mousePos;
};

class SInputInjector: public ECS::System
{
protected:
    void Update(float dt) override;

public:
    SInputInjector()
    : ECS::System(ECS::System::Order::PRE_GAMEPLAY)
    { }

    void InjectMovement(sf::Vector2f direction);
    void InjectMouseClick(sf::Vector2f position);
    void InjectMousePosition(sf::Vector2f position);

private:
    PendingInputActions pendingInputActions;
};


#endif //SPACESHIPBP_SINPUTINJECTOR_H
