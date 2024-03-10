#ifndef OPAL_UTILS_H
#define OPAL_UTILS_H

#include "lexer.h"

char get_operator_as_string(enum token_type type);
void show_lexer(tokens *tks);

#endif
