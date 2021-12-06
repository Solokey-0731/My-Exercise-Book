//Algorithm 1-1 Simulation and High Precision
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//P1601 A+B Problem HP
//Halfdone
/*
int max(int a,int b)
{
    if (a>b) return a;
    else return b;
}
int *addition(char *a, char *b, int lena, int lenb)
{
    int am[1005],bm[1005],i,len;
    for(i=0;*(a+i)!='\0';i++) am[i]=*(a+i)-48;
    for(i=0;*(b+i)!='\0';i++) bm[i]=*(b+i)-48;//Input char->int
    int c[1006];
    len=max(lena,lenb);
    if (lena > lenb)//Fill 0
    {
        for (i = lenb - 1; i >= 0; i--) bm[i+lena-lenb]=bm[i];
        for (i = 0; i < lena - lenb; i++) bm[i] = 0;
    }
    else if(lena < lenb) 
    {
        len = lenb;
        for (i = lena - 1; i >= 0; i--)
        {
            am[i+lenb - lena]=a[i];
        }
        for (i = 0; i < lenb - lena; i++)
        {
            am[i] = 0;
        }
    }
    for(i=0;i<=len;i++) c[i]=0;//Empty the array c
    for (i = 0; i < len; i++)
    {
        c[len - i] =c[len-i]+ am[len-i-1]+bm[len-i-1]; //Add every bits
        if (c[len - i]>= 10)
        {
            c[len - i - 1]+= 1;
            c[len - i] %= 10;
        }
    }
    int *pc=c;
    return pc;
}
int main()
{
    char a[1006], b[1006];
    int lena, lenb,len,*p,i;
    scanf("%s",a);
    getchar();
    scanf("%s",b);
    lena = strlen(a);
    lenb = strlen(b);
    len=max(lena,lenb);
    p=addition(a, b, lena, lenb); 
    if(*(p+0)!=0) for(i=0;i<=len;i++) printf("%d",*(p+i));//Don't print the first 0
    else for(i=1;i<=len;i++) printf("%d",*(p+i));
    return 0;
}*/

//P1303 A*B Problem HP
/*
int main()
{
    int am[2000],bm[2000],i,j,lena,lenb,len,c[4002];
    char a[2001],b[2001];
    scanf("%s",a);
    getchar();
    scanf("%s",b);
    lena=strlen(a);
    lenb=strlen(b);
    len = lena + lenb;
    for(i=lena;i>=1;i--) am[i]=a[lena-i]-48;//reverse input char->int
    for(i=lenb;i>=1;i--) bm[i]=b[lenb-i]-48;
    for(i=1;i<len;i++) c[i]=0; 
    for(i=1;i<=lenb;i++)
    {
        for(j=1;j<=lena;j++)
        {
            c[i+j-1]+=am[j]*bm[i];
        }
    }
    for(i=1;i<len;i++)
    {
        if(c[i]>=10)
        {
            c[i+1]+=c[i]/10;
            c[i]%=10;
        }
    }
    while (c[len] == 0 && len > 1) len--;
    for (i = len; i >= 1; i--) printf("%d", c[i]);
    return 0;
}

int lena, lenb, len;
int *multiplication(int *a, int *b)
{
    int c[65], i, j;
    for (i = 1; i < 65; i++)
        c[i] = 0;
    for (i = 1; i <= lenb; i++)
    {
        for (j = 1; j <= lena; j++)
        {
            c[i + j - 1] += *((a + j)) * (*(b + i));
        }
    }
    for (i = 1; i < len; i++)
    {
        if (c[i] >= 10)
        {
            c[i + 1] += c[i] / 10;
            c[i] %= 10;
        }
    }
    while (c[len] == 0 && len > 1)
        len--;
    return c;
}
int *factorial(int n)
{
    int a[65], i = 1;
    if (n == 1)
    {
        a[1] = 1;
        return &(a[0]) + 1;
    }
    else
    {
        int n0 = n;
        while (n0 > 0)
        {
            a[i] = n0 % 10;
            n0 /= 10;
            ++i;
        }
        return multiplication(&(a[0]) + 1, *factorial(n - 1));
    }
}*/
