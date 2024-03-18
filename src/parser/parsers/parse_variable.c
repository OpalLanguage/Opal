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
    variable_node->data.variableAssignment.isConst = (*tokens)->type == TOKEN_CONST;

    if (variable_node->data.variableAssignment.isConst) {
        *tokens = (*tokens)->next;
    }

    variable_node->data.variableAssignment.identifier = strdup((*tokens)->value);

    *tokens = (*tokens)->next;

    switch ((*tokens)->type) {
        case TOKEN_ASSIGN:
            variable_node->data.variableAssignment.assignmentType = ASSIGN;
            break;
        case TOKEN_ASSIGN_ADD:
            variable_node->data.variableAssignment.assignmentType = ADD_ASSIGN;
            break;
        case TOKEN_ASSIGN_SUBTRACT:
            variable_node->data.variableAssignment.assignmentType = SUB_ASSIGN;
            break;
        case TOKEN_ASSIGN_MULTIPLY:
            variable_node->data.variableAssignment.assignmentType = MUL_ASSIGN;
            break;
        case TOKEN_ASSIGN_DIVIDE:
            variable_node->data.variableAssignment.assignmentType = DIV_ASSIGN;
            break;
        default:
            fprintf(stderr, "Syntax error: Expected an assignment operator after identifier !\n");
            free(variable_node->data.variableAssignment.identifier);
            free(variable_node);
            exit(EXIT_FAILURE);
    }

    *tokens = (*tokens)->next;

    if (!*tokens) {
        fprintf(stderr, "Syntax error: Expected a value after '=' !\n");
        free(variable_node->data.variableAssignment.identifier);
        free(variable_node);
        exit(EXIT_FAILURE);
    }

    variable_node->data.variableAssignment.value = *parse_literal(tokens);

    *tokens = (*tokens)->next;

    variable_node->next = NULL;

    return variable_node;
}