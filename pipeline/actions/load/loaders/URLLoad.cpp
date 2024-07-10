#include "URLLoad.hpp"

#include <iostream>
#include <string>

namespace {
const std::vector<std::string> SUPPORTED_PATH_PREFIXES{"http://", "https://"};
} // namespace

URLLoad::URLLoad()
    : LoaderBase(SUPPORTED_PATH_PREFIXES)
{
}

std::unique_ptr<LoaderBase> URLLoad::createURLLoad()
{
    // Sadly std::make_unique needs to directly call the constructor to create an instance,
    // but it cannot do so if the constructor is private
    return std::unique_ptr<URLLoad>(new URLLoad());
}

bool URLLoad::loadResource(Resource& resource) const
{
    // TODO: Add the loading logic here.
    // For now, we simply return dummy JSON data.

    Resource::ByteArray dummyData;
    for (int i = 0; i < 8; ++i) {
        dummyData.push_back(static_cast<std::byte>(i));
    }

    resource.setData(dummyData);
    resource.setDataType(Resource::DataType::JSON);

    return true;
}
