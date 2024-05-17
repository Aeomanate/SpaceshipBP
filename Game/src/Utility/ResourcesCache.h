#ifndef SPACESHIPBP_RESOURCESCACHE_H
#define SPACESHIPBP_RESOURCESCACHE_H

#include <unordered_map>
#include <string_view>
#include <optional>
#include <filesystem>
#include <source_location>
#include "Core/Application/ObjectsAggregator/GetterConfig.h"
#include "Core/Application/ObjectsAggregator/GetterLog.h"
#include "Core/Storage/Config/GeneralConfig.h"
#include "Utility/Logger/Logger.h"
#include "Utility/TypeTraits.h"

namespace
{
    template <auto configMemberPtr>
    using OwningStruct = Traits::MemberPtr::OwningStruct<configMemberPtr>;

    template <auto configMemberPtr>
    using Config = Traits::MemberPtr::ObjectT<configMemberPtr>;
}

template <class DerivedT, class ResourceT, auto configResourceMemberPtr> requires
requires (
    DerivedT derivedResourceProvider,
    ResourceT resource,
    Config<configResourceMemberPtr> configResource,
    OwningStruct<configResourceMemberPtr> owningStruct)
{
    { owningStruct.folder };
    { configResource.name };
}
class ResourcesCache
{
public:
    using OuterConfigT = OwningStruct<configResourceMemberPtr>;
    using ResourceConfigT = Config<configResourceMemberPtr>;
    using LoadErrorT = std::optional<std::string>;
    using CustomResourceLoaderFuncT = LoadErrorT (*)(ResourceT&, const fs::path&);

public:
    void LoadResources()
    {
        getConfig().resources.Visit([thisPtr=this] (const OuterConfigT& configsStorage) {
            thisPtr->configsStoragePtr = &configsStorage;
        });

        configsStoragePtr->Visit([thisPtr=this](const ResourceConfigT& configResource){
            thisPtr->LoadResource(configResource);
        });
    }

    const ResourceT& GetResource(const ResourceConfigT& configResource) const
    {
        static const ResourceConfigT* lastRequestedConfig = nullptr;
        static const ResourceT* lastRequestedTexture = nullptr;

        if(lastRequestedConfig != &configResource)
        {
            lastRequestedConfig = &configResource;
            lastRequestedTexture = &resources.at(*configResource.name);
        }

        return *lastRequestedTexture;
    }

private:
    void LoadResource(const ResourceConfigT& configResource)
    {
        Log(getLoc().fileOperations.resourceLoadingNotify, configResource.name);
        auto [it, isInserted] = resources.try_emplace(*configResource.name, ResourceT{});
        if(!isInserted)
        {
            Log(getLoc().logLevel.error, "Unable to insert empty resource to the map", Logger::Level::ERROR);
            return;
        }

        static_assert(std::convertible_to<decltype(&DerivedT::LoadResource), CustomResourceLoaderFuncT>,
            "Need to declare CUSTOM_RESOURCE_LOADER in ResourceProvider derived class");
        LoadErrorT loadError = DerivedT::LoadResource(it->second, configsStoragePtr->folder / *configResource.name);

        if(loadError)
        {
            Log(getLoc().fileOperations.resourceLoadingWarning, *loadError, Logger::Level::WARNING);
            return;
        }
    }

private:
    std::unordered_map<std::string_view, ResourceT> resources;
    const OuterConfigT* configsStoragePtr = nullptr;
};

#define CUSTOM_RESOURCE_LOADER(ResType) \
friend class ResourcesCache; \
private: \
    static LoadErrorT LoadResource(ResType& out, const fs::path& path)

#endif //SPACESHIPBP_RESOURCESCACHE_H
