#include "../../include/parser/parser.h"

#include <stdio.h>

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
        default: return "Unknown";
    }
}

void show_parser(Node *node)
{
    while (node != NULL) {
        if (node->type == NODE_VARIABLE_ASSIGNMENT) {
            printf("Variable Assignment\n  Name: %s\n  Type: %s\n  Value: ", node->data.assignment.identifier, getValueTypeName(node->data.assignment.value.type));
            showValue(node->data.assignment.value);
            printf("\n");
        } else {
            printf("Unknown Node Type\n");
        }
        node = node->next;
    }
}