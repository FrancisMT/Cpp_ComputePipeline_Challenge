#include "ProcessAction.hpp"

#include <functional>
#include <iostream>

#include "processors/DataDecompressorProcess.hpp"
#include "processors/ImageDecoderProcess.hpp"
#include "processors/JSONDeserializerProcess.hpp"

namespace {

/// Alias for the function signature used to spawn processor pointers.
using ProcessorFactory = std::function<std::unique_ptr<ProcessorBase>()>;

/**
 * \brief Creates and returns a static list of processor factories.
 *
 * Each factory consists of a function that creates an instances of a specific processor.
 *
 * \return Static list of processor factories.
 */
std::vector<ProcessorFactory>& processorFactoriesList()
{
    static std::vector<ProcessorFactory> processorFactories;
    return processorFactories;
}

/**
 * @brief Helper lambda used to populate the list of available processor factories.
 *
 * @return The number of registered processor factories.
 */
const auto registeredProcessors = []() {
    processorFactoriesList().push_back(&DataDecompressorProcess::createDataDecompressorProcess);
    processorFactoriesList().push_back(&ImageDecoderProcess::createImageDecoderProcess);
    processorFactoriesList().push_back(&JSONDeserializerProcess::createJSONDeserializerProcess);
    return processorFactoriesList().size();
}();

} // namespace

ProcessAction::ProcessAction()
{
    availableProcessors_.reserve(registeredProcessors);
    std::transform(processorFactoriesList().cbegin(),
                   processorFactoriesList().cend(),
                   std::back_inserter(availableProcessors_),
                   [](const ProcessorFactory& processorFactory) { return processorFactory(); });
}

ProcessAction::~ProcessAction()
{
    // Purposely left empty:
    // std::unique_ptr needs a complete type during object construction and destruction.
    // If the constructor or destructor is inlined (or defaulted) in the header file,
    // forward declared types will be tread as an incomplete type.
}

bool ProcessAction::handleResource(Resource& resource) const
{
    const auto viableProcessorItr
          = std::find_if(availableProcessors_.cbegin(),
                         availableProcessors_.cend(),
                         [&resource](const std::unique_ptr<ProcessorBase>& processor) {
                             return processor->canProcessResource(resource);
                         });

    return viableProcessorItr != availableProcessors_.cend()
           && (*viableProcessorItr)->processResource(resource);
}
