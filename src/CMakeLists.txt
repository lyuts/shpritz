cmake_minimum_required(VERSION 2.8)

#include(FindPackageHandleStandardArgs)

find_package(Curses REQUIRED)

find_library(MAGIC_LIBRARY NAMES magic PATHS /usr/local/lib /usr/lib)

if(NOT MAGIC_LIBRARY)
    message(SEND_ERROR "Unable to find magic library.")
endif(NOT MAGIC_LIBRARY)

find_library(SIGCXX_LIBRARY NAMES sigc-2.0 PATHS /usr/local/lib /usr/lib)
if(NOT SIGCXX_LIBRARY)
    message(SEND_ERROR "Unable to find libsigc++ library.")
endif(NOT SIGCXX_LIBRARY)

include_directories(${CURSES_INCLUDE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB SRC "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
file(GLOB READER_SRC "${CMAKE_CURRENT_SOURCE_DIR}/reader/*.cpp")
file(GLOB UI_SRC "${CMAKE_CURRENT_SOURCE_DIR}/ui/*.cpp")
add_executable(shpritz ${SRC} ${READER_SRC} ${UI_SRC})

target_link_libraries(shpritz
    ${CURSES_LIBRARIES}
    ${MAGIC_LIBRARY}
    ${SIGCXX_LIBRARY}
    )

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/config.h.in
    ${PROJECT_BINARY_DIR}/config.h
    )
