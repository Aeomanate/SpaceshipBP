#include "SystemRelated.h"

#include <Windows.h>

void SystemRelated::ShowConsole()
{
    ::ShowWindow(::GetConsoleWindow(), SW_SHOW);
}

void SystemRelated::HideConsole()
{
    ::ShowWindow(::GetConsoleWindow(), SW_HIDE);
}

bool SystemRelated::CreateDirWhenAbsent(fs::path directory)
{
    if(!fs::exists(directory))
    {
        fs::create_directories(directory);
    }

    return fs::exists(directory);
}
