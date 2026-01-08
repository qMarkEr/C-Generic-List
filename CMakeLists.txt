cmake_minimum_required(VERSION 3.10)

project(list)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_library(list STATIC
    src/list.c
)

target_include_directories(list
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

install(TARGETS list
    ARCHIVE DESTINATION lib
)

install(DIRECTORY include/
    DESTINATION include
)