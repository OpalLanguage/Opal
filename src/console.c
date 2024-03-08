#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *asker()
{
    char *code = malloc(200 * sizeof(char));

    if (code == NULL) {
        perror("malloc");
        return NULL;
    }

    printf("Opal > ");

    if (fgets(code, 200, stdin) == NULL) {
        free(code);
        return NULL;
    }

    code[strcspn(code, "\n")] = '\0';

    return code;
}