#include "Pipeline.hpp"

#include <iostream>

void Pipeline::addAction(std::unique_ptr<ActionInterface>&& action)
{

#ifdef DEBUG_BUILD
    std::cout << "Adding a new action\n";
#endif

    // Even though action is an r-value reference,
    // we can't forget that named values (such as function parameters)
    // are always evaluated as l-values (even those declared as r-value references).
    // Therefore, we need to call std::move on the action object (making it a true r-value)
    // to ensure that we are in fact moving the ownership of the pointer to the
    // pipelineActions_ container (otherwise "kaboom!").
    pipelineActions_.emplace_back(std::move(action));
}

bool Pipeline::execute(Resource& resource) const
{
    for (const auto& action : pipelineActions_) {
        if (!action->handleResource(resource)) {
            // TODO: Log description of the action that failed to handle the resource
            // and also log information about the resource itself.
            std::cerr << "Action failed to process resource\n";
            return false;
        }
    }

#ifdef DEBUG_BUILD
    std::cout << "No more actions left in the pipeline\n";
#endif

    return true;
}
