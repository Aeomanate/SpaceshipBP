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
    if(fs::exists(directory))
    {
        return true;
    } else
    {
        Log(getLoc().fileOperations.absentNotify, directory.string());
    }

    bool isCreated = fs::create_directories(directory);

    if(!isCreated)
    {
        Log(getLoc().fileOperations.openOrCreateFailedWarning, directory.string(), Logger::Level::WARNING);
    }

    return isCreated;
}
