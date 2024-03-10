#include "../../../include/lexer/lexers/lex_char.h"

#include <stdlib.h>

void lex_char(tokens **tks, char **code)
{
    (*code)++;
    char *c = malloc(sizeof(char));
    *c = **code;
    add_token(tks, TOKEN_CHAR, c);
    (*code) += 2;
}