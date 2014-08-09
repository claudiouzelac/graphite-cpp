cmake_minimum_required(VERSION 2.8.8 FATAL_ERROR)
project (graphite-cpp)

set(LIBPREFIX "${CMAKE_STATIC_LIBRARY_PREFIX}")
set(LIBSUFFIX "${CMAKE_STATIC_LIBRARY_SUFFIX}")
set(Graphite_VERSION_MAJOR 1)
set(Graphite_VERSION_MINOR 0)
set(Boost_FIND_REQUIRED TRUE)
set(Boost_FIND_QUIETLY TRUE)
set(Boost_DEBUG TRUE)
set(Boost_USE_MULTITHREADED TRUE)
set(CMAKE_VERBOSE_MAKEFILE on)

find_package(Boost 1.55 REQUIRED system)

add_definitions (-DBoost_USE_STATIC_LIBS=ON)
add_subdirectory(src)
