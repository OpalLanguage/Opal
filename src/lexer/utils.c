#include "../../include/lexer/lexer.h"

#include <stdio.h>

const char *get_operator_as_string(enum token_type type)
{
    switch (type) {
        case TOKEN_OP_PLUS:
            return "+";
        case TOKEN_OP_MINUS:
            return "-";
        case TOKEN_OP_MULTIPLY:
            return "*";
        case TOKEN_OP_DIVIDE:
            return "/";
        case TOKEN_OP_MODULO:
            return "%";
        default:
            return NULL;
    }
}

void show_lexer(tokens *tks)
{
    while (tks != NULL) {
        switch (tks->type) {
            case TOKEN_INT: {
                printf("INT -> %d\n", *(int*)tks->value);
                break;
            }
            case TOKEN_CHAR: {
                printf("CHAR -> '%c'\n", *(char*)tks->value);
                break;
            }
            case TOKEN_STRING: {
                printf("STRING -> \"%s\"\n", (char*)tks->value);
                break;
            }
            case TOKEN_VARIABLE_NAME: {
                printf("VARIABLE_NAME -> %s\n", (char*)tks->value);
                break;
            }
            case TOKEN_FLOAT:
                printf("FLOAT -> %f\n", *(double*)tks->value);
                break;
            case TOKEN_BOOLEAN: {
                printf("BOOLEAN -> %s\n", (char*)tks->value);
                break;
            }
            case TOKEN_NULL:
                printf("NULL -> %s\n", (char*)tks->value);
                break;
            case TOKEN_ASSIGN:
                printf("ASSIGN -> =\n");
                break;
            default:
                printf("OPERATOR -> %s\n", get_operator_as_string(tks->type));
                break;
        }
        tks = tks->next;
    }
}