#pragma once

#include <memory>

#include "pipeline/actions/ActionInterface.hpp"

/**
 * @brief Loads resources using the available loaders for specific resource URIs.
 */
class LoadAction final : public ActionInterface
{
public:
    /**
     * @brief Constructor that makes the available loaders
     * ready to be used for loading resources.
     */
    LoadAction();

    /**
     * Class destructor.
     */
    ~LoadAction();

    /**
     * @brief Attempts to load the given resource using one of the available loaders.
     *
     * @param[in,out] resource Resource to load.
     *
     * @return True if the resource was successfully loaded, false otherwise.
     */
    bool handleResource(Resource& resource) const override;

private:
    /// Container holding exclusive ownership pointers of all the available loaders.
    std::vector<std::unique_ptr<class LoaderBase>> availableLoaders_;
};
