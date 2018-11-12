cmake_minimum_required(VERSION 3.12)
project(CSVLibraryTest C)

set(CMAKE_C_STANDARD 11)

add_executable(CSVLibraryTest main.c features/reader.c features/writer.c features/reseter.c features/remover.c features/features.h features/csv.c)