#include "../../../include/lexer/lexers/lex_float.h"

#include <stdlib.h>

void lex_float(Tokens **tks, double number)
{
    double *float_number = malloc(sizeof(double));
    *float_number = number;
    add_token(tks, TOKEN_FLOAT, float_number);
}