#ifndef OPAL_PARSER_H
#define OPAL_PARSER_H

#include "../lexer/lexer.h"

#include <stdbool.h>

typedef enum
{
    NODE_TYPE_CLASS_DECLARATION,
    NODE_TYPE_VARIABLE_DECLARATION,
    NODE_TYPE_FUNCTION_DECLARATION,
    NODE_TYPE_PARAMETER,
    NODE_TYPE_BLOCK,
    NODE_TYPE_STATEMENT,
    NODE_TYPE_IF_STATEMENT,
    NODE_TYPE_ELSEIF_STATEMENT,
    NODE_TYPE_ELSE_STATEMENT,
    NODE_TYPE_WHILE_STATEMENT,
    NODE_TYPE_ASSIGNMENT,
    NODE_TYPE_FUNCTION_CALL,
    NODE_TYPE_RETURN_STATEMENT,
    NODE_TYPE_LOG_STATEMENT,
    NODE_TYPE_EXPRESSION,
    NODE_TYPE_BINARY_EXPRESSION,
    NODE_TYPE_FUNCTION_CALL_EXPRESSION,
    NODE_TYPE_UNARY_EXPRESSION,
    NODE_TYPE_LITERAL_NUMERIC,
    NODE_TYPE_LITERAL_FLOAT,
    NODE_TYPE_LITERAL_STRING,
    NODE_TYPE_LITERAL_CHAR,
    NODE_TYPE_LITERAL_BOOLEAN,
    NODE_TYPE_LITERAL_NULL,
    NODE_TYPE_IDENTIFIER
} NodeType;

typedef struct ASTNode
{
    NodeType type;
    struct ASTNode* next;
} ASTNode;

typedef struct
{
    ASTNode node;
    bool isConst;
    char* name;
    ASTNode* expression;
} VariableDeclaration;

typedef struct
{
    ASTNode node;
    int value;
} LiteralNumeric;

typedef struct
{
    ASTNode node;
    double value;
} LiteralFloat;

typedef struct
{
    ASTNode node;
    char* value;
} LiteralString;

typedef struct
{
    ASTNode node;
    char value;
} LiteralChar;

typedef struct
{
    ASTNode node;
    bool value;
} LiteralBoolean;

typedef struct
{
    ASTNode node;
} LiteralNull;

ASTNode *parse(Tokens *tokens);

#endif