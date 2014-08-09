include_directories(../inc ${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_library(graphite-cpp graphite_reporter.cpp graphite_connector.cpp)

target_link_libraries(graphite-cpp
        ${Boost_LIBRARIES}
)
