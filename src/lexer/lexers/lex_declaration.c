#include "../../../include/lexer/lexers/lex_declaration.h"

#include <string.h>
#include <ctype.h>

bool lex_declaration(tokens **tks, char **code)
{
    if (strncmp(*code, "class", 5) == 0 && !isalnum(*(*code + 5))) {
        add_token(tks, TOKEN_CLASS, "class");
        *code += 5;
        return true;
    }
    else if (strncmp(*code, "enum", 4) == 0 && !isalnum(*(*code + 4))) {
        add_token(tks, TOKEN_ENUM, "enum");
        *code += 4;
        return true;
    }

    else if (strncmp(*code, "func", 4) == 0 && !isalnum(*(*code + 4))) {
        add_token(tks, TOKEN_FUNC, "func");
        *code += 4;
        return true;
    }
    else if (strncmp(*code, "const", 5) == 0 && !isalnum(*(*code + 5))) {
        add_token(tks, TOKEN_CONST, "const");
        *code += 5;
        return true;
    }

    return false;
}