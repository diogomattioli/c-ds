cmake_minimum_required(VERSION 3.16)
project(ds C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-Wall -Wextra -Wpedantic -Werror")
set(CMAKE_C_FLAGS_DEBUG "-g3")
set(CMAKE_C_FLAGS_RELEASE "-O3")

include_directories("include")
file(GLOB srcs "src/*.c")
add_library(ds ${srcs})
