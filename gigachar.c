#include <stdio.h>
#include <string.h>
#include "gigachar.h"

void putgigachar(gigachar c)
{
    char value = (char)(c & GC_CHAR);

    if((c & GC_BOLD) == GC_BOLD) printf("\e[1m");
    if((c & GC_DIM) == GC_DIM) printf("\e[2m");
    if((c & GC_ITALIC) == GC_ITALIC) printf("\e[3m");
    if((c & GC_UNDERLINE) == GC_UNDERLINE) printf("\e[4m");
    if((c & GC_BLINKING) == GC_BLINKING) printf("\e[5m");
    if((c & GC_INVERSE) == GC_INVERSE) printf("\e[7m");
    if((c & GC_HIDDEN) == GC_HIDDEN) printf("\e[8m");
    if((c & GC_STRIKETROUGH) == GC_STRIKETROUGH) printf("\e[9m");
    putchar(c);
    printf("\e[0m");
}

void printgigastring(gigachar* gigastring)
{
    gigachar *ptr = gigastring;
    while(*ptr != GC_GIGANULL)
    {
        putgigachar(*ptr);
        ptr++;
    }
}

void togigastring(gigachar *buff, size_t buff_length, const char* str, gigachar flags)
{
    int max = strlen(str);

    if(buff_length < max)
    {
        max = buff_length;
    }

    for(int i = 0; i < max; i++)
    {
        buff[i] = str[i] | flags;
    }
}

size_t gigastrlen(const gigachar *str)
{
    int count;
    
    gigachar *ptr = str;
    while(*ptr != GC_GIGANULL)
    {
        ptr++;
    }

    return (ptr-str)/sizeof(gigachar);
}

void gigastrncat(gigachar* destination, const gigachar* source, size_t num)
{
    size_t pos = 0;

    gigachar *ptr = destination+gigastrlen(destination)*sizeof(gigachar);
    gigachar *src_ptr = source;

    while(pos < num && *src_ptr)
    {
        *ptr = *src_ptr;
        ptr++;
        src_ptr++;
        pos++;
    }
}

void gigastrcat(gigachar* destination, const gigachar* source)
{
    gigachar *ptr = destination+gigastrlen(destination)*sizeof(gigachar);
    gigachar *src_ptr = source;

    while(*src_ptr)
    {
        *ptr = *src_ptr;
        ptr++;
        src_ptr++;
    }
}

void gigastrncpy(gigachar* destination, const gigachar* source, size_t num)
{
    size_t pos = 0;

    gigachar *ptr = destination;
    gigachar *src_ptr = source;

    while(pos < num && *src_ptr)
    {
        *ptr = *src_ptr;
        ptr++;
        src_ptr++;
        pos++;
    }

    if(src_ptr < source+num*sizeof(gigachar))
        *ptr = '\0';
}

void gigastrcpy(gigachar* destination, const gigachar* source)
{
    gigachar *ptr = destination-1;
    gigachar *src_ptr = source-1;

    do
    {
        ptr++;
        src_ptr++;
        *ptr = *src_ptr;
    }
    while(*src_ptr);
}

int gigastrcmp(const gigachar* str1, const gigachar* str2)
{
    const gigachar *ptr1 = str1;
    const gigachar *ptr2 = str2;

    while(*ptr1 && *ptr2)
    {
        if((*ptr1 & GC_CHAR) != (*ptr2 & GC_CHAR))
            return *ptr2 & GC_CHAR - *ptr1 & GC_CHAR;

        ptr1++;
        ptr2++;
    }

    return 0;
}

int gigastrcmpfull(const gigachar* str1, const gigachar *str2)
{
    const gigachar *ptr1 = str1;
    const gigachar *ptr2 = str2;

    while(*ptr1 && *ptr2)
    {
        if(*ptr1 != *ptr2)
            return *ptr2 - *ptr1;

        ptr1++;
        ptr2++;
    }

    return 0;
}

int gigastrncmp(const gigachar* str1, const gigachar *str2, size_t num)
{
    size_t pos = 0;

    const gigachar *ptr1 = str1;
    const gigachar *ptr2 = str2;

    while(pos < num && *ptr1 && *ptr2)
    {
        if((*ptr1 & GC_CHAR) != (*ptr2 & GC_CHAR))
            return *ptr2 & GC_CHAR - *ptr1 & GC_CHAR;

        ptr1++;
        ptr2++;
        pos++;
    }

    return 0;
}
int gigastrncmpfull(const gigachar* str1, const gigachar *str2, size_t num)
{
    size_t pos = 0;

    const gigachar *ptr1 = str1;
    const gigachar *ptr2 = str2;

    while(pos < num && *ptr1 && *ptr2)
    {
        if(*ptr1 != *ptr2)
            return *ptr2 - *ptr1;

        ptr1++;
        ptr2++;
        pos++;
    }

    return 0;
}

char tonormalchar(gigachar gc)
{
    return (char)(gc & GC_CHAR);
}
