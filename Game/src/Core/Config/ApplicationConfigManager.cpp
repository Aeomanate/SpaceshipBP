#include "ApplicationConfigManager.h"

#include <filesystem>
#include <fstream>
#include <iterator>
#include <rapidjson/prettywriter.h>
#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>
#include "Utility/Logger/Logger.h"
#include "Utility/SystemRelated/SystemRelated.h"
#include "Core/Application/ApplicationShortcuts.h"


void ApplicationConfigManager::LoadOrCreate()
{
    if(!Load())
    {
        Save();
    }
}

bool ApplicationConfigManager::Load()
{
    if(SystemRelated::CreateDirWhenAbsent(getConfig().Config.Folder))
    {
        Log(getLoc().fileOperations.createNotify, getConfig().Config.Folder.string());
        return false;
    }

    fs::path configPath = getConfig().Config.Folder / Application.Config.Name;

    std::ifstream inputConfigStream(configPath);
    if (!inputConfigStream)
    {
        Log(getLoc().fileOperations.createFailed, configPath.string(), LogLevel::WARNING);
        return false;
    }

    std::string inputConfigRawJson;
    inputConfigRawJson.resize(static_cast<size_t>(fs::file_size(configPath)));
    inputConfigStream.read(inputConfigRawJson.data(), inputConfigRawJson.size());

    rapidjson::Document document;
    document.ParseInsitu(inputConfigRawJson.data());
    // Serializable::StoreNewDocumentAllocator(document.GetAllocator());

    if(document.HasParseError())
    {
        Log(getLoc().parseJsonWarning, configPath.string(), LogLevel::WARNING);
        return false;
    }

    Application.SetFromJson(document);

    return true;
}

void ApplicationConfigManager::Save()
{
    fs::path configPath = getConfig().Config.Folder / Application.Config.Name;

    if(SystemRelated::CreateDirWhenAbsent(getConfig().Config.Folder))
    {
        Log(getLoc().fileOperations.createNotify, getConfig().Config.Folder.string());
    }

    if(!fs::exists(configPath))
    {
        Log(getLoc().fileOperations.createNotify, configPath.string());
    }

    std::ofstream newConfig(configPath);
    if (!newConfig)
    {
        Log(getLoc().fileOperations.createFailed, configPath.string(), LogLevel::WARNING);
        return;
    }

    newConfig << Application;
}

