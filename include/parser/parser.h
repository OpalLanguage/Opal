#ifndef OPAL_PARSER_H
#define OPAL_PARSER_H

#include "../lexer/lexer.h"

#include <stdbool.h>

/*
 * UTILS
 */

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

typedef enum
{
    ASSIGN,
    ADD_ASSIGN,
    SUB_ASSIGN,
    MUL_ASSIGN,
    DIV_ASSIGN
} AssignmentType;

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

/*
 * VARIABLE
 */

typedef struct VariableAssignmentNode
{
    bool isConst;
    char* identifier;
    AssignmentType assignmentType;
    Value value;
} VariableAssignmentNode;

/*
 * GLOBAL
 */

typedef struct Node
{
    NodeType type;
    union {
        VariableAssignmentNode variableAssignment;
    } data;
    struct Node *next;
} Node;

Node *parse(Tokens **tokens);
void freeAst(Node *node);

#endif