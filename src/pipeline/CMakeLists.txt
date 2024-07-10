project(Pipeline)

add_subdirectory(actions)

add_library(${PROJECT_NAME} STATIC
    Pipeline.cpp
    Resource.cpp
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE LoadAction
    PRIVATE ProcessAction
)
