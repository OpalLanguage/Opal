#include "../include/lexer.h"

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

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
            case TOKEN_ASSIGN: {
                printf("ASSIGN -> =\n");
                break;
            }
            case TOKEN_VARIABLE_NAME: {
                printf("VARIABLE_NAME -> %s\n", (char*)tks->value);
                break;
            }
            case TOKEN_FLOAT:
                printf("FLOAT -> %f\n", *(float*)tks->value);
                break;
            case TOKEN_BOOLEAN: {
                printf("BOOLEAN -> %s\n", (char*)tks->value);
                break;
            }
            case TOKEN_BYTE:
                break;
            case TOKEN_NULL:
                printf("NULL -> %s\n", (char*)tks->value);
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

bool lex_boolean(tokens **tks, char **code)
{
    if (**code == 'T') {
        if (*(*code+1) == 'r' && *(*code+2) == 'u' && *(*code+3) == 'e') {
            add_token(tks, TOKEN_BOOLEAN, "True");
            (*code) += 4;
            return true;
        }
    }
    else if (**code == 'F') {
        if (*(*code+1) == 'a' && *(*code+2) == 'l' && *(*code+3) == 's' && *(*code+4) == 'e') {
            add_token(tks, TOKEN_BOOLEAN, "False");
            (*code) += 5;
            return true;
        }
    }

    return false;
}

bool lex_null(tokens **tks, char **code)
{
    if (**code == 'N') {
        if (*(*code+1) == 'u' && *(*code+2) == 'l' && *(*code+3) == 'l') {
            add_token(tks, TOKEN_NULL, "Null");
            (*code) += 4;
            return true;
        }
    }

    return false;
}

void lex_number(tokens **tks, char **code)
{
    int *number = malloc(sizeof(int));
    *number = strtol(*code, code, 10);
    add_token(tks, TOKEN_INT, number);
    (*code)++;
}

void lex_char(tokens **tks, char **code)
{
    (*code)++;
    char *c = malloc(sizeof(char));
    *c = **code;
    add_token(tks, TOKEN_CHAR, c);
    (*code) += 2;
}

void lex_string(tokens **tks, char **code)
{
    char *string = calloc(50, sizeof(char));
    char *start = string;

    (*code)++;
    while (**code != '\"' && **code != '\0') {
        *string = **code;
        string++;
        (*code)++;
    }
    *string = '\0';
    add_token(tks, TOKEN_STRING, start);
    (*code)++;
}

void lex_variable(tokens **tks, char **code)
{
    char *name = calloc(50, sizeof(char));
    char *start = name;

    while (**code != ' ' && **code != '\0') {
        *name = **code;
        name++;
        (*code)++;
    }

    *name = '\0';
    add_token(tks, TOKEN_VARIABLE_NAME, start);
    (*code)++;

    if (**code != '=') {
        printf("You need = to define a variable for variable: %s\n", start);
        exit(1);
    }

    add_token(tks, TOKEN_ASSIGN, *code);
    (*code) += 2;

    if (isdigit(**code)) {
        lex_number(tks, code);
        return;
    }

    if (isalpha(**code)) {
        if (!lex_boolean(tks, code) && !lex_null(tks, code)) {
            printf("You need a valid value for variable: %s\n", start);
            exit(1);
        }

        return;
    }

    switch (**code) {
        case '\'': {
            lex_char(tks, code);
            return;
        }
        case '\"': {
            lex_string(tks, code);
            return;
        }

        default:
            printf("You need a valid value for variable: %s\n", start);
            exit(1);
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

        lex_variable(&tks, &code);
    }

    return tks;
}