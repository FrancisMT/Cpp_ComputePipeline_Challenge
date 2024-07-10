#include "gtest/gtest.h"

#include "pipeline/actions/load/loaders/FileLoad.hpp"

// TODO: Due to time constraints, only one test was added to showcase the integration with GTest.
// Furthermore, the implementation of each loader is returning hardcoded mocked values instead or
// real ones, hence the values being used in the test below.
// As an improvement more tests need to be added to improve the test coverage.

/**
 * @brief Tests that the file loader is able to retrieve a file from a supported URI.
 */
TEST(FileLoaderUnitTest, imageFileIsSuccessfullyLoadedFromValidURI)
{
    // Check that we can create a valid file loader.
    const auto fileLoader = FileLoad::createFileLoad();
    ASSERT_NE(fileLoader, nullptr);

    // Create a test resource with the URI supported by the file loader.
    Resource testResource("file://");

    // Check that prior to the loading process, the resource has an unkown type and no data.
    ASSERT_EQ(testResource.getDataType(), Resource::DataType::UNKNOWN);
    ASSERT_TRUE(testResource.getData().empty());

    // Check that the load file load process is successful
    // and now the resource has an Image type and data.
    ASSERT_TRUE(fileLoader->canLoadResource(testResource));
    ASSERT_TRUE(fileLoader->loadResource(testResource));
    ASSERT_EQ(testResource.getDataType(), Resource::DataType::IMAGE);
    ASSERT_FALSE(testResource.getData().empty());
}
