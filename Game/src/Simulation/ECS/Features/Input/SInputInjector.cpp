#include "SInputInjector.h"
#include "Utility/Math/Vectors/Vectors.h"

void SInputInjector::Update(float)
{
    auto injectPendingAction = [] <class CQueue, class ActionT> (PendingAction<CQueue, ActionT>& action)
    {
        if(action.value)
        {
            CQueue::TryGetFirst().value()->push(*action.value);
            action.value = std::nullopt;
        }
    };

    injectPendingAction(pendingInputActions.mouseClick);
    injectPendingAction(pendingInputActions.mousePos);
    injectPendingAction(pendingInputActions.moveDirection);
}

void SInputInjector::InjectMovement(sf::Vector2f direction)
{
    pendingInputActions.moveDirection.value = norm(direction);
}

void SInputInjector::InjectMouseClick(sf::Vector2f position)
{
    pendingInputActions.mouseClick.value = position;
}

void SInputInjector::InjectMousePosition(sf::Vector2f position)
{
    pendingInputActions.mousePos.value = position;
}
