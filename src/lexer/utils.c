#include "../../include/lexer/lexer.h"

#include <stdio.h>

char get_operator_as_string(token_type type)
{
    switch (type) {
        case TOKEN_OP_PLUS:
            return '+';
        case TOKEN_OP_SUBTRACT:
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
        case TOKEN_LEFT_PAREN:
            return '(';
        case TOKEN_RIGHT_PAREN:
            return ')';
        case TOKEN_LEFT_BRACE:
            return '{';
        case TOKEN_RIGHT_BRACE:
            return '}';
        case TOKEN_LEFT_BRACKET:
            return '[';
        case TOKEN_RIGHT_BRACKET:
            return ']';
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
            case TOKEN_IF:
                printf("CONTROL FLOW -> if\n");
                break;
            case TOKEN_ELSEIF:
                printf("CONTROL FLOW -> elseif\n");
                break;
            case TOKEN_ELSE:
                printf("CONTROL FLOW -> else\n");
                break;
            case TOKEN_FOR:
                printf("CONTROL FLOW -> for\n");
                break;
            case TOKEN_WHILE:
                printf("CONTROL FLOW -> while\n");
                break;
            case TOKEN_SWITCH:
                printf("CONTROL FLOW -> switch\n");
                break;
            case TOKEN_CASE:
                printf("CONTROL FLOW -> case\n");
                break;
            case TOKEN_DEFAULT:
                printf("CONTROL FLOW -> default\n");
                break;
            case TOKEN_BREAK:
                printf("CONTROL FLOW -> break\n");
                break;
            case TOKEN_CONTINUE:
                printf("CONTROL FLOW -> continue\n");
                break;
            case TOKEN_CLASS:
                printf("DECLARATION -> class\n");
                break;
            case TOKEN_ENUM:
                printf("DECLARATION -> enum\n");
                break;
            case TOKEN_FUNC:
                printf("DECLARATION -> func\n");
                break;
            case TOKEN_CONST:
                printf("DECLARATION -> const\n");
                break;
            case TOKEN_RETURN:
                printf("MISC -> return\n");
                break;
            case TOKEN_NEW:
                printf("MISC -> new\n");
                break;
            case TOKEN_THIS:
                printf("MISC -> this\n");
                break;
            case TOKEN_SUPER:
                printf("MISC -> super\n");
                break;
            case TOKEN_EOF:
                printf("End of file.\n");
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