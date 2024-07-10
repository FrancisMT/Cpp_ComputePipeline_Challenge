#pragma once

#include <string>
#include <vector>

#include "pipeline/Resource.hpp"

/**
 * @brief Base class for resource loaders that:
 * - checks if a given resource can be loaded based on a URI path prefix;
 * - defines an interface for loading resources;
 *
 * Derive classes must provide an implementation for the loadResource method
 * in order to define how the resource should be loaded.
 */
class LoaderBase
{
public:
    /**
     * @brief Constructor that takes a list of path prefixes
     * indicating the types of URIs that can be handled.
     *
     * @param[in] supportedPathPrefixes Vector supported URI prefixes.
     */
    LoaderBase(const std::vector<std::string>& supportedPathPrefixes);

    /**
     * @brief Virtual destructor.
     *
     * Ensures that derived class destructors are properly called.
     */
    virtual ~LoaderBase() = default;

    /**
     * @brief Checks if the provided resource can be loaded.
     *
     * @param[in] resource Resource to check.
     *
     * @return True if the loader can handle the resource, false otherwise.
     */
    [[nodiscard]] bool canLoadResource(const Resource& resource) const;

    /**
     * @brief Loads the resource.
     *
     * @param[in,out] resource Resource to be loaded.
     *
     * @return True if the resource was successfully loaded, false otherwise.
     */
    virtual bool loadResource(Resource& resource) const = 0;

private:
    /// List of supported URI path prefixes.
    const std::vector<std::string> supportedPathPrefixes_;
};
