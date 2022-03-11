// HighPrecision Addtion 
/*
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[2001],b[2001],c[2001];
char al[2002],bl[2002];
int main()
{
    int la,lb,lc,x=0;
    gets(al);gets(bl);
    la=strlen(al);lb=strlen(bl);
    for(int i=0;i<la;++i) a[la-i]=al[i]-48;
    for(int i=0;i<lb;++i) b[lb-i]=bl[i]-48;
    lc=1;
    while(lc<=la||lc<=lb)
    {
        c[lc]=a[lc]+b[lc]+x;
        x=c[lc]/10;
        c[lc]%=10;
        lc++;
    }
    c[lc]=x;
    while(c[lc]==0) lc--;
    for(int i=lc;i>=1;--i) printf("%d",c[i]);
    return 0;
}*/

// HighPrecision Subtraction
/*
#include<cstdio>
#include<cstring>
using namespace std;
char s1[1002],s2[1002],n[1002];
int a[1001],b[1001];
int main()
{
    scanf("%s",s1);scanf("%s",s2);
    if(strlen(s1)<strlen(s2)||(strlen(s1)==strlen(s2)&&strcmp(s1,s2)<0))
    {
        strcpy(n,s1);
        strcpy(s1,s2);
        strcpy(s2,n);
        printf("-");
    }
    int la=strlen(s1),lb=strlen(s2);
    for(int i=la-1;i>=0;--i) a[la-i]=s1[i]-48;
    for(int i=lb-1;i>=0;--i) b[lb-i]=s2[i]-48;
    for(int i=1;i<=la;++i)
    {
        a[i]-=b[i];
        if(a[i]<0) 
        {
            a[i]+=10;
            a[i+1]--;
        }
    }
    while(a[la]!=0) la--;
    for(int i=la;i>=1;--i) printf("%d",a[i]);
    return 0;
}*/

// HighPrecision Multiplication high×low 2^n

// Method 1
/*
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,s,a[10001],len=1;
int main()
{
    scanf("%d",&n);
    a[1]=1;
    for(int k=1;k<=n;++k) 
    {
        for(int i=1;i<=len;++i) a[i]*=2;
        for(int i=1;i<=len;++i) 
        {
            s=0;
            if(a[i]>9) 
            {
                a[i+1]+=a[i]/10;
                a[i]%=10;
                s=max(s,i+1);
            }
        }
        len=max(len,s);
    }
    for(int i=len;i>=1;--i) printf("%d",a[i]);
    return 0;
}*/

// Method 2
/*
#include<cstdio>
using namespace std;
int a[10001];
int main()
{
    int n,i,j,x,len=1;
    scanf("%d",&n);
    a[1]=1;
    for(i=1;i<=n;++i) 
    {
        x=0;
        for(j=1;j<=len;++j)
        {
            a[j]=a[j]*2+x;
            x=a[j]/10;
            a[j]%=10;
            if(x!=0&&j==len) len++;
        }
    }
    for(int i=len;i>=1;i--) printf("%d",a[i]);
    return 0;
}*/

// The Divisor of a large number
/*
#include<cstdio>
#include<cstring>
using namespace std;
char c[31];// at most 30 digits
int i,k,n,flag=0,t;
int main()
{
    scanf("%s",c+1);// From c[1] to c[n]
    n=strlen(c+1);
    for(k=2;k<=9;k++) 
    {
        t=0;
        for(i=1;i<=n;i++)
        {
            t=t*10+c[i]-48;
            t%=k;
        }
        if(t==0) 
        {
            flag=1;
            printf("%d",k);
        }
    }
    if(flag) printf("\n");
    else printf("none");
    return 0;
}*/

// Factorial at most 10000
/*
#include<cstdio>
#include<cstring>
using namespace std;
int a[40010],n,x,len=1;
int main()
{
    scanf("%d",&n);
    a[1]=1;
    for(int i=1;i<=n;++i)
    {
        x=0;
        for(int j=1;j<=len;++j)
        {
            a[j]=a[j]*i+x;
            x=a[j]/10;
            a[j]=a[j]%10;
            if(x>0&&j>=len) len++;
        }
    }
    for(int i=len;i>=1;--i) printf("%d",a[i]);
    return 0;
}*/

// Check and ReWrite by myself
