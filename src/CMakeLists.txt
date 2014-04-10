cmake_minimum_required(VERSION 2.8)

find_package(Curses REQUIRED)

file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

include_directories(CURSES_INCLUDE_DIR)

add_executable(shpritz ${SOURCES})

target_link_libraries(shpritz ${CURSES_LIBRARIES})
