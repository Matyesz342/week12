#include <stdio.h>
#include <string.h>
#include "prog1.h"
#include <stdlib.h>



int main()
{
    char szo[] = "hello";
    char *p;
    p = strdup(szo);
    puts(p);
    free(p);
    return 0;
}