#include "../include/lexer.h"

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

void show_lexer(tokens *tks)
{
    while (tks != NULL) {
        switch (tks->type) {
            case TOKEN_INT: {
                printf("TOKEN_INT: %d\n", *(int*)tks->value);
                break;
            }
            case TOKEN_CHAR: {
                printf("TOKEN_CHAR: '%c'\n", *(char*)tks->value);
                break;
            }
            case TOKEN_STRING: {
                printf("TOKEN_STRING: \"%s\"\n", (char*)tks->value);
                break;
            }
            case TOKEN_ASSIGN: {
                printf("TOKEN_ASSIGN: =\n");
                break;
            }
        }
        tks = tks->next;
    }
}

void add_token(tokens **tks, enum token_type type, void *value)
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

tokens *lexer(char *code)
{
    tokens *tks = NULL;

    while (*code != '\0') {
        if (isspace(*code)) {
            code++;
            continue;
        }

        if (isdigit(*code)) {
            int *number = malloc(sizeof(int));
            *number = strtol(code, &code, 10);
            add_token(&tks, TOKEN_INT, number);
            code++;
            continue;
        }

        switch (*code) {
            case '\'': {
                code++;
                char *c = malloc(sizeof(char));
                *c = *code;
                add_token(&tks, TOKEN_CHAR, c);
                code += 2;
                break;
            }
            case '\"': {
                char *string = calloc(50, sizeof(char));
                char *start = string;

                code++;
                while (*code != '\"' && *code != '\0') {
                    *string = *code;
                    string++;
                    code++;
                }
                *string = '\0';
                add_token(&tks, TOKEN_STRING, start);
                code++;
                break;
            }
            case '=': {
                char assign = *code;

                add_token(&tks, TOKEN_ASSIGN, &assign);
                code++;
                break;
            }

            default:
                code++;
        }
    }

    return tks;
}