cmake_minimum_required(VERSION 3.16)
project(ds)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-Wall -Wextra -Wpedantic -Werror")
set(CMAKE_C_FLAGS_DEBUG "-g3")
set(CMAKE_C_FLAGS_RELEASE "-O3")
set(CMAKE_C_CPPCHECK "cppcheck")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -Werror")
set(CMAKE_CXX_FLAGS_DEBUG "-g3")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_CXX_CPPCHECK "cppcheck")

find_package(GTest REQUIRED)

include_directories("include")
link_directories(${CMAKE_CURRENT_BINARY_DIR})

file(GLOB srcs "src/*.c")
add_library(ds ${srcs})

file(GLOB tests "tests/*.cpp")
add_executable(ds-tests ${srcs} ${tests})
target_link_libraries(ds-tests ds ${GTEST_BOTH_LIBRARIES})
