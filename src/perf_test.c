#include <time.h>
double get_perf(clock_t start_clock)
{
    return ((double) (clock() - start_clock)) / CLOCKS_PER_SEC;
}