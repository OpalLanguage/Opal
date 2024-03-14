#ifndef OPAL_LEX_DECLARATION_H
#define OPAL_LEX_DECLARATION_H

#include "../lexer.h"

#include <stdbool.h>

bool lex_declaration(Tokens **tks, char **code);

#endif
