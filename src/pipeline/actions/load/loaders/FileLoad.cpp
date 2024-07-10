#include "FileLoad.hpp"

#include <iostream>
#include <string>

namespace {
constexpr auto SUPPORTED_PATH_PREFIX{"file://"};
} // namespace

FileLoad::FileLoad()
    : LoaderBase({SUPPORTED_PATH_PREFIX})
{
}

std::unique_ptr<LoaderBase> FileLoad::createFileLoad()
{
    // Sadly std::make_unique needs to directly call the constructor to create an instance,
    // but it cannot do so if the constructor is private
    return std::unique_ptr<FileLoad>(new FileLoad());
}

bool FileLoad::loadResource(Resource& resource) const
{
    // TODO: Add the loading logic here.
    // For now, we simply return an image resource with dummy data.

    Resource::ByteArray dummyData;
    for (int i = 0; i < 8; ++i) {
        dummyData.push_back(static_cast<std::byte>(i));
    }

    resource.setData(dummyData);
    resource.setDataType(Resource::DataType::IMAGE);

    return true;
}
