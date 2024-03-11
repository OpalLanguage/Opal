#include "../../../include/lexer/lexers/lex_control_flow.h"

#include <string.h>

bool lex_control_flow(tokens **tks, char **code)
{
    if (strncmp(*code, "if", 2) == 0) {
        add_token(tks, TOKEN_IF, "if");
        *code += 2;
        return true;
    }
    else if (strncmp(*code, "elseif", 6) == 0) {
        add_token(tks, TOKEN_ELSEIF, "elseif");
        *code += 6;
        return true;
    }
    else if (strncmp(*code, "else", 4) == 0) {
        add_token(tks, TOKEN_ELSE, "else");
        *code += 4;
        return true;
    }
    else if (strncmp(*code, "for", 3) == 0) {
        add_token(tks, TOKEN_FOR, "for");
        *code += 3;
        return true;
    }
    else if (strncmp(*code, "while", 5) == 0) {
        add_token(tks, TOKEN_WHILE, "while");
        *code += 5;
        return true;
    }
    else if (strncmp(*code, "switch", 6) == 0) {
        add_token(tks, TOKEN_SWITCH, "switch");
        *code += 6;
        return true;
    }
    else if (strncmp(*code, "case", 4) == 0) {
        add_token(tks, TOKEN_CASE, "case");
        *code += 4;
        return true;
    }
    else if (strncmp(*code, "default", 7) == 0) {
        add_token(tks, TOKEN_DEFAULT, "default");
        *code += 7;
        return true;
    }
    else if (strncmp(*code, "break", 5) == 0) {
        add_token(tks, TOKEN_BREAK, "break");
        *code += 5;
        return true;
    }
    else if (strncmp(*code, "continue", 8) == 0) {
        add_token(tks, TOKEN_CONTINUE, "continue");
        *code += 8;
        return true;
    }

    return false;
}