#include "../../../../include/lexer/lexers/types/lex_int.h"

#include <stdlib.h>

void lex_int(tokens **tks, double number)
{
    int *int_number = malloc(sizeof(int));
    *int_number = (int)number;
    add_token(tks, TOKEN_INT, int_number);
}