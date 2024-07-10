#pragma once

#include <vector>

#include "pipeline/Resource.hpp"

/**
 * @brief Base class for resource processors that:
 * - checks if a given resource can be processes based on a data type;
 * - defines an interface for processing resources;
 *
 * Derive classes must provide an implementation for the processResource method
 * in order to define how the resource should be processed.
 */
class ProcessorBase
{
public:
    /**
     * @brief Constructor that takes a list of resource data types that can be handled.
     *
     * @param[in] supportedDataTypes Vector of resource data types.
     */
    ProcessorBase(const std::vector<Resource::DataType>& supportedDataTypes);

    /**
     * @brief Virtual destructor.
     *
     * Ensures that derived class destructors are properly called.
     */
    virtual ~ProcessorBase() = default;

    /**
     * @brief Checks if the provided resource can be processed.
     *
     * @param[in] resource Resource to check.
     *
     * @return True if the processor can handle the resource, false otherwise.
     */
    [[nodiscard]] bool canProcessResource(const Resource& resource) const;

    /**
     * @brief Processes the resource.
     *
     * @param[in,out] resource Resource to be processed.
     *
     * @return True if the resource was successfully processed, false otherwise.
     */
    virtual bool processResource(Resource& resource) const = 0;

private:
    /// List of supported resource data types.
    const std::vector<Resource::DataType> supportedDataTypes_;
};
