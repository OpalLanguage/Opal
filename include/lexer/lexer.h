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
    TOKEN_ASSIGN_ADD,
    TOKEN_ASSIGN_SUBTRACT,
    TOKEN_ASSIGN_MULTIPLY,
    TOKEN_ASSIGN_DIVIDE,
    TOKEN_ASSIGN_MODULO,

    TOKEN_IDENTIFIER,

    TOKEN_OP_PLUS,
    TOKEN_OP_SUBTRACT,
    TOKEN_OP_MULTIPLY,
    TOKEN_OP_DIVIDE,
    TOKEN_OP_MODULO,

    TOKEN_OP_EQUAL,
    TOKEN_OP_NOT_EQUAL,
    TOKEN_OP_GREATER,
    TOKEN_OP_GREATER_EQUAL,
    TOKEN_OP_LESS,
    TOKEN_OP_LESS_EQUAL,

    TOKEN_OP_AND,
    TOKEN_OP_OR,
    TOKEN_OP_NOT,

    TOKEN_LEFT_PAREN,
    TOKEN_RIGHT_PAREN,
    TOKEN_LEFT_BRACE,
    TOKEN_RIGHT_BRACE,
    TOKEN_LEFT_BRACKET,
    TOKEN_RIGHT_BRACKET,
    TOKEN_COMMA,
    TOKEN_DOT,
    TOKEN_SEMICOLON,
    TOKEN_COLON,

    TOKEN_INCR,
    TOKEN_DECR,

    TOKEN_NULL,
    TOKEN_EOF,
    TOKEN_ERROR,
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