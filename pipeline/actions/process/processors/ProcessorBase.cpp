#include "ProcessorBase.hpp"

#include <algorithm>
#include <iostream>

ProcessorBase::ProcessorBase(const std::vector<Resource::DataType>& supportedDataTypes)
    : supportedDataTypes_{supportedDataTypes}
{
}

bool ProcessorBase::canProcessResource(const Resource& resource) const
{
    return std::any_of(supportedDataTypes_.cbegin(),
                       supportedDataTypes_.cend(),
                       [resourceDataType = resource.getDataType()](const auto& dataType) {
                           return resourceDataType == dataType;
                       });
}
