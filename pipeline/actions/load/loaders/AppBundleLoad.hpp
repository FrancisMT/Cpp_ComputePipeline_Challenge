#pragma once

#include <memory>

#include "LoaderBase.hpp"

/**
 * @brief Loads resources from an application bundle.
 */
class AppBundleLoad final : public LoaderBase
{
public:
    /**
     * \brief Class destructor.
     */
    ~AppBundleLoad() override = default;

    /**
     * \brief Create a pointer to an App Bundle Loader.
     *
     * \return An AppBundleLoad pointer with exclusive ownership.
     */
    static std::unique_ptr<LoaderBase> createAppBundleLoad();

    /**
     * @brief Loads the resource from an application bundle.
     *
     * @param[in,out] resource Resource to be loaded.
     *
     * @return True if the resource was successfully loaded, false otherwise.
     */
    bool loadResource(Resource& resource) const override;

private:
    /**
     * @brief Private constructor.
     */
    AppBundleLoad();
};