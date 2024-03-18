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

const char* getAssignTypeName(AssignmentType type)
{
    switch (type) {
        case ASSIGN: return "=";
        case ADD_ASSIGN: return "+=";
        case SUB_ASSIGN: return "-=";
        case MUL_ASSIGN: return "*=";
        case DIV_ASSIGN: return "/=";
        default: return "Unknown Assignment Type";
    }
}


void show_parser(Node *node)
{
    while (node != NULL) {
        switch (node->type) {
            case NODE_VARIABLE_ASSIGNMENT:
                printf("Variable Assignment\n  Name: %s\n  Operator: %s\n  Type: %s\n  Value: ",
                       node->data.variableAssignment.identifier,
                       getAssignTypeName(node->data.variableAssignment.assignmentType),
                       getValueTypeName(node->data.variableAssignment.value.type));
                showValue(node->data.variableAssignment.value);
                printf("\n  isConst: %s\n", node->data.variableAssignment.isConst ? "True" : "False");
                break;
            case NODE_FUNCTION_ASSIGNMENT:
                printf("Function Assignment\n  Name: %s\n  Parameters Count: %d\n",
                       node->data.functionAssignmentNode.identifier,
                       node->data.functionAssignmentNode.parametersCount);

                for (int i = 0; i < node->data.functionAssignmentNode.parametersCount; i++) {
                    Parameter param = node->data.functionAssignmentNode.parameters[i];
                    printf("  Parameter %d: Name: %s, Type: %s",
                           i + 1, param.name, getValueTypeName(param.type));

                    printf("\n");
                }

                break;
            default:
                printf("Unknown Node Type\n");
                exit(EXIT_FAILURE);
        }

        node = node->next;
    }
}