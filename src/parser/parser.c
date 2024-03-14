#include "../../include/parser/parser.h"
#include "../../include/parser/parsers/parse_variable.h"

#include <stdio.h>

void add_node(ASTNode **ast, ASTNode *node)
{
    if (*ast == NULL) {
        *ast = node;
    } else {
        ASTNode *current = *ast;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
    }
}

ASTNode *parse(Tokens *tokens)
{
    ASTNode *ast = NULL;

    while (tokens && tokens->type != TOKEN_EOF) {
        if (tokens->type == TOKEN_IDENTIFIER || tokens->type == TOKEN_CONST) {
            ASTNode* varDeclNode = parse_variable_declaration(&tokens);
            add_node(&ast, varDeclNode);
        }

        tokens = tokens->next;
    }

    return ast;
}
