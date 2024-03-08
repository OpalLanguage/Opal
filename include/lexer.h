#ifndef OPAL_LEXER_H
#define OPAL_LEXER_H

typedef struct token token;
enum token_type
{
    TOKEN_INT,
    TOKEN_CHAR,
    TOKEN_STRING,
    TOKEN_ASSIGN
};

struct token
{
    enum token_type type;
    void *value;
    token *next;
};

void show_lexer();

#endif
