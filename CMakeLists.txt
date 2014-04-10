cmake_minimum_required(VERSION 2.6)

project (shpritz)

#set(CMAKE_CXX_COMPILER clang++)
#set(CMAKE_CXX_FLAGS "-std=c++11 -stdlib=libc++ ${CMAKE_CXX_FLAGS}")

#find_package(Boost COMPONENTS iostreams REQUIRED)
#find_package(ZLIB REQUIRED)
#find_package(LibClang REQUIRED)
#find_package(BerkeleyDB REQUIRED)

if(DEBUG)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")
endif(DEBUG)

include_directories(
    SYSTEM
    ${CMAKE_CURRENT_SOURCE_DIR}
#    ${Boost_INCLUDE_DIRS}
#    ${ZLIB_INCLUDE_DIRS}
#    ${LibClang_INCLUDE_DIRS}
#    ${DB_INCLUDE_DIRS}
)

#add_library(common STATIC clic_parser.cpp clic_printer.cpp ClicDb.cpp)

#add_executable(clic_clear clic_clear.cpp)
#target_link_libraries(clic_clear
#    common
#    ${DB_LIBRARIES}
#)

#add_executable(clic_add clic_add.cpp)
#target_link_libraries(clic_add
#    common
#    ${Boost_LIBRARIES}
#    ${ZLIB_LIBRARIES}
#    ${DB_LIBRARIES}
#    ${LibClang_LIBRARIES}
#)
#
#add_executable(clic_rm clic_rm.cpp)
#target_link_libraries(clic_rm
#    common
#    ${Boost_LIBRARIES}
#    ${ZLIB_LIBRARIES}
#    ${DB_LIBRARIES}
#)
#
#add_executable(indexer main.cpp)
#target_link_libraries(indexer common)
#

add_subdirectory(src)
