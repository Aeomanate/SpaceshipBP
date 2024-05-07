#include <cassert>
#include "SInputInjector.h"
#include "Utility/Math/Vectors/Vectors.h"

template <class CQueue, class ActionT, class FlushApprover = bool(*)(const ActionT&)>
void injectPendingAction (PendingAction<CQueue, ActionT>& action, FlushApprover approveFlush = [] (const ActionT&) { return true; })
{
    if(action.actionOpt)
    {
        auto actionsQueueOpt = CQueue::TryGetFirst();
        assert(actionsQueueOpt);

        actionsQueueOpt.value()->push(action.actionOpt.value());

        if(!approveFlush(action.actionOpt.value()))
        { return; }

        action.actionOpt = std::nullopt;
    }
};

void SInputInjector::Update(float)
{
    injectPendingAction(pendingInputActions.mouseClick);
    injectPendingAction(pendingInputActions.mousePos);
    injectPendingAction(pendingInputActions.moveDirection, isSemiZero);
}

void SInputInjector::InjectMovement(sf::Vector2f direction)
{
    if (!pendingInputActions.moveDirection.actionOpt)
    { pendingInputActions.moveDirection.actionOpt = sf::Vector2f(); }
    pendingInputActions.moveDirection.actionOpt.value() += direction;
}

void SInputInjector::InjectMouseClick(sf::Vector2f position)
{
    pendingInputActions.mouseClick.actionOpt = position;
}

void SInputInjector::InjectMousePosition(sf::Vector2f position)
{
    pendingInputActions.mousePos.actionOpt = position;
}
