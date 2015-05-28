set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost COMPONENTS system)
include_directories(../inc ${Boost_INCLUDE_DIR})

set(LIB_NAME graphite-cpp)
file(GLOB SOURCES
    "*.cpp"
)

link_directories(${Boost_LIBRARY_DIR})
add_library(${LIB_NAME} ${SOURCES})

target_link_libraries(${LIB_NAME}
        ${Boost_LIBRARIES}
)
