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

void StorageRoot::LoadOrCreate()
{
    if(!Load())
    {
        Save();
    }
}

bool StorageRoot::Load()
{
    std::ifstream in = SystemRelated::StreamOpen<std::ifstream>(folder, filename);
    if(!in || !(in >> *rootMemberVariable))
    {
        Log(getLoc().fileOperations.jsonParseWarning, (folder / filename).string(), Logger::Level::WARNING);
        return false;
    }

    return true;
}

bool StorageRoot::Save()
{
    std::ofstream out = SystemRelated::StreamOpen<std::ofstream>(folder, filename);
    if(!out || !(out << *rootMemberVariable))
    {
        Log(getLoc().fileOperations.jsonWriteWarning, (folder / filename).string(), Logger::Level::WARNING);
        return false;
    }

    return true;
}

void StorageRoot::Init(const fs::path& storageFolder, const std::string& storageFilename)
{
    folder = storageFolder;
    filename = storageFilename;
}
