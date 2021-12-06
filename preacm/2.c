#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// Daffodil
/*
int main()
{
    int i=0;
    for(int a=1;a<10;a++)
    {
        for(int b=0;b<10;b++)
        {
            for(int c=0;c<10;c++)
            {
                if((a*10+b)*10+c==a*a*a+b*b*b+c*c*c)
                {
                    printf(i?" %d":"%d",a*a*a+b*b*b+c*c*c);
                    i += 1;
                }
            }
        }
    }
    return 0;
}*/

// Hanxin

// Triangle
/*
int main()
{
    int n;
    scanf("%d",&n);
    int n0=n;
    while(n>0)
    {
        for(int space=0;space<n0-n;space++) printf(" ");
        for(int i=0;i<2*n-1;i++) printf("*");
        for(int space=0;space<n0-n;space++) printf(" ");
        if(n>1) printf("\n");
        --n;
    }
    return 0;
}*/

// Subsequence


// Decimal
/*
int main()
{
    int a, b, c, flag = 1;
    while (flag)
    {
        scanf("%d %d %d", &a, &b, &c);
        if (a == 0 && b == 0 && c == 0)
            flag = 0;
        if (flag)
        {
            float s = a / b;
        }
    }
    return 0;
}*/

