include_directories(../inc)
set(SOURCES main.cpp ../src/Connector.cpp ../src/PeriodicPublisher.cpp ../src/Reporter.cpp)
add_executable(graphite-cpp-example ${SOURCES})
target_link_libraries(graphite-cpp-example
                      graphite-cpp
                      )