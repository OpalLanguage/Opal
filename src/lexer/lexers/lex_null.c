#include "../../../include/lexer/lexers/lex_null.h"

bool lex_null(tokens **tks, char **code)
{
    if (**code == 'N') {
        if (*(*code+1) == 'u' && *(*code+2) == 'l' && *(*code+3) == 'l') {
            add_token(tks, TOKEN_NULL, "Null");
            (*code) += 4;
            return true;
        }
    }

    return false;
}