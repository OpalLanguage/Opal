#include "../../include/lexer/lexer.h"

#include <stdio.h>

char get_operator_as_string(enum token_type type)
{
    switch (type) {
        case TOKEN_OP_PLUS:
            return '+';
        case TOKEN_OP_SUBSTRACT:
            return '-';
        case TOKEN_OP_MULTIPLY:
            return '*';
        case TOKEN_OP_DIVIDE:
            return '/';
        case TOKEN_OP_MODULO:
            return '%';
        case TOKEN_OP_NOT:
            return '!';
        case TOKEN_OP_GREATER:
            return '>';
        case TOKEN_OP_LESS:
            return '<';
        case TOKEN_RIGHT_PAREN:
            return '(';
        case TOKEN_LEFT_PAREN:
            return ')';
        case TOKEN_RIGHT_BRACE:
            return '{';
        case TOKEN_LEFT_BRACE:
            return '}';
        case TOKEN_COMMA:
            return ',';
        case TOKEN_DOT:
            return '.';
        case TOKEN_SEMICOLON:
            return ';';
        case TOKEN_COLON:
            return ':';
        default:
            return 'E';
    }
}

void show_lexer(tokens *tks)
{
    while (tks != NULL) {
        switch (tks->type) {
            case TOKEN_INT:
                printf("INT -> %d\n", *(int*)tks->value);
                break;
            case TOKEN_CHAR:
                printf("CHAR -> '%c'\n", *(char*)tks->value);
                break;
            case TOKEN_STRING:
                printf("STRING -> \"%s\"\n", (char*)tks->value);
                break;
            case TOKEN_IDENTIFIER:
                printf("IDENTIFIER -> %s\n", (char*)tks->value);
                break;
            case TOKEN_FLOAT:
                printf("FLOAT -> %f\n", *(double*)tks->value);
                break;
            case TOKEN_BOOLEAN:
                printf("BOOLEAN -> %s\n", (char*)tks->value);
                break;
            case TOKEN_NULL:
                printf("NULL -> %s\n", (char*)tks->value);
                break;
            case TOKEN_ASSIGN:
                printf("ASSIGN -> =\n");
                break;
            default:
                if (tks->value == NULL) {
                    printf("OPERATOR -> %c\n", get_operator_as_string(tks->type));
                    break;
                }
                printf("OPERATOR -> %s\n", (char*)tks->value);
                break;
        }
        tks = tks->next;
    }
}