#include "../../../../include/lexer/lexers/types/lex_int.h"

#include <stdlib.h>

void lex_int(tokens **tks, char **code)
{
    int *number = malloc(sizeof(int));
    *number = strtol(*code, code, 10);
    add_token(tks, TOKEN_INT, number);
    (*code)++;
}