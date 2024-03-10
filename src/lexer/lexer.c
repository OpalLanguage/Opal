#include "../../include/lexer/lexer.h"
#include "../../include/lexer/lexers/lex_string.h"
#include "../../include/lexer/lexers/lex_char.h"
#include "../../include/lexer/lexers/lex_null.h"
#include "../../include/lexer/lexers/lex_boolean.h"

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

void add_token(tokens **tks, const enum token_type type, void *value)
{
    tokens *new_token = (tokens*)malloc(sizeof(tokens));
    if (new_token == NULL) {
        perror("malloc");
        exit(1);
    }

    new_token->type = type;
    new_token->value = value;
    new_token->next = NULL;

    if (*tks == NULL) {
        *tks = new_token;
    }
    else {
        tokens *current = *tks;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_token;
    }
}

void skip_whitespace_and_continue(char **code)
{
    while (isspace(**code)) (*code)++;
}

tokens *lexer(char *code)
{
    tokens *tks = NULL;

    while (*code != '\0') {
        if (isspace(*code)) {
            code++;
            continue;
        }

        if (isalpha(*code)) {
            if (!lex_boolean(&tks, &code) && !lex_null(&tks, &code)) {
                char buffer[50];
                int i = 0;
                while (isalnum(*code) || *code == '_') {
                    buffer[i++] = *code++;
                }

                buffer[i] = '\0';
                add_token(&tks, TOKEN_VARIABLE_NAME, strdup(buffer));
            }
        }
        else if (isdigit(*code) || *code == '.') {
            char *end;
            const double value = strtod(code, &end);

            if (code != end) {
                if (strchr(code, '.') != NULL) {
                    double *floatVal = malloc(sizeof(double));
                    *floatVal = value;
                    add_token(&tks, TOKEN_FLOAT, floatVal);
                } else {
                    int *intVal = malloc(sizeof(int));
                    *intVal = (int)value;
                    add_token(&tks, TOKEN_INT, intVal);
                }
                code = end;
            }
        }
        else {
            switch (*code) {
                case '=':
                    add_token(&tks, TOKEN_ASSIGN, NULL);
                    break;
                case '+':
                    add_token(&tks, TOKEN_OP_PLUS, NULL);
                    break;
                case '-':
                    add_token(&tks, TOKEN_OP_MINUS, NULL);
                    break;
                case '*':
                    add_token(&tks, TOKEN_OP_MULTIPLY, NULL);
                    break;
                case '/':
                    add_token(&tks, TOKEN_OP_DIVIDE, NULL);
                    break;
                case '%':
                    add_token(&tks, TOKEN_OP_MODULO, NULL);
                    break;
                case '\'':
                    lex_char(&tks, &code);
                    break;
                case '\"':
                    lex_string(&tks, &code);
                    break;
                default:
                    fprintf(stderr, "Unrecognized character: %c\n", *code);
                    exit(EXIT_FAILURE);
            }
            code++;
        }

        skip_whitespace_and_continue(&code);
    }

    return tks;
}