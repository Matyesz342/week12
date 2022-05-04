#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX 100
int my_strcmpi(const char* a, const char* b)
{
    int hossz1 = strlen(a);
    int hossz2 = strlen(b);
    if (hossz1 != hossz2)
    {
        return false;
    }
    
    char (*ptr1)[MAX];
    char (*ptr2)[MAX];
    ptr1 = &a;
    ptr2 = &b;
    for (int i = 0; i < hossz1; i++)
    {
        if (((*ptr1)[i] - (*ptr2)[i] == 0 ||  (*ptr1)[i] - (*ptr2)[i] == 32 || (*ptr2)[i] - (*ptr1)[i] == 32) == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    char szoveg1[MAX] = "A programozas jo";
    char szoveg2[MAX] = "A prOgramOzAs Jo";
    //char *a = szoveg1;
    //char *b = szoveg2;
    if(my_strcmpi(szoveg1, szoveg2) == false)
    {

    }
    puts("A ket szoveg azonos");
    
    return 0;
}