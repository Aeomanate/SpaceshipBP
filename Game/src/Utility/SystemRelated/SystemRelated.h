#ifndef SPACESHIPBP_SYSTEMRELATED_H
#define SPACESHIPBP_SYSTEMRELATED_H

#include <filesystem>
#include "Core/Application/ObjectsAggregator/GetterLog.h"
#include "Utility/Logger/Logger.h"

namespace fs = std::filesystem;

class SystemRelated
{
public:
    static void ShowConsole();
    static void HideConsole();
    static bool CreateDirWhenAbsent(const fs::path& directory);

    template <class Stream>
    static Stream StreamOpen(fs::path folder, const std::string& name)
    {
        if(!SystemRelated::CreateDirWhenAbsent(folder))
        {
            return { };
        }

        fs::path pathToOpen = folder / name;
        if(!fs::exists(pathToOpen))
        {
            Log(getLoc().fileOperations.absentNotify, pathToOpen.string());
        }

        Log(getLoc().fileOperations.tryOpenOrCreateNotify, pathToOpen.string());
        Stream stream(pathToOpen);

        if (!stream)
        {
            Log(getLoc().fileOperations.openOrCreateFailedWarning, pathToOpen.string(), Logger::Level::WARNING);
        }

        return std::move(stream);
    }
};


#endif //SPACESHIPBP_SYSTEMRELATED_H
