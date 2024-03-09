#ifndef OPAL_LEXER_H
#define OPAL_LEXER_H

typedef struct tokens tokens;
enum token_type
{
    TOKEN_INT,
    TOKEN_FLOAT, // TODO
    TOKEN_BOOLEAN,
    TOKEN_BYTE, // TODO
    TOKEN_CHAR,
    TOKEN_STRING,
    TOKEN_ASSIGN,
    TOKEN_VARIABLE_NAME,
    TOKEN_NULL
};

struct tokens
{
    enum token_type type;
    void *value;
    tokens *next;
};

void show_lexer(tokens *tks);
void add_token(tokens **tks, enum token_type type, void *value);
tokens *lexer(char *code);

#endif