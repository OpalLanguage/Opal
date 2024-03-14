#include "../../../include/parser/parsers/parse_variable.h"
#include "../../../include/parser/parsers/parse_literal.h"

#include <stdio.h>
#include <stdlib.h>

ASTNode* parse_variable_declaration(Tokens **tokens)
{
    VariableDeclaration *variableDeclaration = (VariableDeclaration*)malloc(sizeof(VariableDeclaration));
    if (variableDeclaration == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    bool isConst = (*tokens)->type == TOKEN_CONST;

    variableDeclaration->node.type = NODE_TYPE_VARIABLE_DECLARATION;
    variableDeclaration->isConst = isConst;

    /*
     * DEF OF THE VARIABLE NAME
     */

    if (isConst) {
        *tokens = (*tokens)->next;
    }

    if ((*tokens)->type != TOKEN_IDENTIFIER) {
        fprintf(stderr, "Syntax error: Expected 'IDENTIFIER' after variable const for variable.\n");
        exit(EXIT_FAILURE);
    }

    variableDeclaration->name = (*tokens)->value;

    /*
     * ASSIGN
     */

    *tokens = (*tokens)->next;

    if ((*tokens)->type != TOKEN_ASSIGN) {
        fprintf(stderr, "Syntax error: Expected '=' after variable name.\n");
        exit(EXIT_FAILURE);
    }

    /*
     * DEF OF THE VALUE FOR THE VARIABLE
     */

    *tokens = (*tokens)->next;

    if ((*tokens)->type != TOKEN_INT
    && (*tokens)->type != TOKEN_FLOAT
    && (*tokens)->type != TOKEN_BOOLEAN
    && (*tokens)->type != TOKEN_CHAR
    && (*tokens)->type != TOKEN_STRING
    && (*tokens)->type != TOKEN_NULL) {
        fprintf(stderr, "Syntax error: Expected 'VALUE' after assign.\n");
        exit(EXIT_FAILURE);
    }

    variableDeclaration->expression = parse_literal(tokens);

    return (ASTNode*)variableDeclaration;
}