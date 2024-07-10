#include "LoadAction.hpp"

#include <functional>
#include <iostream>

#include "loaders/AppBundleLoad.hpp"
#include "loaders/FileLoad.hpp"
#include "loaders/URLLoad.hpp"

namespace {

/// Alias for the function signature used to spawn loader pointers.
using LoaderFactory = std::function<std::unique_ptr<LoaderBase>()>;

/**
 * \brief Creates and returns a static list of loader factories.
 *
 * Each factory consists of a function that creates an instances of a specific loader.
 *
 * \return Static list of loader factories.
 */
std::vector<LoaderFactory>& loaderFactoriesList()
{
    static std::vector<LoaderFactory> loaderFactories;
    return loaderFactories;
}

/**
 * @brief Helper lambda used to populate the list of available loader factories.
 *
 * @return The number of registered loader factories.
 */
const auto registeredLoaders = []() {
    loaderFactoriesList().push_back(&AppBundleLoad::createAppBundleLoad);
    loaderFactoriesList().push_back(&FileLoad::createFileLoad);
    loaderFactoriesList().push_back(&URLLoad::createURLLoad);
    return loaderFactoriesList().size();
}();

} // namespace

LoadAction::LoadAction()
{
    availableLoaders_.reserve(registeredLoaders);
    std::transform(loaderFactoriesList().cbegin(),
                   loaderFactoriesList().cend(),
                   std::back_inserter(availableLoaders_),
                   [](const LoaderFactory& loaderFactory) { return loaderFactory(); });
}

LoadAction::~LoadAction()
{
    // Purposely left empty:
    // std::unique_ptr needs a complete type during object construction and destruction.
    // If the constructor or destructor is inlined (or defaulted) in the header file,
    // forward declared types will be tread as an incomplete type.
}

bool LoadAction::handleResource(Resource& resource) const
{
    const auto viableLoaderItr
          = std::find_if(availableLoaders_.cbegin(),
                         availableLoaders_.cend(),
                         [&resource](const std::unique_ptr<LoaderBase>& loader) {
                             return loader->canLoadResource(resource);
                         });

    return viableLoaderItr != availableLoaders_.cend()
           && (*viableLoaderItr)->loadResource(resource);
}
