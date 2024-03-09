#include "../../../../include/lexer/lexers/types/lex_boolean.h"

bool lex_boolean(tokens **tks, char **code)
{
    if (**code == 'T') {
        if (*(*code+1) == 'r' && *(*code+2) == 'u' && *(*code+3) == 'e') {
            add_token(tks, TOKEN_BOOLEAN, "True");
            (*code) += 4;
            return true;
        }
    }
    else if (**code == 'F') {
        if (*(*code+1) == 'a' && *(*code+2) == 'l' && *(*code+3) == 's' && *(*code+4) == 'e') {
            add_token(tks, TOKEN_BOOLEAN, "False");
            (*code) += 5;
            return true;
        }
    }

    return false;
}