#include "SInputCleaner.h"
#include "CQueueMouseMoves.h"
#include "CQueuePlayerMoveDirections.h"
#include "CQueueMouseClicks.h"

void SInputCleaner::Update(float)
{
    auto popHandledElement = [] <class T> (std::queue<T>& queue)
    {
        queue.pop();
    };

    popHandledElement(CQueueMouseMoves::AllEntities().begin()->second.queue);
    popHandledElement(CQueueMouseClicks::AllEntities().begin()->second.queue);
    popHandledElement(CQueuePlayerMoveDirections::AllEntities().begin()->second.queue);
}
