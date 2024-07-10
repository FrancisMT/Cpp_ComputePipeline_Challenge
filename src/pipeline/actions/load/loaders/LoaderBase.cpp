#include "LoaderBase.hpp"

#include <algorithm>

LoaderBase::LoaderBase(const std::vector<std::string>& supportedPathPrefixes)
    : supportedPathPrefixes_{supportedPathPrefixes}
{
}

bool LoaderBase::canLoadResource(const Resource& resource) const
{
    return std::any_of(supportedPathPrefixes_.cbegin(),
                       supportedPathPrefixes_.cend(),
                       [resourceURI = resource.getDataUri()](const std::string& prefix) {
                           return resourceURI.starts_with(prefix);
                       });
}
