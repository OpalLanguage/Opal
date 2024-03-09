cmake_minimum_required(VERSION 3.25)
project(Opal C)

set(CMAKE_C_STANDARD 23)

add_executable(Opal
        src/main.c
        src/console.c

        src/lexer/lexer.c
        src/lexer/lexers/types/lex_char.c
        src/lexer/lexers/types/lex_string.c
        src/lexer/lexers/types/lex_int.c
        src/lexer/lexers/types/lex_float.c
        src/lexer/lexers/lex_variable.c
        src/lexer/lexers/types/lex_null.c
        src/lexer/lexers/types/lex_byte.c
        src/lexer/lexers/types/lex_boolean.c


        include/console.h

        include/lexer/lexer.h
        include/lexer/lexers/types/lex_boolean.h
        include/lexer/lexers/types/lex_byte.h
        include/lexer/lexers/types/lex_char.h
        include/lexer/lexers/types/lex_float.h
        include/lexer/lexers/types/lex_int.h
        include/lexer/lexers/types/lex_null.h
        include/lexer/lexers/types/lex_string.h
        include/lexer/lexers/lex_variable.h include/lexer/lexers/types.h)
