#pragma once

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

/**
 * @brief Class that represents a generic resource with:
 * - an URI where the resource is available
 * - resource type;
 * - byte array containing the resource data;
 */
class Resource
{
public:
    /// Alias for a vector of bytes.
    using ByteArray = std::vector<std::byte>;

    /**
     * @brief Possible data types of the resource.
     */
    enum class DataType : uint8_t {
        IMAGE = 0,      // Image data
        COMPRESSED = 1, // Compressed data
        JSON = 2,       // JSON data
        UNKNOWN = 3     // Unknown  data
    };

public:
    /**
     * @brief Default constructor.
     */
    Resource() = default;

    /**
     * @brief Default destructor.
     */
    ~Resource() = default;

    /**
     * @brief Constructs a Resource with a given URI.
     *
     * @param[in] resourceURI The URI from where the resource can be fetched.
     */
    Resource(const std::string& resourceURI);

    /**
     * @brief Constructs a Resource with a given type and data.
     *
     * @param[in] resourceType The type of the resource.
     * @param[in] resourceData The byte array containing the data of the resource.
     */
    Resource(const DataType resourceType, const ByteArray& resourceData);

    /**
     * @brief Gets the URI of the resource.
     *
     * @return The URI from where the resource can be fetched.
     */
    const std::string& getDataUri() const;

    /**
     * @brief Gets the type of the resource's data.
     *
     * @return Resource type.
     */
    DataType getDataType() const;

    /**
     * @brief Gets the data of the resource.
     *
     * @return Byte array containing the data of the resource.
     */
    const ByteArray& getData() const;

    /**
     * @brief Sets the URI of the resource.
     *
     * @param[in] uri URI to set.
     */
    void setDataUri(const std::string& uri);

    /**
     * @brief Sets the type of the resource data.
     *
     * @param[in] type Type to set.
     */
    void setDataType(const DataType type);

    /**
     * @brief Sets the data of the resource.
     *
     * @param[in] data Data to set.
     */
    void setData(const ByteArray& data);

private:
    /// Type of the resource's data.
    DataType type_;
    /// URI from where the resource can be fetched.
    std::string uri_;
    /// Byte array containing the data of the resource.
    ByteArray data_;
};
