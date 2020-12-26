cmake_minimum_required(VERSION 3.19)

set(NAME rdlib)
project(${NAME})
add_compile_options(-Wall -Wextra -Werror -Wpedantic)

set(CMAKE_C_STANDARD 99)

include_directories(inc)

file(GLOB SRC CONFIGURE_DEPENDS "./inc/*.h" "./src/**/*.c" "./src/*.c")
add_library(${NAME} ${SRC})
