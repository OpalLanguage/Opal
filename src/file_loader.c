#include <stdio.h>
#include <stdlib.h>

char *getCode(char *path)
{
    FILE *file = fopen(path, "rb");
    if (file == NULL) {
        perror("Error by opening file");
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *content = (char*)malloc(length + 1);
    if (content == NULL) {
        perror("malloc");
        fclose(file);
        exit(1);
    }

    fread(content, 1, length, file);
    content[length] = '\0';
    fclose(file);

    return content;
}