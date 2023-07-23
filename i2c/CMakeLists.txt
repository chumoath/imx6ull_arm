aux_source_directory(. SRC)
add_executable(i2c_exe ${SRC})

add_custom_target(i2c
        COMMAND
        cp -rfa ${CMAKE_CURRENT_SOURCE_DIR}/../bsp ${CMAKE_CURRENT_BINARY_DIR}/
        COMMAND
        cp -rfa ${CMAKE_CURRENT_SOURCE_DIR}/../i2c ${CMAKE_CURRENT_BINARY_DIR}/
        COMMAND
        cp -rfa ${CMAKE_CURRENT_SOURCE_DIR}/../imx6ul ${CMAKE_CURRENT_BINARY_DIR}/
        COMMAND
        cp -rfa ${CMAKE_CURRENT_SOURCE_DIR}/../obj ${CMAKE_CURRENT_BINARY_DIR}/
        COMMAND
        cp -fa ${CMAKE_CURRENT_BINARY_DIR}/i2c/Makefile ${CMAKE_CURRENT_BINARY_DIR}/Makefile
        COMMAND
        cp -fa ${CMAKE_CURRENT_BINARY_DIR}/i2c/imx6ul.lds ${CMAKE_CURRENT_BINARY_DIR}/imx6ul.lds
        )

add_custom_command(TARGET i2c
        # step 2
        PRE_BUILD COMMAND
        ${CMAKE_COMMAND} -E echo "compiling i2c.bin..."

        # step 3
        COMMAND
        cd ${CMAKE_CURRENT_BINARY_DIR} && make

        # step 4
        POST_BUILD COMMAND
        ${CMAKE_COMMAND} -E echo "compile i2c.bin OK"

        POST_BUILD COMMAND
        ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/i2c.bin /home/wjxh/linux/tftp
        )
