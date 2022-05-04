#include <stdio.h>
#include <string.h>
#include "prog1.h"
#include <stdlib.h>
#include <ctype.h>

void my_tolower(char text[])
{
    int hossz = strlen(text);
    for (int i = 0; i < hossz; i++)
    {
        text[i] = tolower(text[i]);
    }
    
}

int strcmpi(const char *s, const char *t)
{
    char *p1 = strdup(s);
    char *p2 = strdup(t);

    my_tolower(p1);
    my_tolower(p2);

    int result = strcmp(p1, p2);

    free(p1);
    free(p2);

    return result;
}

int main()
{
    const char* szo1 = "zebra";
    const char* szo2 = "Zebra";

    int result = strcmpi(szo1, szo2);

    printf("%s vs %s: %d\n",szo1, szo2, result);

    return 0;
}