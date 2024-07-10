#include "JSONDeserializerProcess.hpp"

#include <iostream>

namespace {
constexpr auto SUPPORTED_TYPE{Resource::DataType::JSON};
} // namespace

JSONDeserializerProcess::JSONDeserializerProcess()
    : ProcessorBase({SUPPORTED_TYPE})
{
}

std::unique_ptr<ProcessorBase> JSONDeserializerProcess::createJSONDeserializerProcess()
{
    // Sadly std::make_unique needs to directly call the constructor to create an instance,
    // but it cannot do so if the constructor is private.
    return std::unique_ptr<JSONDeserializerProcess>(new JSONDeserializerProcess());
}

bool JSONDeserializerProcess::processResource(Resource& resource) const
{
    // TODO: Add the JSON deserialization logic here.
    // For now, we simply return dummy deserialized data.

    Resource::ByteArray dummyData;
    for (int i = 0; i < 8; ++i) {
        dummyData.push_back(static_cast<std::byte>(i));
    }

    resource.setData(dummyData);

    return true;
}
