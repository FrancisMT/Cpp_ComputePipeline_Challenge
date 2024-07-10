#include "ImageDecoderProcess.hpp"

#include <iostream>

namespace {
constexpr auto SUPPORTED_TYPE{Resource::DataType::IMAGE};
} // namespace

ImageDecoderProcess::ImageDecoderProcess()
    : ProcessorBase({SUPPORTED_TYPE})
{
}

std::unique_ptr<ProcessorBase> ImageDecoderProcess::createImageDecoderProcess()
{
    // Sadly std::make_unique needs to directly call the constructor to create an instance,
    // but it cannot do so if the constructor is private.
    return std::unique_ptr<ImageDecoderProcess>(new ImageDecoderProcess());
}

bool ImageDecoderProcess::processResource(Resource& resource) const
{
    // TODO: Add the decode logic here.
    // For now, we simply return dummy decoded data.

    Resource::ByteArray dummyData;
    for (int i = 0; i < 8; ++i) {
        dummyData.push_back(static_cast<std::byte>(i));
    }

    resource.setData(dummyData);

    return true;
}
