cmake_minimum_required(VERSION 3.19)

set(NAME TestThreads)
project(${NAME})
add_compile_options(-Wall -Wextra -Werror -Wpedantic)

set(CMAKE_C_STANDARD 11)

include_directories(inc)

file(GLOB SRC CONFIGURE_DEPENDS "./inc/*.h" "./src/*.c")
add_executable(${NAME} ${SRC})

include_directories(lib/rdlib/inc)
add_subdirectory(lib/rdlib)
target_link_libraries(${NAME} PRIVATE rdlib)


