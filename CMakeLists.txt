cmake_minimum_required(VERSION 3.14)
project(parser)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_library(parser_core
    src/Nodo.cpp
    src/Tokenizer.cpp
    src/LRParser.cpp
    src/App.cpp
)

target_include_directories(parser_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(parser src/main.cpp)
target_link_libraries(parser PRIVATE parser_core)


