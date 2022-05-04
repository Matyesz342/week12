#include <stdio.h>
#include <string.h>
#include "prog1.h"

int main()
{
    char szo[] = "hello";
    char cell[100];

    strcpy(cell, szo);

    puts(cell);
    return 0;
}