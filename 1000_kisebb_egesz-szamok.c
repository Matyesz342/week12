#include <stdio.h>

#define MAX 10

int get_result(int i, int n, int total)
{
    if(i<n)
    {
        if (i % 3 == 0 || i % 5 == 0)
        {
            get_result(i+1, n, total+i);
        }
        else
        {
            get_result(i+1, n, total);
        }
    }
    else
    {
        return total;
    }
}

int main()
{
    int result = get_result(1, MAX, 0);
    printf("sum = %d\n", result);
    return 0;
}