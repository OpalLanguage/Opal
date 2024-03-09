#include "../../../include/lexer/lexers/lex_variable.h"
#include "../../../include/lexer/lexers/types.h"

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void lex_variable(tokens **tks, char **code)
{
    char *name = calloc(50, sizeof(char));
    char *start = name;

    while (**code != ' ' && **code != '\0') {
        *name = **code;
        name++;
        (*code)++;
    }

    *name = '\0';
    add_token(tks, TOKEN_VARIABLE_NAME, start);
    (*code)++;

    if (**code != '=') {
        printf("You need = to define a variable for variable: %s\n", start);
        exit(1);
    }

    add_token(tks, TOKEN_ASSIGN, *code);
    (*code) += 2;

    if (isdigit(**code)) {
        lex_int(tks, code);
        return;
    }

    if (isalpha(**code)) {
        if (!lex_boolean(tks, code) && !lex_null(tks, code)) {
            printf("You need a valid value for variable: %s\n", start);
            exit(1);
        }

        return;
    }

    switch (**code) {
        case '\'': {
            lex_char(tks, code);
            return;
        }
        case '\"': {
            lex_string(tks, code);
            return;
        }

        default:
            printf("You need a valid value for variable: %s\n", start);
            exit(1);
    }
}