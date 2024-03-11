#include "../../../include/lexer/lexers/lex_misc.h"

#include <string.h>
#include <ctype.h>

bool lex_misc(tokens **tks, char **code)
{
    if (strncmp(*code, "return", 6) == 0 && !isalnum(*(*code + 6))) {
        add_token(tks, TOKEN_RETURN, "return");
        *code += 6;
        return true;
    }
    else if (strncmp(*code, "new", 3) == 0 && !isalnum(*(*code + 3))) {
        add_token(tks, TOKEN_NEW, "new");
        *code += 3;
        return true;
    }
    else if (strncmp(*code, "this", 4) == 0 && !isalnum(*(*code + 4))) {
        add_token(tks, TOKEN_THIS, "this");
        *code += 4;
        return true;
    }
    else if (strncmp(*code, "super", 5) == 0 && !isalnum(*(*code + 5))) {
        add_token(tks, TOKEN_SUPER, "super");
        *code += 5;
        return true;
    }

    return false;
}