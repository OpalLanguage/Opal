#include "../../../include/lexer/lexers/lex_string.h"

#include <stdlib.h>

void lex_string(tokens **tks, char **code)
{
    char *string = calloc(50, sizeof(char));
    char *start = string;

    (*code)++;
    while (**code != '\"' && **code != '\0') {
        *string = **code;
        string++;
        (*code)++;
    }
    *string = '\0';
    add_token(tks, TOKEN_STRING, start);
    (*code)++;
}