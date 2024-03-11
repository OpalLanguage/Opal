cmake_minimum_required(VERSION 3.25)
project(Opal C)

set(CMAKE_C_STANDARD 23)

add_executable(Opal
        src/main.c
        src/console.c
        src/file_loader.c
        src/perf_test.c

        src/lexer/lexer.c
        src/lexer/utils.c
        src/lexer/lexers/lex_char.c
        src/lexer/lexers/lex_string.c
        src/lexer/lexers/lex_int.c
        src/lexer/lexers/lex_float.c
        src/lexer/lexers/lex_null.c
        src/lexer/lexers/lex_boolean.c
        src/lexer/lexers/lex_control_flow.c
        src/lexer/lexers/lex_declaration.c
        src/lexer/lexers/lex_misc.c
        src/lexer/lexers/lex_comment.c

        src/parser/parser.c
        src/parser/parsers/parse_switch.c
        src/parser/parsers/parse_for.c
        src/parser/parsers/parse_while.c
        src/parser/parsers/parse_condition.c
        src/parser/parsers/parse_class.c
        src/parser/parsers/parse_function.c
        src/parser/parsers/parse_variable.c


        include/console.h
        include/file_loader.h
        include/perf_test.h

        include/lexer/lexer.h
        include/lexer/utils.h
        include/lexer/lexers/lex_boolean.h
        include/lexer/lexers/lex_char.h
        include/lexer/lexers/lex_float.h
        include/lexer/lexers/lex_int.h
        include/lexer/lexers/lex_null.h
        include/lexer/lexers/lex_string.h
        include/lexer/lexers/lex_control_flow.h
        include/lexer/lexers/lex_declaration.h
        include/lexer/lexers/lex_misc.h
        include/lexer/lexers/lex_comment.h

        include/parser/parser.h
        include/parser/parsers/parse_variable.h
        include/parser/parsers/parse_for.h
        include/parser/parsers/parse_while.h
        include/parser/parsers/parse_switch.h
        include/parser/parsers/parse_condition.h
        include/parser/parsers/parse_function.h
        include/parser/parsers/parse_class.h )