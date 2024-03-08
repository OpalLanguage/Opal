#include "../include/console.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(void)
{
    while (true) {
        char *code = asker();

        printf("%s\n", code);
        free(code);
    }

    return 0;
}