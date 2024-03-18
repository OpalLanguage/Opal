#ifndef OPAL_PARSER_H
#define OPAL_PARSER_H

#include "../lexer/lexer.h"

#include <stdbool.h>

typedef struct Node Node;

/*
 * UTILS
 */

typedef enum
{
    NODE_VARIABLE_ASSIGNMENT,
    NODE_FUNCTION_ASSIGNMENT
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
        char *stringValue;
        char charValue;
        bool booleanValue;
    } data;
} Value;

typedef struct Parameter
{
    char *name;
    ValueType type;
} Parameter;

/*
 * VARIABLE
 */

typedef struct VariableAssignmentNode
{
    bool isConst;
    char *identifier;
    AssignmentType assignmentType;
    Value value;
} VariableAssignmentNode;

/*
 * FUNCTION
 */

typedef struct FunctionAssignmentNode
{
    char *identifier;
    Parameter *parameters;
    int parametersCount;
    //Node* body;
} FunctionAssignmentNode;

/*
 * GLOBAL
 */

struct Node
{
    NodeType type;
    union {
        VariableAssignmentNode variableAssignment;
        FunctionAssignmentNode functionAssignmentNode;
    } data;
    struct Node *next;
};

Node *parse(Tokens **tokens);
void freeAst(Node *node);

#endif