#ifndef SPACESHIPBP_RESOURCESPROVIDER_H
#define SPACESHIPBP_RESOURCESPROVIDER_H

#include <unordered_map>
#include <string_view>
#include <optional>
#include <filesystem>
#include <source_location>
#include "Core/Application/Getters/ConfigGetter.h"
#include "Core/Application/Getters/LogGetter.h"
#include "Core/Storage/Config/GeneralConfig.h"
#include "Utility/Logger/Logger.h"
#include "Utility/TypeTraits.h"

namespace
{
    template <auto configMemberPtr>
    using OwningStruct = Traits::MemberPtr::OwningStruct<configMemberPtr>;

    template <auto configMemberPtr>
    using Config = Traits::MemberPtr::ObjectT<configMemberPtr>;

    template
    <
        class UserResourceProviderT, class ResourceT,
        class LoaderFuncSign = std::optional<std::string> (UserResourceProviderT::*)(ResourceT&, const fs::path&)
    >
    concept HasCustomLoaderFunc = requires {
        { &UserResourceProviderT::LoadResourceImpl } -> std::convertible_to<LoaderFuncSign>;
    };
}

template <class DerivedT, class ResourceT, auto configResourceMemberPtr> requires
requires (
        ResourceT resource,
        Config<configResourceMemberPtr> configResource,
        OwningStruct<configResourceMemberPtr> owningStruct,
        DerivedT derivedResourceProvider
    ) {
    { owningStruct.folder };
    { configResource.name };
    HasCustomLoaderFunc<DerivedT, ResourceT>;
}
class ResourcesProvider
{
public:
    using LoadErrorT = std::optional<std::string>;
    using OuterConfigT = OwningStruct<configResourceMemberPtr>;
    using ResourceConfigT = Config<configResourceMemberPtr>;

public:
    void LoadResources()
    {
        std::source_location();

        (getConfig().resources.*configResourceMemberPtr).Visit([thisPtr=this](const ResourceConfigT& configResourceT){
            thisPtr->LoadResource(configResourceT);
        });
    }

    const ResourceT& GetResource(const ResourceConfigT& configResource) const
    {
        static const ResourceConfigT* lastRequestedConfig = nullptr;
        static const sf::Texture* lastRequestedTexture = nullptr;

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

        LoadErrorT loadError = DerivedT::LoadResource(it->second, *configResource.folder / *configResource.name);
        if(loadError)
        {
            Log(getLoc().fileOperations.resourceLoadingWarning, *loadError, Logger::Level::WARNING);
            return;
        }
    }

private:
    std::unordered_map<std::string_view, ResourceT> resources;
};

#endif //SPACESHIPBP_RESOURCESPROVIDER_H
