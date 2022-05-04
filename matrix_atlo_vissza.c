#include <stdio.h>

void kiir_matrix(int n, int matrix[n][n])
{
    int j = 0;
    for (int i = n-1; i >= 0; i--)
    {
        printf("%d\t", matrix[j][i]);
        j++;
    }
    
}

int main()
{
    int matrix[6][6] = {
        {1, 2, 3, 4, 5, 6},
        {11, 12, 13, 14, 15, 16},
        {56, 74, 32, 64, 128, 43},
        {43, 44, 45, 46, 23, 65},
        {9, 8, 7, 6, 5, 0},
        {94, 82, 77, 61, 53, 10}
    };
    int n = 6;
    kiir_matrix(n, matrix);

    puts("END");
    return 0;
}