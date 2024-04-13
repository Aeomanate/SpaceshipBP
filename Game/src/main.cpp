#include <Windows.h>
#include "Core/Application/Application.h"

int main()
{
    ::ShowWindow(::GetConsoleWindow(), SW_HIDE);
    Application().startLoop();
}
