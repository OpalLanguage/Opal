#include "../../include/parser/parser.h"
#include "../../include/parser/parsers/parse_variable.h"
#include "../../include/parser/parsers/parse_function.h"

#include <stdio.h>
#include <stdlib.h>

Node *parse(Tokens **tokens)
{
    Node *head = NULL;
    Node **current = &head;

    while (*tokens && (*tokens)->type != TOKEN_EOF) {
        switch ((*tokens)->type) {
            case TOKEN_IDENTIFIER:
            case TOKEN_CONST:
                *current = parse_variable(tokens);
                current = &((*current)->next);
                break;
            case TOKEN_FUNC:
                *current = parse_function(tokens);
                current = &((*current)->next);
                break;
            default:
                *tokens = (*tokens)->next;
                break;
        }
    }

    return head;
}

void freeAst(Node *node)
{
    while (node != NULL) {
        Node *nextNode = node->next;

        if (node->type == NODE_VARIABLE_ASSIGNMENT) {
            free(node->data.variableAssignment.identifier);
            if (node->data.variableAssignment.value.type == VALUE_STRING) {
                free(node->data.variableAssignment.value.data.stringValue);
            }
        }

        free(node);
        node = nextNode;
    }
}