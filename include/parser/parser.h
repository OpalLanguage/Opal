#ifndef OPAL_PARSER_H
#define OPAL_PARSER_H

typedef enum
{
    NODE_PROGRAM,
    NODE_CLASS_DECLARATION,
    NODE_VARIABLE_DECLARATION,
    NODE_FUNCTION_DECLARATION,
    NODE_STATEMENT,
    NODE_EXPRESSION
} node_type;

typedef struct node
{
    node_type type;
} node;

typedef struct
{
    node base;
    char *name;
} node_class_declaration;

typedef struct
{
    node base;
    char *name;
    node *initializer;
    int isConst;
} node_variable_declaration;

typedef struct
{
    node base;
    char *name;
    node **parameters;
    int paramCount;
    node *body;
} node_function_declaration;

typedef struct
{
    node base;
} node_expression;

#endif