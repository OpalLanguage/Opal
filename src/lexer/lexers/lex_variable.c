#include "../../../include/lexer/lexers/lex_variable.h"
#include "../../../include/lexer/lexers/types.h"

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void lex_variable(tokens **tks, char **code)
{
    char *name = calloc(50, sizeof(char));
    char *start = name;

    while (**code != ' ' && **code != '\0' && **code != '=') {
        *name = **code;
        name++;
        (*code)++;
    }
    *name = '\0';

    add_token(tks, TOKEN_VARIABLE_NAME, start);

    while (isspace(**code)) (*code)++;

    if (**code != '=') {
        printf("You need = to define a variable for variable: %s\n", start);
        exit(1);
    }

    add_token(tks, TOKEN_ASSIGN, *code);
    (*code)++;
    while (isspace(**code)) (*code)++;

    if (isdigit(**code)) {
        char *end;
        double number = strtod(*code, &end);

        if (*code == end) {
            printf("You need to specify a valid number for variable: %s\n", start);
            exit(1);
        }

        bool isFloat = (end != *code && (strchr(*code, '.') != NULL || strchr(*code, 'e') != NULL || strchr(*code, 'E') != NULL));

        if (isFloat) {
            lex_float(tks, number);
        }
        else {
            int intValue = (int)number;
            lex_int(tks, intValue);
        }
        *code = end;
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