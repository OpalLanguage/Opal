#include "../include/console.h"
#include "../include/lexer/lexer.h"

int main(void)
{
    char *code = asker();
    tokens *tks = lexer(code);

    show_lexer(tks);
    return 0;
}