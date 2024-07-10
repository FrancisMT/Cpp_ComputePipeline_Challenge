#pragma once

#include <memory>
#include <vector>

#include "Resource.hpp"
#include "actions/ActionInterface.hpp"

/**
 * @brief The Pipeline class manages a sequence of actions that are executed on a given Resource.
 *
 * Actions are added to the pipeline in a specific order and the pipeline is executed as a
 * sequential finite-state-machine.
 *
 * Each action will handle the provided resource and, if successful,
 * will feed the handled resource (now with updated data), to the nex action in the sequence.
 */
class Pipeline
{
public:
    /**
     * @brief Default constructor.
     */
    Pipeline() = default;

    /**
     * @brief Default destructor.
     */
    ~Pipeline() = default;

    /**
     * @brief Adds an action to the pipeline.
     *
     * @param[in] action Pointer to the action to be added.
     */
    void addAction(std::unique_ptr<ActionInterface>&& action);

    /**
     * @brief Processes the provided resource by sequentially executing each action in the pipeline.
     *
     * @param[in,out] resource Resource to be processed by the pipeline.
     *
     * @return True if all actions succeeded in processing the resource, false otherwise.
     */
    bool execute(Resource& resource) const;

private:
    /// Container where the sequential actions of the pipeline are stored.
    std::vector<std::unique_ptr<ActionInterface>> pipelineActions_;
};
