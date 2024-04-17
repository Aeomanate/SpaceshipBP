#include "ApplicationConfigManager.h"

#include <filesystem>
#include <fstream>
#include "Utility/Logger/Logger.h"
#include "Utility/SystemRelated/SystemRelated.h"
#include "Core/Application/ApplicationShortcuts.h"


ApplicationConfigManager::~ApplicationConfigManager()
{
    Save();
}

void ApplicationConfigManager::LoadOrCreate()
{
    if(!Load())
    {
        Save();
    }
}

template <class StreamType>
StreamType openFileStream(fs::path folder, std::string_view name)
{
    StreamType configFromFileStream;

    if(SystemRelated::CreateDirWhenAbsent(folder))
    {
        Log(getLoc().fileOperations.createNotify, folder.string());
        return std::move(configFromFileStream);
    }

    fs::path configPath = folder / name;
    if(!fs::exists(configPath))
    {
        Log(getLoc().fileOperations.createNotify, configPath.string());
    }

    configFromFileStream.open(configPath);
    if (!configFromFileStream)
    {
        Log(getLoc().fileOperations.createFailed, configPath.string(), LogLevel::WARNING);
    }

    return std::move(configFromFileStream);
}

bool ApplicationConfigManager::Load()
{
    fs::path folder = getConfig().Config.Folder;
    std::string name = getConfig().Config.Name;

    if(!(openFileStream<std::ifstream>(folder, name) >> Application) || Application.HasParseError())
    {
        Log(getLoc().parseJsonWarning, (folder / name).string(), LogLevel::WARNING);
        return false;
    }

    return true;
}

void ApplicationConfigManager::Save()
{

    fs::path folder = getConfig().Config.Folder;
    std::string name = getConfig().Config.Name;

    //if(!(openFileStream<std::ofstream>(folder, name) << Application))
    {

    }
}


