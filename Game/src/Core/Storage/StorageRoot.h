#ifndef SPACESHIPBP_STORAGEROOT_H
#define SPACESHIPBP_STORAGEROOT_H

namespace Serialization { class SerializableBase; };
class StorageRoot
{
public:
    StorageRoot(Serialization::SerializableBase* rootMemberVariable);
    ~StorageRoot();
    void LoadOrCreate();
    bool Load();
    void Save();

protected:
    Serialization::SerializableBase* rootMemberVariable;
};


#endif //SPACESHIPBP_STORAGEROOT_H
