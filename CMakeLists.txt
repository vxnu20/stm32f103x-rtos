cmake_minimum_required(VERSION 4.0)

# project settings
project(stm32f103x-base C CXX ASM)
#set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

file(GLOB_RECURSE APP_SOURCES "${CMAKE_SOURCE_DIR}/src/*.c")
file(GLOB STARTUP_SOURCES "${CMAKE_SOURCE_DIR}/startup/*.c")

# free rtos config
include(tools/cmake/freertos.cmake)
add_subdirectory(${FREERTOS_PATH})

# stm32f103x driver
add_subdirectory(drivers/stm32f103x-driver)

# Executable target (uses project name automatically)
add_executable(${PROJECT_NAME}
    ${APP_SOURCES}
    ${STARTUP_SOURCES}
)

# Common compiler flags
target_compile_options(${PROJECT_NAME} PRIVATE
    -mcpu=cortex-m3
    -mthumb
    -g
)
target_compile_options(freertos_kernel PRIVATE
    -mcpu=cortex-m3
    -mthumb
    -g
)

target_compile_options(freertos_config INTERFACE
    -mcpu=cortex-m3
    -mthumb
    -g
)

# Linker script
set(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/ld/linker.ld)

# Linker flags
target_link_options(${PROJECT_NAME} PRIVATE
    -T${LINKER_SCRIPT}
    -mcpu=cortex-m3
    -nostartfiles
    -Wl,--gc-sections
    --specs=nano.specs
)

# Project include headers
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/include/freertos
    ${CMAKE_SOURCE_DIR}/include/mcu
)

target_link_libraries(${PROJECT_NAME} PRIVATE stm32f103x_driver freertos_kernel freertos_config)

# Explicitly set output ELF name (otherwise CMake may add extra suffixes)
set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_NAME "${PROJECT_NAME}"
    SUFFIX ".elf"
)