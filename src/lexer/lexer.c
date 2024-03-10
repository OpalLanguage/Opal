#include "../../include/lexer/lexer.h"
#include "../../include/lexer/lexers/lex_float.h"
#include "../../include/lexer/lexers/lex_string.h"
#include "../../include/lexer/lexers/lex_char.h"
#include "../../include/lexer/lexers/lex_null.h"
#include "../../include/lexer/lexers/lex_boolean.h"
#include "../../include/lexer/lexers/lex_int.h"

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

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

        if (isalpha(*code)) {
            if (!lex_boolean(&tks, &code) && !lex_null(&tks, &code)) {
                char *name = calloc(50, sizeof(char));
                char *start = name;

                while (*code != ' ' && *code != '\0') {
                    *name = *code;
                    name++;
                    code++;
                }
                *name = '\0';

                add_token(&tks, TOKEN_VARIABLE_NAME, start);
                while (isspace(*code)) code++;
                continue;
            }

            continue;
        }

        if (*code == '=') {
            char *value = malloc(sizeof(char));
            if (value == NULL) {
                perror("malloc");
                exit(1);
            }

            *value = '=';

            add_token(&tks, TOKEN_ASSIGN, value);
            code++;
            while (isspace(*code)) code++;
            continue;
        }

        if (isdigit(*code)) {
            char *end;
            double number = strtod(code, &end);
            bool isFloat = (*end != *code && (strchr(code, '.') != NULL));

            if (isFloat && floor(number) == number) {
                isFloat = false;
            }

            if (isFloat) {
                lex_float(&tks, number);
            }
            else {
                int intValue = (int)number;
                lex_int(&tks, intValue);
            }
            code = end;
            continue;
        }

        switch (*code) {
            case '\'': {
                lex_char(&tks, &code);
                while (isspace(*code)) code++;
                continue;
            }
            case '\"': {
                lex_string(&tks, &code);
                while (isspace(*code)) code++;
                continue;
            }

            default:
                while (isspace(*code)) code++;
        }
    }

    return tks;
}