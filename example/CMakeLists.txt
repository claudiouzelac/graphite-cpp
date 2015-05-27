include_directories(../inc)
add_executable(graphite-cpp-example main.cpp)
target_link_libraries(graphite-cpp-example
                      graphite-cpp
                      )