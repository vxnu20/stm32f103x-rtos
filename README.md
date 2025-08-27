| Use    | Command |
| -------- | ------- |
| Generate cmake config  | `cmake -B build -DCMAKE_TOOLCHAIN_FILE=arm-gcc-toolchain.cmake`  |
| build | `cmake --build build`     |
| flash    |  `openocd -f interface/stlink-v2.cfg -f target/stm32f1x.cfg -c "program build/stm32f103x_template.elf verify reset exit"`   |

