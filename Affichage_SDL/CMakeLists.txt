cmake_minimum_required(VERSION 3.12)
project(Affichage_SDL C)

set(CMAKE_C_STANDARD 11)

link_libraries(-lmingw32 -lSDLmain -lSDL -lSDL_image)

add_executable(Affichage_SDL main.c menu/menu.c loading/loading.c generator/generator.c utils/utils.c)