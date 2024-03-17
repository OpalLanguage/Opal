#include "../include/console.h"
#include "../include/file_loader.h"
#include "../include/lexer/lexer.h"
#include "../include/lexer/lex_utils.h"
#include "../include/parser/parser.h"
#include "../include/parser/parse_utils.h"

#include <stdlib.h>

int main(void)
{
    char *code = asker();
    //char *code = get_code("../opal/main.opal");
    Tokens *tks = lexer(code);

    Node *node = parse(&tks);

    show_parser(node);

    free(code);

    while (tks != NULL) {
        Tokens *current = tks;
        tks = tks->next;
        free(current);
    }

    freeAst(node);

    return 0;
}