#include "Core/Application/Application.h"

int main()
{
    Application::GetInstance()->Setup({ 800, 600 }, "SpaceShip");
    Application::GetInstance()->Run();
}
