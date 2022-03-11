// P3383 Linear Prime Fltr
/*
#include<bits/stdc++.h>
#include<cstring>
using namespace std;
#define MAXN 1000010
#define MAXL 100000010
int Prime[MAXN];
bool isPrime[MAXL];
int n,cnt=0;
void GetPrime(int n)
{
    memset(isPrime,1,sizeof(isPrime));
    isPrime[1]=0;
    for(int i=2;i<=n;++i)
    {
        if(isPrime[i])
            Prime[++cnt]=i;
        for(int j=1;j<=cnt&&i*Prime[j]<=n;++j)
        {
            isPrime[i*Prime[j]]=0;
            if(i%Prime[j]==0) break;
        }
    }
}
int main()
{
    int q,x;
    scanf("%d", &n);
    GetPrime(n);
    scanf("%d",&q);
    for(int i=0;i<q;++i) 
    {
        scanf("%d",&x);
        printf("%d\n",Prime[x]);
    }
    return 0;
}*/

// P1226 QuickPow And Mod
#include<bits/stdc++.h>
using namespace std;
long long a,b,ans=1,p,q;
int main()
{
    scanf("%d%d%d",&a,&b,&p);
    int base=a,q=b;
    while(b>0)
    {
        if(b&1) ans=ans*base%p;
        base=base*base%p;
        b>>=1;
    }
    printf("%d^%d mod %d=%lld",a,q,p,ans%p);
    return 0;
}