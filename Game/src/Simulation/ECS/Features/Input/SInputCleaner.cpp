#include "SInputCleaner.h"
#include "CQueueMouseMoves.h"
#include "CQueuePlayerMoveDirections.h"
#include "CQueueMouseClicks.h"

void SInputCleaner::Update(float)
{
    auto popHandledElement = [] <class T> (std::optional<ECS::SimpleComponent<std::queue<T>>>&& component)
    {
        if(component && !component.value()->empty())
        {
            component.value()->pop();
        }
    };

    popHandledElement(CQueueMouseMoves::TryGetFirst());
    popHandledElement(CQueueMouseClicks::TryGetFirst());
    popHandledElement(CQueuePlayerMoveDirections::TryGetFirst());
}
