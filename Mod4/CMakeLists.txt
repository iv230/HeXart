cmake_minimum_required(VERSION 3.12)
project(Mod4 C)

set(CMAKE_C_STANDARD 11)

add_executable(Mod4 main.c menu.c menu.h actions.c actions.h data.c data.h displayCSVorder.c crescentSort.c decrescentSort.c)