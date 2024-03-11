#include "../include/console.h"
#include "../include/file_loader.h"
#include "../include/lexer/lexer.h"
#include "../include/lexer/utils.h"
#include "../include/perf_test.h"

#include <stdlib.h>

int main(void)
{
    clock_t start_clock = clock();

   // char *code = asker();
    char *code = get_code("../opal/main.opal");
    tokens *tks = lexer(code);

    show_lexer(tks);
    printf("Exec time -> %f seconds\n", get_perf(start_clock));

    free(code);
    free(tks);
    return 0;
}