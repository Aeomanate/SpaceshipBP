#include "GetterRandom.h"
#include "Core/Application/Application.h"

Random& getRand()
{
    return Application::GetAggregatedObject<Random>();
}
