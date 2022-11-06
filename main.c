#include <stdio.h>
#include <stdlib.h>
#include "gigachar.h"

void main(int argc, char *argv[])
{
    gigachar c = 'c' | GC_BOLD | GC_INVERSE | GC_STRIKETROUGH;
    gigachar c1 = 'c' | GC_DIM |GC_ITALIC;
    gigachar c2 = 'c' | GC_ITALIC;

    gigachar* str = malloc(4*sizeof(gigachar));

    str[0] = c;
    str[1] = c1;
    str[2] = c2;
    str[3] = GC_GIGANULL;

    printgigastring(str);

    putchar('\n');

    const char *normalStr1 = "jeblalalalalalalala ";
    const char *normalStr2 = "jebac pis";
    
    gigachar popierdolonyStr[100];
    sprintgigastring(popierdolonyStr, 100, normalStr1, GC_BOLD | GC_STRIKETROUGH);

    gigachar popierdolonyStr2[100];
    sprintgigastring(popierdolonyStr2, 100, normalStr2, GC_BOLD | GC_UNDERLINE);
 printf("%d", gigastrncmp(popierdolonyStr2, popierdolonyStr, 3));
    gigastrcpy(popierdolonyStr, popierdolonyStr2);
    printgigastring(popierdolonyStr);

   


    printf("----------------------------\n");
}