cmake_minimum_required(VERSION 3.5)
project(xinci)

include_directories(xinci)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


set(HEADER_FIES
        src/args.h
        src/dictionary.h
        src/extractor.h
        src/indexer.h
        src/model.h
        src/selector.h
        src/utils.h
        )

set(SOURCE_FILES
        src/main.cpp
        src/args.cpp
        src/dictionary.cpp
        src/indexer.cpp
        src/model.cpp
        src/selector.cpp
        src/utils.cpp
        src/extractor.cpp
        )

add_executable(xinci ${SOURCE_FILES})