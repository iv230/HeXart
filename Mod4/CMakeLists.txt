cmake_minimum_required(VERSION 3.12)
project(Mod4 C)

set(CMAKE_C_STANDARD 11)

add_executable(Mod4 dataManager/dataManager.c dataManager/dataManager.h dataPrinter/dataPrinter.c dataPrinter/dataPrinter.h features/search.c features/sort.c features/features.h file/file.c file/file.h main.c errors.h menu/menu.c menu/menu.h)