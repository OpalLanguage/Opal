#include "../../../include/parser/parsers/parse_function.h"
#include "../../../include/parser/parsers/parse_parameter.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node *parse_function(Tokens **tokens)
{
    if (tokens == NULL || *tokens == NULL) {
        fprintf(stderr, "Error: Token is NULL in parse_variable.\n");
        exit(EXIT_FAILURE);
    }

    Node *function_node = (Node*)malloc(sizeof(Node));

    if (function_node == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    function_node->type = NODE_FUNCTION_ASSIGNMENT;

    *tokens = (*tokens)->next;

    function_node->data.functionAssignmentNode.identifier = strdup((*tokens)->value);

    if (function_node->data.functionAssignmentNode.identifier == NULL) {
        fprintf(stderr, "Syntax error: Expected an 'IDENTIFIER' after func declaration !\n");
        free(function_node);
        exit(EXIT_FAILURE);
    }

    *tokens = (*tokens)->next;

    if ((*tokens)->type != TOKEN_LEFT_PAREN) {
        fprintf(stderr, "Syntax error: Expected an '(' after identifier !\n");
        free(function_node);
        exit(EXIT_FAILURE);
    }

    *tokens = (*tokens)->next;

    Parameter *parameters = malloc(sizeof(Parameter) * INITIAL_CAPACITY);
    int parametersCount = 0;
    int capacity = INITIAL_CAPACITY;

    while ((*tokens)->type != TOKEN_RIGHT_PAREN) {
        if (parametersCount == capacity) {
            capacity *= 2;
            Parameter *temp = realloc(parameters, sizeof(Parameter) * capacity);
            if (!temp) {
                perror("malloc");
                free(parameters);
                exit(EXIT_FAILURE);
            }
            parameters = temp;
        }

        parameters[parametersCount++] = parse_parameter(tokens);

        if ((*tokens)->type == TOKEN_COMMA) {
            *tokens = (*tokens)->next;
        }
    }

    function_node->data.functionAssignmentNode.parameters = parameters;
    function_node->data.functionAssignmentNode.parametersCount = parametersCount;

    *tokens = (*tokens)->next;
    function_node->next = NULL;

    return function_node;
}