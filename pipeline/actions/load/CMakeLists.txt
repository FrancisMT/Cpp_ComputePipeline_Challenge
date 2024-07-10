project(LoadAction)

add_library(${PROJECT_NAME} STATIC
    LoadAction.cpp
    loaders/LoaderBase.cpp
    loaders/AppBundleLoad.cpp
    loaders/FileLoad.cpp
    loaders/URLLoad.cpp
)
