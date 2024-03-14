#include "../../../include/lexer/lexers/lex_null.h"

#include <string.h>

bool lex_null(Tokens **tks, char **code)
{
    if (strncmp(*code, "Null", 4) == 0) {
        add_token(tks, TOKEN_NULL, "Null");
        (*code) += 4;
        return true;
    }

    return false;
}