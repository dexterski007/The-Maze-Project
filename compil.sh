#!/usr/bin/bash
# Compile the program
# shellcheck disable=SC2046

gcc ./src/*.c $(sdl2-config --cflags) $(sdl2-config --libs) -Wall -Wextra -Werror -pedantic -std=c11 -o maze -lm -lSDL2 -lSDL2_image -lSDL2_ttf
