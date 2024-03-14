#include "../../include/lexer/lexer.h"
#include "../../include/lexer/lexers/lex_string.h"
#include "../../include/lexer/lexers/lex_char.h"
#include "../../include/lexer/lexers/lex_null.h"
#include "../../include/lexer/lexers/lex_boolean.h"
#include "../../include/lexer/lexers/lex_control_flow.h"
#include "../../include/lexer/lexers/lex_declaration.h"
#include "../../include/lexer/lexers/lex_misc.h"
#include "../../include/lexer/lexers/lex_int.h"
#include "../../include/lexer/lexers/lex_float.h"
#include "../../include/lexer/lexers/lex_comment.h"

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void add_token(Tokens **tks, const TokenType type, void *value)
{
    Tokens *new_token = (Tokens*)malloc(sizeof(Tokens));
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
        Tokens *current = *tks;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_token;
    }
}

void add_operator_token(Tokens **tks, char **code, char expected, TokenType singleType, TokenType doubleType, void *doubleValue)
{
    if (*(*code + 1) == expected) {
        add_token(tks, doubleType, doubleValue);
        (*code)++;
    } else {
        add_token(tks, singleType, NULL);
    }
}

void add_operator_or_assignment_token(Tokens **tks, char **code, TokenType opType, TokenType assignType, void *assignSymbol)
{
    if (*(*code + 1) == '=') {
        add_token(tks, assignType, assignSymbol);
        (*code)++;
    } else {
        add_token(tks, opType, NULL);
    }
}

void skip_whitespace_and_continue(char **code)
{
    while (isspace(**code)) (*code)++;
}

Tokens *lexer(char *code)
{
    Tokens *tks = NULL;

    while (*code != '\0') {
        if (isspace(*code)) {
            code++;
            continue;
        }

        if (*code == '/') {
            lex_comment(&code);
            continue;
        }

        if (isalpha(*code)) {
            if (!lex_boolean(&tks, &code)
            && !lex_null(&tks, &code)
            && !lex_control_flow(&tks, &code)
            && !lex_declaration(&tks, &code)
            && !lex_misc(&tks, &code)) {
                char buffer[50];
                int i = 0;
                while (isalnum(*code) || *code == '_') {
                    buffer[i++] = *code++;
                }

                buffer[i] = '\0';
                add_token(&tks, TOKEN_IDENTIFIER, strdup(buffer));
            }
        }
        else if (isdigit(*code) || (*code == '.' && isdigit(*(code + 1)))) {
            char *end;
            const double value = strtod(code, &end);

            if (code != end) {
                char *dotPos = strchr(code, '.');
                if (dotPos != NULL && dotPos < end) {
                    lex_float(&tks, value);
                } else {
                    lex_int(&tks, value);
                }
                code = end;
            }
        }
        else {
            switch (*code) {
                case '(': add_token(&tks, TOKEN_LEFT_PAREN, NULL); break;
                case ')': add_token(&tks, TOKEN_RIGHT_PAREN, NULL); break;
                case '{': add_token(&tks, TOKEN_LEFT_BRACE, NULL); break;
                case '}': add_token(&tks, TOKEN_RIGHT_BRACE, NULL); break;
                case '[': add_token(&tks, TOKEN_LEFT_BRACKET, NULL); break;
                case ']': add_token(&tks, TOKEN_RIGHT_BRACKET, NULL); break;
                case ',': add_token(&tks, TOKEN_COMMA, NULL); break;
                case '.': add_token(&tks, TOKEN_DOT, NULL); break;
                case ';': add_token(&tks, TOKEN_SEMICOLON, NULL); break;
                case ':': add_token(&tks, TOKEN_COLON, NULL); break;

                case '=': add_operator_token(&tks, &code, '=', TOKEN_ASSIGN, TOKEN_OP_EQUAL, "=="); break;
                case '!': add_operator_token(&tks, &code, '=', TOKEN_OP_NOT, TOKEN_OP_NOT_EQUAL, "!="); break;
                case '<': add_operator_token(&tks, &code, '=', TOKEN_OP_LESS, TOKEN_OP_LESS_EQUAL, "<="); break;
                case '>':add_operator_token(&tks, &code, '=', TOKEN_OP_GREATER, TOKEN_OP_GREATER_EQUAL, ">="); break;
                case '&': add_operator_token(&tks, &code, '&', TOKEN_ERROR, TOKEN_OP_AND, "&&"); break;
                case '|': add_operator_token(&tks, &code, '|', TOKEN_ERROR, TOKEN_OP_OR, "||"); break;

                case '*': add_operator_or_assignment_token(&tks, &code, TOKEN_OP_MULTIPLY, TOKEN_ASSIGN_MULTIPLY, "*="); break;
                case '/': add_operator_or_assignment_token(&tks, &code, TOKEN_OP_DIVIDE, TOKEN_ASSIGN_DIVIDE, "/="); break;
                case '%': add_operator_or_assignment_token(&tks, &code, TOKEN_OP_MODULO, TOKEN_ASSIGN_MODULO, "%="); break;

                case '+':
                    if (*(code+1) == '+') {
                        add_token(&tks, TOKEN_INCR, "++");
                        code++;
                    } else {
                        add_operator_or_assignment_token(&tks, &code, TOKEN_OP_PLUS, TOKEN_ASSIGN_ADD, "+=");
                    }
                    break;
                case '-':
                    if (*(code + 1) == '-') {
                        add_token(&tks, TOKEN_DECR, "--");
                        code++;
                    } else {
                        add_operator_or_assignment_token(&tks, &code, TOKEN_OP_SUBTRACT, TOKEN_ASSIGN_SUBTRACT, "-=");
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

    add_token(&tks, TOKEN_EOF, NULL);
    return tks;
}