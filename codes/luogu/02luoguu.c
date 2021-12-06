#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//P1008
/*
void sort1(int *num)
{
    int i,flag=1,r;
    while(flag)
    {
        flag=0;
        for(i=0; i<5; i++)
        {
            if(*(num+i)>*(num+i+1))
            {
                flag=1;
                r=*(num+i);
                *(num+i)=*(num+i+1);
                *(num+i+1)=r;
            }
        }
    }
}
int check(int a,int b,int c)
{
    int p=100*a+10*b+c;
    int q=2*p,r=3*p,i=0;
    int n[6];
    while(q>0)
    {
        n[i]=q%10;
        q=q/10;
        i++;
    }
    while(r>0)
    {
        n[i]=r%10;
        r=r/10;
        i++;
    }
    sort1(n);
    for(i=0; i<5; i++) if(n[i]==n[i+1]||n[i]==0) return 0;
    for(i=0; i<6; i++)
    {
        if(n[i]==a||n[i]==b||n[i]==c) return 0;
    }
    return 1;
}

int main()
{
    int a,b,c,flag=0,count=0,number;
    for(a=1; a<4; a++)
    {
        for(b=1; b<10; b++)
        {
            for(c=1; c<10; c++)
            {
                flag=0;
                if(a!=b&&b!=c&&a!=c)
                {
                    flag=check(a,b,c);
                    if(flag==1)
                    {
                        if(count!=0) printf("\n");
                        number=100*a+10*b+c;
                        printf("%d %d %d",number,2*number,3*number);
                        count++;
                    }
                }

            }
        }
    }
    return 0;
}
*/

//P1009

//P1010
int main()
{
    int n,i,j,a[15],count;
    scanf("%d",&n);
    i=0;
    while(n>0)
    {
        a[i]=n%2;
        n=n/2;
        i++;
    }
    for(i=14; i>=0; i--) 
    {
        if(a[i]==1)
        {
            j=i;
            count=0;
        }
    }
}

//P1011 Stations

int main()
{
    int a, n, m, x, i, b[20], r, flag = 1, y;
    scanf("%d %d %d %d", &a, &n, &m, &x);
    if (x == 1 || x == 2)
        r = a;
    else
    {
        b[0] = 0;
        b[1] = a;
        y = 0;
        r = a;
        while (flag)
        {
            b[2] = y;
            r = a;
            for (i = 3; i < n; i++)
            {
                r = r + b[i - 1] + b[i - 2];
                b[i] = b[i - 1] + b[i - 2];
                r = r - b[i - 1];
            }
            if (m == r)
                flag = 0;
            else
                y++;
        }
        b[2] = y;
        r = a;
        for (i = 3; i <= x; i++)
        {
            r = r + b[i - 1] + b[i - 2];
            b[i] = b[i - 1] + b[i - 2];
            r = r - b[i - 1];
        }
    }
    printf("%d", r);
    return 0;
}
