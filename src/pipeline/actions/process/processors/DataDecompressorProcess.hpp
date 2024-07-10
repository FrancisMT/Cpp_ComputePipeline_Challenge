#pragma once

#include <memory>

#include "ProcessorBase.hpp"

/**
 * @brief Decompresses the data from a compressed resource.
 */
class DataDecompressorProcess final : public ProcessorBase
{
public:
    /**
     * \brief Class destructor.
     */
    ~DataDecompressorProcess() override = default;

    /**
     * \brief Create a pointer to a Data Decompressor Process.
     *
     * \return An DataDecompressorProcess pointer with exclusive ownership.
     */
    static std::unique_ptr<ProcessorBase> createDataDecompressorProcess();

    /**
     * @brief Decompresses the data from a compressed resource.
     *
     * @param[in,out] resource Resource whose data is to be decompressed.
     *
     * @return True if the resource's data was successfully decompressed, false otherwise.
     */
    bool processResource(Resource& resource) const override;

private:
    /**
     * @brief Private constructor.
     */
    DataDecompressorProcess();
};
