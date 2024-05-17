#include "GetterMenuLayer.h"
#include "Core/Application/Application.h"

MenuLayer& getMenuLayer()
{
    return Application::GetAggregatedObject<MenuLayer>();
}
