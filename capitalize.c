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

void my_capitalize(char text[])
{
    int hossz = strlen(text);
    if (hossz == 0)
    {
        return;
    }
    my_tolower(text);
    text[0] = toupper(text[0]);
    
}

/*int strcmpi(const char *s, const char *t)
{
    char *p1 = strdup(s);
    char *p2 = strdup(t);

    my_tolower(p1);
    my_tolower(p2);

    int result = strcmp(p1, p2);

    free(p1);
    free(p2);

    return result;
}*/

char * my_capitalizeV2(const char* text)
{
    char *masolat = strdup(text);
    my_capitalize(masolat);
    return masolat;
}

int main()
{
    char szo1[] = "zebra";
    //const char* szo2 = "Zebra";
    printf("elotte: %s\n",szo1);
    char *uj =my_capitalizeV2(szo1);

    printf("%s\n",uj);

    return 0;
}