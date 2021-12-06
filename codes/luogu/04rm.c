#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//P2615
/*
int main()
{
    int n, i, j,k=2, a[1521];
    scanf("%d", &n);
    for(i=0;i<n*n;i++) a[i]=0;
    i = 0;
    j = (n - 1) / 2;
    a[(n-1)/2]=1;
    while (k <= n * n)
    {
        if (i == 0 && j != n - 1)
        {
            i = n - 1;
            j = j + 1;
        }
        else if (i != 0 && j == n - 1)
        {
            j = 0;
            i = i - 1;
        }
        else if (i == 0 && j == n - 1)
            i = i + 1;
        else if (i != 0 && j != n - 1)
        {
            if (a[i * n + j - n + 1] != 0)
                i = i + 1;
            else
            {
                i = i - 1;
                j = j + 1;
            }
        }
        a[i * n + j] = k;
        k += 1;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (j == n - 1)
                printf("%d\n", a[i * n + j]);
            else
                printf("%d ", a[i * n + j]);
        }
    }
    return 0;
}*/


