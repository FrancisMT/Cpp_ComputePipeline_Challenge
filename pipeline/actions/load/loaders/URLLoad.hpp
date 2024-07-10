#pragma once

#include <memory>

#include "LoaderBase.hpp"

/**
 * @brief Loads resources from an URL.
 */
class URLLoad final : public LoaderBase
{
public:
    /**
     * \brief Class destructor.
     */
    ~URLLoad() override = default;

    /**
     * \brief Create a pointer to an URL Loader.
     *
     * \return An URLLoad pointer with exclusive ownership.
     */
    static std::unique_ptr<LoaderBase> createURLLoad();

    /**
     * @brief Loads the resource from an URL.
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
    URLLoad();
};
