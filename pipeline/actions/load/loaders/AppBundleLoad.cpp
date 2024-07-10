#include "AppBundleLoad.hpp"

#include <iostream>
#include <string>

namespace {
constexpr auto SUPPORTED_PATH_PREFIX{"bundle://"};
} // namespace

AppBundleLoad::AppBundleLoad()
    : LoaderBase({SUPPORTED_PATH_PREFIX})
{
}

std::unique_ptr<LoaderBase> AppBundleLoad::createAppBundleLoad()
{
    // Sadly std::make_unique needs to directly call the constructor to create an instance,
    // but it cannot do so if the constructor is private
    return std::unique_ptr<AppBundleLoad>(new AppBundleLoad());
}

bool AppBundleLoad::loadResource(Resource& resource) const
{
    // TODO: Add the loading logic here.
    // For now, we simply return dummy compressed data.

    Resource::ByteArray dummyData;
    for (int i = 0; i < 8; ++i) {
        dummyData.push_back(static_cast<std::byte>(i));
    }

    resource.setData(dummyData);
    resource.setDataType(Resource::DataType::COMPRESSED);

    return true;
}
