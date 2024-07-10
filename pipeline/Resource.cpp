#include "Resource.hpp"

Resource::Resource(const std::string& resourceURI)
    : type_{DataType::UNKNOWN}
    , uri_{resourceURI}
{
}

Resource::Resource(const DataType resourceType, const ByteArray& resourceData)
    : type_{resourceType}
    , data_{resourceData}
{
}

const std::string& Resource::getDataUri() const
{
    return uri_;
}

Resource::DataType Resource::getDataType() const
{
    return type_;
}

const Resource::ByteArray& Resource::getData() const
{
    return data_;
}

void Resource::setDataUri(const std::string& uri)
{
    uri_ = uri;
}

void Resource::setDataType(const Resource::DataType type)
{
    type_ = type;
}

void Resource::setData(const Resource::ByteArray& data)
{
    data_ = data;
}
