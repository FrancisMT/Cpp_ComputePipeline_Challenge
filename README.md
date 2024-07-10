# Compute Pipeline Challenge
C++ implementation of the ComputePipeline coding challenge.

## Implementation Details
This project demonstrates a pipeline architecture in C++ for handling various types of resources, from data ingestion to additional processing depending on the data type.

The pipeline sequentially handles resources through a series of actions, such as loading and processing data, using a modular and extensible design. 
This "plug&play" architecture future proofs the need to:
* add new loaders for other URIs;
* add new data processors for other data types;
* add entirely new actions (e.g. image thresholding, uploading data to AWS, compressing data, etc).

_Note: The currently available loader and processor actions output only dummy data mainly for testing purposes._

## Tools
* C++20
* CMake
* GTest

## Build
```
❯ mkdir build && cd build
❯ cmake ..
❯ cmake --build .
```

## Usage
```
❯ ./ComputePipeline-Challenge
Pipeline finished all operations on the provided resource successfully
```

## Documentation
This project is configured to generate documentation using Doxygen.

To access it, open the _build/doxygen/html/index.html_ file

## Coverage
CMake already takes care of automatically integrating Google test into the project, so there is no need to manually install and configure it.

### Run tests
```
❯ ctest
    Start 1: FileLoaderUnitTest.imageFileIsSuccessfullyLoadedFromValidURI
1/2 Test #1: FileLoaderUnitTest.imageFileIsSuccessfullyLoadedFromValidURI ...   Passed    0.00 sec
    Start 2: PipelineIntegrationTest.pipelineCorrectlyProcessesInput
2/2 Test #2: PipelineIntegrationTest.pipelineCorrectlyProcessesInput ........   Passed    0.00 sec

100% tests passed, 0 tests failed out of 2

Total Test time (real) =   0.00 sec
```
