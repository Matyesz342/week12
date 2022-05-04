#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX 100
int my_strcmpi(const char a, const char b)
{
    if (a - b == 0 ||  a - b == 32 || b - a == 32)
    {
        return 0;
    }
    else if(a > b)
    {
        return 1;
    }
    else
    {
        return -1;
    }
    
    
}

int main()
{
    char szoveg1[MAX] = "A programozas jo";
    char szoveg2[MAX] = "A prOgramOzAs Jo";
    int hossz1 = strlen(szoveg1);
    int hossz2 = strlen(szoveg2);
    int hossz = 0;
    if (hossz1 > hossz2)
    {
        hossz = hossz1;
    }
    else
    {
        hossz = hossz2;
    }
    char (*a)[MAX];
    char (*b)[MAX];
    a = &szoveg1;
    b = &szoveg2;
    int nagyobb = 0;
    int kisebb = 0;
    int egyenlo = 0;
    for (int i = 0; i < hossz; i++)
    {
        if (my_strcmpi((*a)[i], (*b)[i]))
        {
            nagyobb++;
        }
        else if(my_strcmpi((*a)[i], (*b)[i])== 0)
        {
            
        }
        else
        {
            return -1;
        }
        
    }
    puts("A ket szoveg azonos");
    return 0;
}