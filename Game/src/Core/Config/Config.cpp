#include "Config.h"

#include <fstream>
#include <filesystem>
#include <rapidjson/prettywriter.h>
#include <rapidjson/document.h>

namespace fs = std::filesystem;

void Config::Load()
{
    fs::path configPath = application.configFolder;
    fs::path configLocation = configPath / application.configName;

    std::ifstream configFileReader;
    configFileReader.open(configLocation);

    if(!configFileReader.is_open())
    {
        std::ofstream configWriter;
        configWriter.open(configLocation);

        if(!configWriter.is_open())
        {

        }
    }
}

void Config::Store()
{

}

void Config::CheckStoredAndLoad()
{

}


