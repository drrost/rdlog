cmake_minimum_required(VERSION 3.19)

set(NAME rdlog)
project(${NAME})
add_compile_options(-Wall -Wextra -Werror -Wpedantic)

set(CMAKE_C_STANDARD 11)

include_directories(inc)

file(GLOB SRC CONFIGURE_DEPENDS "./inc/*.h"
        "./src/*.c"
        "./src/**/*.c"
        "./src/**/**/*.c"
        "./src/**/**/**/*.c"
        )
add_executable(${NAME} ${SRC})

# rdlib
include_directories(libs/rdlib/inc)
add_subdirectory(libs/rdlib)
target_link_libraries(${NAME} PRIVATE rdlib)

# json
include_directories(libs/json/inc)
add_subdirectory(libs/json)
target_link_libraries(${NAME} PRIVATE rdjson)

# sqlite3
target_link_libraries(${NAME} LINK_PUBLIC sqlite3)
