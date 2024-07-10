#pragma once

#include <memory>

#include "ProcessorBase.hpp"

/**
 * @brief Decodes the data from an image resource.
 */
class ImageDecoderProcess final : public ProcessorBase
{
public:
    /**
     * \brief Class destructor.
     */
    ~ImageDecoderProcess() override = default;

    /**
     * \brief Create a pointer to an Image Decoder Process.
     *
     * \return An ImageDecoderProcess pointer with exclusive ownership.
     */
    static std::unique_ptr<ProcessorBase> createImageDecoderProcess();

    /**
     * @brief Decodes the data from an image resource.
     *
     * @param[in,out] resource Resource whose data is to be decoded.
     *
     * @return True if the resource's data was successfully decoded, false otherwise.
     */
    bool processResource(Resource& resource) const override;

private:
    /**
     * @brief Private constructor.
     */
    ImageDecoderProcess();
};
