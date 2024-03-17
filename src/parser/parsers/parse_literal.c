#include "../../../include/parser/parsers/parse_literal.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Value *parse_literal(Tokens **tokens)
{
    if (tokens == NULL || *tokens == NULL) {
        fprintf(stderr, "Error: Token is NULL in parse_literal.\n");
        exit(EXIT_FAILURE);
    }

    Value *value = (Value*)malloc(sizeof(Value));
    if (value == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    switch ((*tokens)->type) {
        case TOKEN_INT:
            value->type = VALUE_INT;
            value->data.intValue = *((int*)(*tokens)->value);
            break;
        case TOKEN_FLOAT:
            value->type = VALUE_FLOAT;
            value->data.floatValue = *((double*)(*tokens)->value);
            break;
        case TOKEN_STRING:
            value->type = VALUE_STRING;
            value->data.stringValue = strdup((char*)(*tokens)->value);
            if (value->data.stringValue == NULL) {
                fprintf(stderr, "Memory allocation failed for string value\n");
                free(value);
                exit(EXIT_FAILURE);
            }
            break;
        case TOKEN_CHAR:
            value->type = VALUE_CHAR;
            value->data.charValue = *((char*)(*tokens)->value);
            break;
        case TOKEN_BOOLEAN:
            value->type = VALUE_BOOLEAN;
            value->data.booleanValue = *((bool*)(*tokens)->value);
            break;
        default:
            fprintf(stderr, "Syntax error: Invalid type of data after assign !\n");
            exit(EXIT_FAILURE);
    }

    return value;
}