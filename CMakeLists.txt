cmake_minimum_required(VERSION 3.14)
project(bsp)

#enable_language(asm)

include_directories(imx6ul)

set (CURRENT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bsp)
file(GLOB BSP_DIR RELATIVE ${CURRENT_DIR} ${CURRENT_DIR}/*)

message("${BSP_DIR}")
foreach(dir ${BSP_DIR})
    include_directories(bsp/${dir})
endforeach()

add_subdirectory(i2c)
add_subdirectory(bsp)