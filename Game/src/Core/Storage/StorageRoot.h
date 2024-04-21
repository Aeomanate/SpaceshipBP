#ifndef SPACESHIPBP_STORAGEROOT_H
#define SPACESHIPBP_STORAGEROOT_H
#include <filesystem>
namespace fs = std::filesystem;

namespace Serialization { class SerializableBase; };
class StorageRoot
{
public:
    StorageRoot(Serialization::SerializableBase* rootMemberVariable);
    virtual ~StorageRoot() = default;

    void Init(const fs::path& storageFolder, const std::string& storageFilename);

    void LoadOrCreate();
    bool Load();
    bool Save();

protected:
    Serialization::SerializableBase* rootMemberVariable;
    fs::path folder;
    std::string filename;
};


#endif //SPACESHIPBP_STORAGEROOT_H
