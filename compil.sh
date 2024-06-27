#!/usr/bin/bash

# Capture the output of sdl2-config commands
SDL2_CFLAGS=$(sdl2-config --cflags)
SDL2_LIBS="$(sdl2-config --libs) -lSDL2_ttf"

# Compile the program
gcc ./src/*.c $SDL2_CFLAGS $SDL2_LIBS -Wall -Wextra -Werror -pedantic -std=c11 -o myapp -lm -lSDL2 -lSDL2_image -lSDL2_ttf

