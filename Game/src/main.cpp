#include <Windows.h>
#include <Core/Application.h>

int main()
{
    ::ShowWindow(::GetConsoleWindow(), SW_HIDE);
    Application().startLoop();
}
