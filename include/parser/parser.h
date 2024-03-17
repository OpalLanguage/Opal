#ifndef OPAL_PARSER_H
#define OPAL_PARSER_H

#include "../lexer/lexer.h"

#include <stdbool.h>

typedef enum
{
    NODE_VARIABLE_ASSIGNMENT
} NodeType;

typedef enum
{
    VALUE_INT,
    VALUE_FLOAT,
    VALUE_STRING,
    VALUE_CHAR,
    VALUE_BOOLEAN,
    VALUE_NULL
} ValueType;

typedef struct Value
{
    ValueType type;
    union {
        int intValue;
        double floatValue;
        char* stringValue;
        char charValue;
        bool booleanValue;
    } data;
} Value;

typedef struct VariableAssignmentNode
{
    char* identifier;
    Value value;
} VariableAssignmentNode;

typedef struct Node
{
    NodeType type;
    union {
        VariableAssignmentNode assignment;
    } data;
    struct Node *next;
} Node;

Node *parse(Tokens **tokens);
void freeAst(Node *node);

#endif