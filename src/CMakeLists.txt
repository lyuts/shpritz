cmake_minimum_required(VERSION 2.8)

#include(FindPackageHandleStandardArgs)

find_package(Curses REQUIRED)

find_library(MAGIC_LIBRARY NAMES magic)

#if(NOT ${MAGIC_LIBRARY})
#    message(SEND_ERROR "Unable to find magic library")
#endif(NOT ${MAGIC_LIBRARY})

include_directories(${CURSES_INCLUDE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB SRC "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
file(GLOB READER_SRC "${CMAKE_CURRENT_SOURCE_DIR}/reader/*.cpp")
add_executable(shpritz ${SRC} ${READER_SRC})

target_link_libraries(shpritz
    ${CURSES_LIBRARIES}
    ${MAGIC_LIBRARY}
    )
