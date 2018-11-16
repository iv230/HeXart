cmake_minimum_required(VERSION 3.12)
project(Mod4 C)

set(CMAKE_C_STANDARD 11)

add_executable(Mod4 main.c menu/menu.c menu/menu.h features/features.h displayCSVorder.c crescentSort.c decrescentSort.c dataManager/dataManager.c dataManager/dataManager.h features/sort.c file/file.c file/file.h errors.h dataPrinter/dataPrinter.c dataPrinter/dataPrinter.h)