cmake_minimum_required(VERSION 2.6)

project (shpritz)

set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

if(DEBUG)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0")
endif(DEBUG)

include_directories(
    SYSTEM
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_subdirectory(src)
