#include "../include/console.h"
#include "../include/file_loader.h"
#include "../include/lexer/lexer.h"
#include "../include/lexer/utils.h"

#include <stdlib.h>

int main(void)
{
    //char *code = asker();
    char *code = get_code("../opal/main.opal");
    tokens *tks = lexer(code);

    show_lexer(tks);

    free(code);
    free(tks);
    return 0;
}