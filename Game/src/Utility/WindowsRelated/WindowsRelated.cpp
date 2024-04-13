#include "WindowsRelated.h"

#include <Windows.h>

void WindowsRelated::ShowConsole()
{
    ::ShowWindow(::GetConsoleWindow(), SW_SHOW);
}

void WindowsRelated::HideConsole()
{
    ::ShowWindow(::GetConsoleWindow(), SW_HIDE);
}
