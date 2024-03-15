#include "../../../include/parser/parsers/parse_literal.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ASTNode* create_literal_numeric(const char* value)
{
    LiteralNumeric* literal = (LiteralNumeric*)malloc(sizeof(LiteralNumeric));
    if (!literal) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    literal->node.type = NODE_TYPE_LITERAL_NUMERIC;
    literal->value = atoi(value);
    return (ASTNode*)literal;
}

ASTNode* create_literal_float(const char* value)
{
    LiteralFloat* literal = (LiteralFloat*)malloc(sizeof(LiteralFloat));
    if (!literal) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    literal->node.type = NODE_TYPE_LITERAL_FLOAT;
    literal->value = atof(value);
    return (ASTNode*)literal;
}

ASTNode* create_literal_boolean(const char* value)
{
    LiteralBoolean* literal = (LiteralBoolean*)malloc(sizeof(LiteralBoolean));
    if (!literal) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    literal->node.type = NODE_TYPE_LITERAL_BOOLEAN;
    literal->value = strcmp(value, "True") == 0;
    return (ASTNode*)literal;
}

ASTNode* create_literal_char(const char* value)
{
    LiteralChar* literal = (LiteralChar*)malloc(sizeof(LiteralChar));
    if (!literal) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    literal->node.type = NODE_TYPE_LITERAL_CHAR;
    literal->value = *value;
    return (ASTNode*)literal;
}

ASTNode* create_literal_string(const char* value)
{
    LiteralString* literal = (LiteralString*)malloc(sizeof(LiteralString));
    if (!literal) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    literal->node.type = NODE_TYPE_LITERAL_STRING;
    literal->value = strdup(value);
    return (ASTNode*)literal;
}

ASTNode* create_literal_null()
{
    LiteralNull* literal = (LiteralNull*)malloc(sizeof(LiteralNull));
    if (!literal) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    literal->node.type = NODE_TYPE_LITERAL_NULL;
    return (ASTNode*)literal;
}

ASTNode* parse_literal(Tokens **tokens)
{
    ASTNode* literalNode = NULL;

    switch ((*tokens)->type) {
        case TOKEN_INT:
            literalNode = create_literal_numeric((*tokens)->value);
            break;
        case TOKEN_FLOAT:
            literalNode = create_literal_float((*tokens)->value);
            break;
        case TOKEN_BOOLEAN:
            literalNode = create_literal_boolean((*tokens)->value);
            break;
        case TOKEN_CHAR:
            literalNode = create_literal_char((*tokens)->value);
            break;
        case TOKEN_STRING:
            literalNode = create_literal_string((*tokens)->value);
            break;
        case TOKEN_NULL:
            literalNode = create_literal_null();
            break;
        default:
            fprintf(stderr, "Syntax error: Unexpected token type for literal.\n");
            exit(EXIT_FAILURE);
    }

    return literalNode;
}