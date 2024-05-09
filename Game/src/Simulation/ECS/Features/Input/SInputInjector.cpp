#include <cassert>
#include "SInputInjector.h"
#include "Utility/Math/Vectors.h"

template<class CInput, class InputDataT>
void injectPendingAction (PendingAction<CInput, InputDataT>& action, bool(*flushApprover)(InputDataT) = [](InputDataT){return true;})
{
    if(action.actionOpt)
    {
        auto actionsQueuePtr = CInput::TryGetFirstDataPtr();
        REF(actionsQueuePtr)->push(*action.actionOpt);

        if(!flushApprover(*action.actionOpt))
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

void SInputInjector::InjectMoveVector(sf::Vector2f direction)
{
    if (!pendingInputActions.moveDirection.actionOpt)
    { pendingInputActions.moveDirection.actionOpt = sf::Vector2f{0, 0}; }
    *pendingInputActions.moveDirection.actionOpt += direction;
}

void SInputInjector::InjectMouseClick(sf::Vector2f position)
{
    pendingInputActions.mouseClick.actionOpt = position;
}

void SInputInjector::InjectMousePosition(sf::Vector2f position)
{
    pendingInputActions.mousePos.actionOpt = position;
}
