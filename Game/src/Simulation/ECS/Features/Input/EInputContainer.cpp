#include "EInputContainer.h"
#include "CQueueMouseMoves.h"
#include "CQueueMouseClicks.h"
#include "CQueuePlayerMoveDirections.h"


EInputContainer::EInputContainer()
{
    Claim<CQueueMouseClicks>();
    Claim<CQueueMouseMoves>();
    Claim<CQueuePlayerMoveDirections>();
}
