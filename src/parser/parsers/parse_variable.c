#include "../../../include/parser/parsers/parse_variable.h"
#include "../../../include/parser/parsers/parse_literal.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node *parse_variable(Tokens **tokens)
{
    if (tokens == NULL || *tokens == NULL) {
        fprintf(stderr, "Error: Token is NULL in parse_variable.\n");
        exit(EXIT_FAILURE);
    }

    Node *variable_node = (Node*)malloc(sizeof(Node));

    if (variable_node == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    variable_node->type = NODE_VARIABLE_ASSIGNMENT;
    variable_node->data.assignment.identifier = strdup((*tokens)->value);

    *tokens = (*tokens)->next;

    if (!*tokens || (*tokens)->type != TOKEN_ASSIGN) {
        fprintf(stderr, "Syntax error: Expected '=' after identifier !\n");
        free(variable_node->data.assignment.identifier);
        free(variable_node);
        exit(EXIT_FAILURE);
    }

    *tokens = (*tokens)->next;

    if (!*tokens) {
        fprintf(stderr, "Syntax error: Expected a value after '=' !\n");
        free(variable_node->data.assignment.identifier);
        free(variable_node);
        exit(EXIT_FAILURE);
    }

    variable_node->data.assignment.value = *parse_literal(tokens);

    *tokens = (*tokens)->next;

    variable_node->next = NULL;

    return variable_node;
}