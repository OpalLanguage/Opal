#include "../../include/lexer/lexer.h"
#include "../../include/lexer/lexers/lex_string.h"
#include "../../include/lexer/lexers/lex_char.h"
#include "../../include/lexer/lexers/lex_null.h"
#include "../../include/lexer/lexers/lex_boolean.h"

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

void add_operator_token(tokens **tks, char **code, char expected, enum token_type singleType, enum token_type doubleType, void *singleValue, void *doubleValue)
{
    if (*(*code + 1) == expected) {
        add_token(tks, doubleType, doubleValue);
        (*code)++;
    } else {
        add_token(tks, singleType, singleValue);
    }
}

void add_operator_or_assignment_token(tokens **tks, char **code, enum token_type opType, enum token_type assignType, void *opSymbol, void *assignSymbol)
{
    if (*(*code + 1) == '=') {
        add_token(tks, assignType, assignSymbol);
        (*code)++;
    } else {
        add_token(tks, opType, opSymbol);
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
                add_token(&tks, TOKEN_IDENTIFIER, strdup(buffer));
            }
        }
        else if (isdigit(*code)) {
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
                case '(': add_token(&tks, TOKEN_RIGHT_PAREN, NULL); break;
                case ')': add_token(&tks, TOKEN_LEFT_PAREN, NULL); break;
                case '{': add_token(&tks, TOKEN_RIGHT_BRACE, NULL); break;
                case '}': add_token(&tks, TOKEN_LEFT_BRACE, NULL); break;
                case '[': add_token(&tks, TOKEN_RIGHT_BRACKET, NULL); break;
                case ']': add_token(&tks, TOKEN_LEFT_BRACKET, NULL); break;
                case ',': add_token(&tks, TOKEN_COMMA, NULL); break;
                case '.': add_token(&tks, TOKEN_DOT, NULL); break;
                case ';': add_token(&tks, TOKEN_SEMICOLON, NULL); break;
                case ':': add_token(&tks, TOKEN_COLON, NULL); break;

                case '=': add_operator_token(&tks, &code, '=', TOKEN_ASSIGN, TOKEN_OP_EQUAL, NULL, "=="); break;
                case '!': add_operator_token(&tks, &code, '=', TOKEN_OP_NOT, TOKEN_OP_NOT_EQUAL, NULL, "!="); break;
                case '<': add_operator_token(&tks, &code, '=', TOKEN_OP_LESS, TOKEN_OP_LESS_EQUAL, NULL, "<="); break;
                case '>':add_operator_token(&tks, &code, '=', TOKEN_OP_GREATER, TOKEN_OP_GREATER_EQUAL, NULL, ">="); break;
                case '&': add_operator_token(&tks, &code, '&', TOKEN_ERROR, TOKEN_OP_AND, NULL, "&&"); break;
                case '|': add_operator_token(&tks, &code, '|', TOKEN_ERROR, TOKEN_OP_OR, NULL, "||"); break;

                case '*': add_operator_or_assignment_token(&tks, &code, TOKEN_OP_MULTIPLY, TOKEN_ASSIGN_MULTIPLY, NULL, "*="); break;
                case '/': add_operator_or_assignment_token(&tks, &code, TOKEN_OP_DIVIDE, TOKEN_ASSIGN_DIVIDE, NULL, "/="); break;
                case '%': add_operator_or_assignment_token(&tks, &code, TOKEN_OP_MODULO, TOKEN_ASSIGN_MODULO, NULL, "%="); break;

                case '+':
                    if (*(code+1) == '+') {
                        add_token(&tks, TOKEN_INCR, "++");
                        code++;
                    } else {
                        add_operator_or_assignment_token(&tks, &code, TOKEN_OP_PLUS, TOKEN_ASSIGN_ADD, NULL, "+=");
                    }
                    break;
                case '-':
                    if (*(code + 1) == '-') {
                        add_token(&tks, TOKEN_DECR, "--");
                        code++;
                    } else {
                        add_operator_or_assignment_token(&tks, &code, TOKEN_OP_SUBTRACT, TOKEN_ASSIGN_SUBTRACT, NULL, "-=");
                    }
                    break;
                    
                case '\'': lex_char(&tks, &code); break;
                case '\"': lex_string(&tks, &code); break;

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