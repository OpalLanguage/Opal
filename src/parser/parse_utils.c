#include "../../include/parser/parser.h"

#include <stdio.h>
#include <stdlib.h>

void show_parser(ASTNode *astNode)
{
    while (astNode != NULL) {
        switch (astNode->type) {
            case NODE_TYPE_CLASS_DECLARATION:
                break;
            case NODE_TYPE_VARIABLE_DECLARATION: {
                VariableDeclaration *varDecl = (VariableDeclaration*)astNode;
                printf("Variable Declaration: %s = ", varDecl->name);

                if (varDecl->expression != NULL) {
                    switch (varDecl->expression->type) {
                        case NODE_TYPE_LITERAL_NUMERIC: {
                            LiteralNumeric *num = (LiteralNumeric*)varDecl->expression;
                            printf("%d\n  Type: INT\n", num->value);
                            break;
                        }
                        case NODE_TYPE_LITERAL_FLOAT: {
                            LiteralFloat *flt = (LiteralFloat*)varDecl->expression;
                            printf("%f\n  Type: FLOAT\n", flt->value);
                            break;
                        }
                        case NODE_TYPE_LITERAL_CHAR: {
                            LiteralChar *ch = (LiteralChar*)varDecl->expression;
                            printf("\'%c\'\n  Type: CHAR\n", ch->value);
                            break;
                        }
                        case NODE_TYPE_LITERAL_STRING: {
                            LiteralString *str = (LiteralString*)varDecl->expression;
                            printf("\"%s\"\n  Type: STRING\n", str->value);
                            break;
                        }
                        case NODE_TYPE_LITERAL_BOOLEAN: {
                            LiteralBoolean *bln = (LiteralBoolean*)varDecl->expression;
                            printf("%s\n  Type: BOOLEAN\n", bln->value ? "True" : "False");
                            break;
                        }
                        case NODE_TYPE_LITERAL_NULL: {
                            printf("Null\n  Type: NULL\n");
                            break;
                        }
                        default:
                            printf("Unsupported expression type in variable declaration\n");
                            break;
                    }
                } else {
                    printf("Undefined\n");
                }
                break;
            }
            case NODE_TYPE_FUNCTION_DECLARATION:
                break;
            case NODE_TYPE_PARAMETER:
                break;
            case NODE_TYPE_BLOCK:
                break;
            case NODE_TYPE_STATEMENT:
                break;
            case NODE_TYPE_IF_STATEMENT:
                break;
            case NODE_TYPE_ELSEIF_STATEMENT:
                break;
            case NODE_TYPE_ELSE_STATEMENT:
                break;
            case NODE_TYPE_WHILE_STATEMENT:
                break;
            case NODE_TYPE_ASSIGNMENT:
                break;
            case NODE_TYPE_FUNCTION_CALL:
                break;
            case NODE_TYPE_RETURN_STATEMENT:
                break;
            case NODE_TYPE_LOG_STATEMENT:
                break;
            case NODE_TYPE_EXPRESSION:
                break;
            case NODE_TYPE_BINARY_EXPRESSION:
                break;
            case NODE_TYPE_FUNCTION_CALL_EXPRESSION:
                break;
            case NODE_TYPE_UNARY_EXPRESSION:
                break;
            case NODE_TYPE_LITERAL_NUMERIC:
                break;
            case NODE_TYPE_LITERAL_STRING:
                break;
            case NODE_TYPE_LITERAL_BOOLEAN:
                break;
            case NODE_TYPE_LITERAL_NULL:
                break;
            case NODE_TYPE_IDENTIFIER:
                break;
            case NODE_TYPE_LITERAL_FLOAT:
                break;
            case NODE_TYPE_LITERAL_CHAR:
                break;
            default:
                printf("Unknown type for parser. (Type: %u)", astNode->type);
                exit(EXIT_FAILURE);
        }

        astNode = astNode->next;
    }
}