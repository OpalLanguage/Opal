#include "../../../include/lexer/lexers/lex_comment.h"

#include <string.h>

void lex_comment(char **code)
{
    if (strncmp(*code, "//", 2) == 0) {
        *code += 2;
        while (**code != '\n' && **code != '\0') {
            (*code)++;
        }
    }

    else if (strncmp(*code, "/*", 2) == 0) {
        *code += 2;
        while (**code != '\0' && !(**code == '*' && *(*code + 1) == '/')) {
            (*code)++;
        }
        if (**code == '*') {
            *code += 2;
        }
    }
}