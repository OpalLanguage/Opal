#include "../../../include/parser/parsers/parse_parameter.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Parameter parse_parameter(Tokens **tokens)
{
    char *name = strdup((*tokens)->value);

    if (name == NULL) {
        fprintf(stderr, "Syntax error: Expected an 'IDENTIFIER' after '(' !\n");
        exit(EXIT_FAILURE);
    }

    *tokens = (*tokens)->next;

    return (Parameter){name, VALUE_INT};
}