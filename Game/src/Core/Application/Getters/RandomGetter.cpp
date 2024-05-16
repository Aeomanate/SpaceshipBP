#include "RandomGetter.h"
#include "Core/Application/Application.h"

Random& getRand()
{
    return Application::GetRandom();
}
