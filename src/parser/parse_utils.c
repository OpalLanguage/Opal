#include "../../include/parser/parser.h"

#include <stdio.h>
#include <stdlib.h>

void showValue(Value value)
{
    switch (value.type) {
        case VALUE_INT:
            printf("%d", value.data.intValue);
            break;
        case VALUE_FLOAT:
            printf("%f", value.data.floatValue);
            break;
        case VALUE_STRING:
            printf("\"%s\"", value.data.stringValue);
            break;
        case VALUE_CHAR:
            printf("'%c'", value.data.charValue);
            break;
        case VALUE_BOOLEAN:
            printf("%s", value.data.booleanValue ? "True" : "False");
            break;
        case VALUE_NULL:
            printf("Null value");
            break;
        default:
            printf("Unknown Value Type");
            break;
    }
}

const char* getValueTypeName(ValueType type)
{
    switch (type) {
        case VALUE_INT: return "Integer";
        case VALUE_FLOAT: return "Float";
        case VALUE_STRING: return "String";
        case VALUE_CHAR: return "Character";
        case VALUE_BOOLEAN: return "Boolean";
        case VALUE_NULL: return "Null";
        default: return "Unknown";
    }
}

void show_parser(Node *node)
{
    while (node != NULL) {
        switch (node->type) {
            case NODE_VARIABLE_ASSIGNMENT:
                printf("Variable Assignment\n  Name: %s\n  Type: %s\n  Value: ", node->data.variableAssignment.identifier, getValueTypeName(node->data.variableAssignment.value.type));
                showValue(node->data.variableAssignment.value);
                printf("\n");
                break;
            default:
                printf("Unknown Node Type\n");
                exit(EXIT_FAILURE);
        }

        node = node->next;
    }
}