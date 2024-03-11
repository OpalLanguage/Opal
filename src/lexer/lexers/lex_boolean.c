#include "../../../include/lexer/lexers/lex_boolean.h"

#include <string.h>

bool lex_boolean(tokens **tks, char **code)
{
    if (strncmp(*code, "True", 4) == 0) {
        add_token(tks, TOKEN_BOOLEAN, "True");
        *code += 4;
        return true;
    }
    else if (strncmp(*code, "False", 5) == 0) {
        add_token(tks, TOKEN_BOOLEAN, "False");
        *code += 5;
        return true;
    }

    return false;
}