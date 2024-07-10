#pragma once

#include <memory>

#include "pipeline/actions/ActionInterface.hpp"

/**
 * @brief Processes resources using the available processors for specific resource types.
 */
class ProcessAction final : public ActionInterface
{
public:
    /**
     * @brief Constructor that makes the available processors
     * ready to be used for processing resources.
     */
    ProcessAction();

    /**
     * Class destructor.
     */
    ~ProcessAction();

    /**
     * @brief Attempts to process the given resource using one of the available processors.
     *
     * @param[in,out] resource Resource to process.
     *
     * @return True if the resource was successfully processed, false otherwise.
     */
    bool handleResource(Resource& resource) const override;

private:
    /// Container holding exclusive ownership pointers of all the available processors.
    std::vector<std::unique_ptr<class ProcessorBase>> availableProcessors_;
};
