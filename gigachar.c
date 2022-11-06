#include "gigachar.h"

void print(gigachar c)
{
    char value = (char)(c & GC_CHAR);

    if((c & GC_BOLD) == GC_BOLD) printf("\e[1m");
    putchar(c);
    printf("\e[0m");
}