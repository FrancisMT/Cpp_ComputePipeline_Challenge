#include "DataDecompressorProcess.hpp"

#include <iostream>

namespace {
constexpr auto SUPPORTED_TYPE{Resource::DataType::COMPRESSED};
} // namespace

DataDecompressorProcess::DataDecompressorProcess()
    : ProcessorBase({SUPPORTED_TYPE})
{
}

std::unique_ptr<ProcessorBase> DataDecompressorProcess::createDataDecompressorProcess()
{
    // Sadly std::make_unique needs to directly call the constructor to create an instance,
    // but it cannot do so if the constructor is private.
    return std::unique_ptr<DataDecompressorProcess>(new DataDecompressorProcess());
}

bool DataDecompressorProcess::processResource(Resource& resource) const
{
    // TODO: Add the decompress logic here.
    // For now, we simply return dummy decompressed data.

    Resource::ByteArray dummyData;
    for (int i = 0; i < 8; ++i) {
        dummyData.push_back(static_cast<std::byte>(i));
    }

    resource.setData(dummyData);

    return true;
}
