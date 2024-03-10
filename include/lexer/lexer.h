#ifndef OPAL_LEXER_H
#define OPAL_LEXER_H

typedef struct tokens tokens;
enum token_type
{
    TOKEN_INT,
    TOKEN_FLOAT,
    TOKEN_BOOLEAN,
    TOKEN_CHAR,
    TOKEN_STRING,
    TOKEN_ASSIGN,
    TOKEN_VARIABLE_NAME,

    TOKEN_OP_PLUS,
    TOKEN_OP_MINUS,
    TOKEN_OP_MULTIPLY,
    TOKEN_OP_DIVIDE,
    TOKEN_OP_MODULO,

    TOKEN_NULL
};

struct tokens
{
    enum token_type type;
    void *value;
    tokens *next;
};

void add_token(tokens **tks, enum token_type type, void *value);
tokens *lexer(char *code);

#endif