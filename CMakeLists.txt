cmake_minimum_required(VERSION 3.10)
project(gameUPH C)

set(CMAKE_C_STANDARD 99)

add_executable(gameUPH main.c src/game.c src/input.c src/render.c
        src/sprites.c
        include/vars.h
        include/function.h
        include/structs.h
        include/sprites.h
)
