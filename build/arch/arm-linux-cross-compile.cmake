#-DCMAKE_TOOLCHAIN_FILE=./build/arch/arm-linux-cross-compile.cmake
#-DCROSSCOMPILING=1
#-DCMAKE_INSTALL_PREFIX=/home/wjxh/linux/tftp

set(CMAKE_SYSTEM_PROCESSOR arm)

set (CMAKE_C_COMPILER arm-linux-gnueabihf-gcc)
set (CMAKE_CXX_COMPILER arm-linux-gnueabihf-g++)
set (CMAKE_ASM_COMPILER arm-linux-gnueabihf-as)

set (CMAKE_FIND_ROOT_PATH_MODE_LIBRARY NEVER)
set (CMAKE_FIND_ROOT_PATH_MODE_INCLUDE NEVER)
set (CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)