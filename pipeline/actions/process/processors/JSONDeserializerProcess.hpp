#pragma once

#include <memory>

#include "ProcessorBase.hpp"

/**
 * @brief Deserializes the data from a JSON resource.
 */
class JSONDeserializerProcess final : public ProcessorBase
{
public:
    /**
     * \brief Class destructor.
     */
    ~JSONDeserializerProcess() override = default;

    /**
     * \brief Create a pointer to a JSON Deserializer Process.
     *
     * \return An JSONDeserializerProcess pointer with exclusive ownership.
     */
    static std::unique_ptr<ProcessorBase> createJSONDeserializerProcess();

    /**
     * @brief Decodes the data from a JSON resource.
     *
     * @param[in,out] resource Resource whose data is to be deserialized.
     *
     * @return True if the resource's data was successfully deserialized, false otherwise.
     */
    bool processResource(Resource& resource) const override;

private:
    /**
     * @brief Private constructor.
     */
    JSONDeserializerProcess();
};
