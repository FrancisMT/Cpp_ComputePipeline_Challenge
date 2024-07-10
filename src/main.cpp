
#include <iostream>
#include <memory>

#include "pipeline/Pipeline.hpp"
#include "pipeline/Resource.hpp"
#include "pipeline/actions/load/LoadAction.hpp"
#include "pipeline/actions/process/ProcessAction.hpp"

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
    // A pipeline is created and specific pipeline actions are added in the desirable order of
    // execution. At the moment, the pipeline supports the following actions:
    // - loading data
    // - processing loaded data
    // TODO: as an improvement, the order of desirable actions could be loaded:
    // - At runtime-time from:
    //      - user input;
    //      - a database;
    //      - .conf file;
    // - At compile-time from:
    //      - preprocessor macros define via CMake: e.g. -DPIPELINE_ACTION_ORDER="load;process" .
    Pipeline pipeline;
    pipeline.addAction(std::make_unique<LoadAction>());
    pipeline.addAction(std::make_unique<ProcessAction>());

    // Feed a resource to the pipeline to start the data handling process.
    // TODO: improve how the initial data is acquired. For now, we use a supported URI prefix.
    constexpr auto initialResourceURI{"http://"};

    // Initialize the resource and ask the pipeline to handle it.
    Resource resource(initialResourceURI);
    const auto executionSuccessful = pipeline.execute(resource);

    std::cout << "Pipeline finished all operations on the provided resource "
              << (executionSuccessful ? "successfully" : "unsuccessfully") << "\n";

    return 0;
}
