#include "StorageRoot.h"

#include <filesystem>
#include <fstream>
#include "Utility/Logger/Logger.h"
#include "Utility/SystemRelated/SystemRelated.h"
#include "Core/Application/ApplicationShortcuts.h"
#include "Utility/Serialization/Serializable.h"

StorageRoot::StorageRoot(Serialization::SerializableBase* rootMemberVariable)
: rootMemberVariable { rootMemberVariable }
{ }

StorageRoot::~StorageRoot()
{

}

void StorageRoot::LoadOrCreate()
{
    if(!Load())
    {
        Save();
    }
}

template <class StreamType>
StreamType openFileStream(fs::path folder, std::string_view name)
{
    StreamType stream;

    if(!fs::exists(folder))
    {
        Log(getLoc().fileOperations.absentNotify, folder.string());
    }

    if(!SystemRelated::CreateDirWhenAbsent(folder))
    {
        Log(getLoc().fileOperations.openOrCreateFailedWarning, folder.string(), LogLevel::WARNING);
        return std::move(stream);
    }

    fs::path configPath = folder / name;
    if(!fs::exists(configPath))
    {
        Log(getLoc().fileOperations.absentNotify, configPath.string());
    }

    Log(getLoc().fileOperations.tryOpenOrCreateNotify, configPath.string());

    stream.open(configPath);
    if (!stream)
    {
        Log(getLoc().fileOperations.openOrCreateFailedWarning, configPath.string(), LogLevel::WARNING);
    }

    return std::move(stream);
}

bool StorageRoot::Load()
{
    fs::path folder = getConfig().config.folder;
    std::string filename = getConfig().config.Name;

    std::ifstream in = openFileStream<std::ifstream>(folder, filename);
    if(!in)
    {
        Log(getLoc().fileOperations.absentNotify, folder.string(), LogLevel::WARNING);
        return false;
    }

    if(!(in >> *rootMemberVariable) || rootMemberVariable->HasParseError())
    {
        Log(getLoc().fileOperations.jsonParseWarning, (folder / filename).string(), LogLevel::WARNING);
        return false;
    }

    return true;
}

void StorageRoot::Save()
{

    fs::path folder = getConfig().config.folder;
    std::string filename = getConfig().config.Name;

    if(!fs::exists(folder))
    {
        Log(getLoc().fileOperations.absentNotify, folder.string());
    }

    std::ofstream out = openFileStream<std::ofstream>(folder, filename);

    if (!out)
    {
        Log(getLoc().fileOperations.openOrCreateFailedWarning, (folder / filename).string(), LogLevel::WARNING);
        return;
    }

    if(!(out << *rootMemberVariable))
    {
        Log(getLoc().fileOperations.jsonWriteWarning, (folder / filename).string(), LogLevel::WARNING);
    }
}
