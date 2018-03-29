cmake_minimum_required(VERSION 3.9)
project(IZII2 C)

set(CMAKE_C_STANDARD 99)

add_executable(testarrayToBitBoards
        izii2.h
        arrayToBitBoards.c
        testarrayToBitBoards.c
        printBoard.c)