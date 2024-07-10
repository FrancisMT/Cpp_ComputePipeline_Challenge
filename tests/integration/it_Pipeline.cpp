#include "gtest/gtest.h"

#include "pipeline/Pipeline.hpp"
#include "pipeline/Resource.hpp"
#include "pipeline/actions/load/LoadAction.hpp"
#include "pipeline/actions/process/ProcessAction.hpp"

/**
 * @brief Tests that the pipeline is able to perform actions to a provided resource
 * in the expected order.
 */
TEST(PipelineIntegrationTest, pipelineCorrectlyProcessesInput)
{
    // Create a pipeline and add actions to it in the desirable order.
    Pipeline pipeline;
    pipeline.addAction(std::make_unique<LoadAction>());
    pipeline.addAction(std::make_unique<ProcessAction>());

    // Create the initial resource to feed to the pipeline.
    constexpr auto testURI{"http://"};
    Resource resource(testURI);
    ASSERT_EQ(resource.getDataType(), Resource::DataType::UNKNOWN);
    ASSERT_TRUE(resource.getData().empty());

    // Start the resource handling in the pipeline and check that it was successful.
    const auto executionSuccessful = pipeline.execute(resource);
    ASSERT_TRUE(executionSuccessful);

    // Check that after the pipeline has finished handling the resource, it has the expected data.
    ASSERT_EQ(resource.getDataUri(), testURI);
    ASSERT_EQ(resource.getDataType(), Resource::DataType::JSON);
    ASSERT_FALSE(resource.getData().empty());
}
