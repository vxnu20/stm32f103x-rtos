set(FREERTOS_PATH ${CMAKE_SOURCE_DIR}/external/freertos)
set(FREERTOS_HEAP "4" CACHE STRING "" FORCE)
set(FREERTOS_PORT "GCC_ARM_CM3" CACHE STRING "" FORCE)

add_library(freertos_config INTERFACE)
target_include_directories(freertos_config SYSTEM
    INTERFACE
        ${CMAKE_SOURCE_DIR}/include
)
target_compile_definitions(freertos_config INTERFACE
    projCOVERAGE_TEST=0
)