#include <cassert>
#include "SInputCleaner.h"
#include "CInputMousePositions.h"
#include "CInputMoveDirections.h"
#include "CInputMouseClicks.h"

void SInputCleaner::Update(float)
{
    auto popHandledElement = [] (auto queueComponentPtr)
    {
        if(!REF(queueComponentPtr)->empty())
        {
            REF(queueComponentPtr)->pop();
        }
    };

    popHandledElement(CInputMousePositions::TryGetFirstDataPtr());
    popHandledElement(CInputMouseClicks::TryGetFirstDataPtr());
    popHandledElement(CInputMoveDirections::TryGetFirstDataPtr());
}
