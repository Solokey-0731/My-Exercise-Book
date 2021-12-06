#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//P1001
/*
int main()
{
    long a,b;
    scanf("%ld %ld",&a,&b);
    printf("%ld",a+b);
    return 0;
}*/

//P1014
/*
int main()
{
    int N,i,n,N0;
    scanf("%d",&N);
    for(n=1;n*n-n<2*N;n++);//求出此时的n值
    n=n-1;
    N0=(int)(0.5*n*(n-1));
    if(n%2==0) printf("%d/%d",N-N0,n+1-N+N0);
    else printf("%d/%d",n+1-N+N0,N-N0);
    return 0;
}*/

//P1035
/*
int main()
{
    int k;
    long n;
    double s=1;
    scanf("%d",&k);
    for(n=2;s<=(double)k;n++)
    {
        s=s+1.0/(double)n;
    }
    printf("%ld",n-1);
    return 0;
}*/

//P1046
/*
int main()
{
    int a[10],i,height,count=0;
    for(i=0;i<10;i++) scanf("%d",&a[i]);
    getchar();
    scanf("%d",&height);
    for(i=0;i<10;i++) if(a[i]<=height+30) count++;
    printf("%d",count);
    return 0;
}*/

//P1047
/*
int main()
{
    int l,tree[10001],m,i,a[200],x,count=0;
    scanf("%d %d",&l,&m);
    getchar();
    for(i=0; i<2*m; i=i+2)
    {
        scanf("%d %d",&a[i],&a[i+1]);
        getchar();
    }
    for(i=0; i<=l; i++)
    {
        tree[i]=0;
    }
    for(i=0; i<2*m; i=i+2)
    {
        for(x=a[i]; x<=a[i+1]; x++)
        {
            tree[x]=1;
        }
    }
    for(i=0; i<=l; i++)
    {
        if(tree[i]==0) count++;
    }
    printf("%d",count);
    return 0;
}*/

//P1048
/*
void sortof(int* a, int n)
{
    int i, flag = 1, r;
    while (flag)
    {
        flag = 0;
        for (i = 0; i < n - 1; i++)
        {
            if (*(a + i) > *(a + i + 1))
            {
                flag = 1;
                r = *(a + i);
                *(a + i) = *(a + i + 1);
                 *(a + i + 1) = r;
            }
        }
    }
}
int main()
{
    int n, i, count = 0;
    int a[100];
    scanf("%d", &n);
    getchar();
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    sortof(a, n);
    for (i = 0; i < n - 1; i++)
    {
        if (a[i] == a[i + 1])
        {
            a[i] = 0;
            count++;
        }
    }
    sortof(a, n);
    printf("%d\n", n - count);
    for (i = count; i < n; i++) printf((i - count) ? " %d" : "%d", a[i]);
    return 0;
}*/

//P1075 TLE
/*
int check(int x)
{
    int i;
    if(x==1||x==2) return 1;
    else
    {
        for(i=2; i<=x/2; i++)
        {
            if(x%i==0) return 0;
        }
    }
    return 1;
}
int main()
{
    int i,n,n1,flag;
    scanf("%d",&n);
    for(i=2; i<=n/2; i++)
    {
        flag=check(i);
        if(flag==1&&check(n/i)==1&&(n%i==0))
        {
            n1=i;
        }
    }
    printf("%d",n1);
    return 0;
}*/
//P1075 最优解
/*
int main()
{
    int i, n;
    scanf("%d", &n);
    for (i = 2; i <=sqrt(n); i++)
    {
        if(n%i==0)
        {
        printf("%d",n/i);
        return 0;
        }
    }
}*/

//P1085
/*
int main()
{
    int a[14],sum[7],flag=0, m,n;
    for(i=0;i<14;i+=2)
    {
        scanf("%d %d",&a[i],&a[i+1]);
        sum[i/2]=a[i]+a[i+1];
        getchar();
    }
    m=sum[0];
    for(i=0;i<7;i++)
    {
        if(sum[i]>m&&sum[i]>8)
        {
            flag=1;
            m=sum[i];
            n=i+1;
        }
    }
    if(flag==0) printf("0");
    else printf("%d",n);
    return 0;
}*/

//P1089
/*
int main()
{
    int bud[12],i,mama=0,pocket=0,sum=0,flag=1;
    for(i=0;i<12;i++)
    {
        scanf("%d",&bud[i]);
    }
    for(i=0;i<12;i++)
    {
        pocket=pocket+300;
        pocket=pocket-bud[i];
        if(pocket>=100)
        {
            mama=mama+pocket/100*100;
            pocket=pocket%100;
        }
        if(pocket<0&&flag==1)
        {
            flag=0;
            printf("-%d",i+1);
        }
    }
    if(flag==1)
    {
        sum=pocket+mama+mama/5;
        printf("%d",sum);
    }
    return 0;
}*/

//P1116
//书上的冒泡会导致WA
/*
int main()
{
    int N, a[10000], i, flag = 1, count = 0, r, turn = 0;
    scanf("%d", &N);
    for (i = 0; i < N; i++) scanf("%d", &a[i]);
    while(flag)
    {
        for(i=0; i<N-1; i++)
        {
            flag = 0;
            if (a[i] > a[i + 1])
            {
                flag = 1;
                r = a[i];
                a[i] = a[i + 1];
                a[i + 1] = r;
                count++;
            }
        }
        for (i = N - 2; i >0; i--)
        {
            flag = 0;
            if (a[i - 1] > a[i])
            {
                flag = 1;
                r = a[i];
                a[i] = a[i - 1];
                a[i - 1] = r;
                count++;
            }
        }
    }
    printf("%d", count);
    return 0;
}
*/
//冒泡排序的核心是逆序
/*
int main()
{
    int N,i,a[10000],j,count=0,t;
    scanf("%d",&N);
    for(i=0; i<N; i++) scanf("%d",&a[i]);
    for(i=0; i<N-1; i++)
    {
        for(j=i+1; j<N; j++)
        {
            if(a[i]>a[j]) count++;
        }
    }
    for(i=0;i<N-1;i++)
    {
        for(j=0;j<N-1;j++)
        {
            if(a[j]>a[j+1])
            {
                t=a[j+1];
                a[j+1]=a[j];
                a[j]=t;
            }
        }
    }
    printf("%d",count);
    return 0;
}*/

//P1179
/*
int main()
{
    int L,R,i,count=0,N,m;
    scanf("%d %d",&L,&R);
    for(i=L;i<=R;i++)
    {
        N=i;
        while(N>0)
        {
            m=N%10;
            N=N/10;
            if(m==2) count++;
        }
    }
    printf("%d",count);
    return 0;
}*/

//P1200
/*
int main()
{
    char str1[10],str2[10],*s;
    int sum1=1,sum2=1;
    gets(str1);
    getchar();
    gets(str2);
    for(s=str1;*s!='\0';s++) sum1=sum1*(int)(*s-64);
    for(s=str2;*s!='\0';s++) sum2=sum2*(int)(*s-64);
    if(sum1%47==sum2%47) printf("GO");
    else printf("STAY");
    return 0;
}*/

