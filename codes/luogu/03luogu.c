//STRING
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//指针变量调试代码
/*int main()
{
    char *p[2][3];
    p[0][0]="abc\0";
    p[0][1]="def\0";
    p[1][0]="ghi\0";
    p[1][1]="jkl\0";
    printf("%s",*(*(p+1)+1));
    return 0;
}*/

//P1914 Caesar Cipher
/*int main()
{
    char str[200];
    int n,i;
    scanf("%d",&n);
    scanf("%s",str);
    n=n%26;
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]+n<=122) printf("%c",str[i]+n);
        else printf("%c",str[i]+n-26);
    }
    return 0;
}*/

//P1125 Stupid Monkey
/*
void sort(char a[])
{
    int len = strlen(a), i, j, k, r;
    for (i = 1; i < len; i++)
    {
        j = i - 1;
        while (j >= 0 && (a[j] > a[i]))
            j = j - 1; //search the minimum a[j]
        r = a[i];      //record a[i]
        for (k = i - 1; k >= j + 1; k--)
            a[k + 1] = a[k]; // move behind
        a[j + 1] = r;        //insert a[i] between a[j] and a[j+1]
    }
}
int Primecheck(int x)
{
    if (x == 0||x==1)
        return 0;
    else if(x==2) return 1;
    else
    {
        int i;
        for (i = 2; i <= sqrt(x); i++)
        {
            if (x % i == 0)
                return 0;
        }
        return 1;
    }
}
int main()
{
    char str[101];
    int p[100]; //record the time of each element
    int i, j = 0, length, maxn = 1,minn;
    scanf("%s", str);
    length = strlen(str);
    sort(str);
    for (i = 0; i < 100; i++)
        p[i] = 1;
    for (i = 0; i < length; i++)
    {
        if (str[i] == str[i + 1])
            p[j] += 1;
        else
            j++; //j+1 is the varieties of letters
    }
    minn=p[0];
    for (i = 0; i < j; i++)
    {
        if (p[i] > maxn)
            maxn = p[i];
        if (p[i] < minn)
            minn = p[i];
    }
    if (Primecheck(maxn - minn))
        printf("Lucky Word\n%d",maxn-minn);
    else
        printf("No Answer\n0");
    return 0;
}*/

//P