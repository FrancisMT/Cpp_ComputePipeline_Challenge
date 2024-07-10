#pragma once

#include <memory>

#include "LoaderBase.hpp"

/**
 * @brief Loads resources from a file path .
 */
class FileLoad final : public LoaderBase
{
public:
    /**
     * \brief Class destructor.
     */
    ~FileLoad() override = default;

    /**
     * \brief Create a pointer to an File Loader.
     *
     * \return An FileLoad pointer with exclusive ownership.
     */
    static std::unique_ptr<LoaderBase> createFileLoad();

    /**
     * @brief Loads the resource from a file path.
     *
     * @param[in,out] resource Resource to be loaded.
     *
     * @return True if the resource was successfully loaded, false otherwise.
     */
    bool loadResource(Resource& resource) const override;

private:
    /**
     * @brief Private constructor.
     */
    FileLoad();
};
