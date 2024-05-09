#include "ETimer.h"
#include "CTimer.h"

ETimer::ETimer()
: ECS::Entity("Timer")
{
    Claim<CTimer>();
}
