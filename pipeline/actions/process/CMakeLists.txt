project(ProcessAction)

add_library(${PROJECT_NAME} STATIC
    ProcessAction.cpp
    processors/ProcessorBase.cpp
    processors/DataDecompressorProcess.cpp
    processors/ImageDecoderProcess.cpp
    processors/JSONDeserializerProcess.cpp
)
