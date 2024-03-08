cmake_minimum_required(VERSION 3.25)
project(Opal C)

set(CMAKE_C_STANDARD 23)

add_executable(Opal
        src/main.c
        src/console.c
        src/lexer.c

        include/console.h
        include/lexer.h)
