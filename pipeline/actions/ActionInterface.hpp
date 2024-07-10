#pragma once

#include "pipeline/Resource.hpp"

/**
 * @brief Abstract interface for actions that can be applied to a resource.
 *
 * Derive classes must provide an implementation for the handleResource method
 * in order to define the action's behavior.
 */
class ActionInterface
{
public:
    /**
     * @brief Virtual destructor.
     *
     * Ensures that derived class destructors are properly called.
     */
    virtual ~ActionInterface() = default;

    /**
     * @brief Handles the provided resource by performing the action's specific logic.
     *
     * @param[in,out] resource Resource to be handled.
     *
     * @return True if the action successfully handled the resource, false otherwise.
     */
    virtual bool handleResource(Resource& resource) const = 0;
};