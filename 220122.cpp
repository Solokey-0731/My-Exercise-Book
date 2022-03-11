// Greedy Algorithm

// P1223 Greedy Algorithm 
// struct sort!
/*
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef struct quq
{
    int srlnum;
    int tme;
}qu;
qu quq[1001];
bool cmp(qu x,qu y)
{
    return x.tme<y.tme;
}
int main()
{
    int n;
    double avg=0;
    scanf("%d",&n);
    for(int i=1;i<=n;++i) 
    {
        quq[i].srlnum=i;
        scanf("%d",&quq[i].tme);
    }
    sort(quq+1,quq+n+1,cmp);
    for(int i=1;i<=n;++i) 
    {
        printf((i-1)?" %d":"%d",quq[i].srlnum);
        avg=avg+(1.0*(n-i)*quq[i].tme/n);
    }
    printf("\n%.2f",avg);
    return 0;
}*/

// P1208 Mixing Milk
/*
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef struct MilkFarm
{
    int price;
    int amount;
}MkFarm;
MkFarm mkf[5001];
bool cmp(MkFarm x,MkFarm y)
{
    return x.price<y.price;
}
int main()
{
    int n,m,sum=0,ans=0,amti;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++) 
    {
        scanf("%d %d",&mkf[i].price,&mkf[i].amount);
    }
    sort(mkf,mkf+n,cmp);
    for(int i=0;sum<n;i++)
    {
        sum+=mkf[i].amount;
        amti=mkf[i].amount;
        if(sum>n) 
            amti=n-(sum-mkf[i].amount);
        ans+=amti*mkf[i].price;
    }
    printf("%d",ans);
    return 0;
}*/

// P5019 Paved Road
/*
#include<bits/stdc++.h>
using namespace std;
#define MAXN 100001
long long ans;
int dpt[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&dpt[i]);
    for(int i=2;i<=n;i++) if(dpt[i]>dpt[i-1]) ans+=dpt[i]-dpt[i-1];
    printf("%lld",ans+dpt[1]);
    return 0;
}*/

// P1090 Combine the fruit piles
#include<bits/stdc++.h>
using namespace std;
int a[10001];
int main()
{
    int n,egy=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[n]);
    
    return 0;
}

// P1044 Stack Catalan Algorithm
/*
#include<bits/stdc++.h>
#define MAXN 20
#define ll long long
using namespace std;
ll Cmb[2*MAXN][MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=2*n;++i)
    {
        Cmb[i][0]=Cmb[i][i]=1;
        for(int j=1;j<i;++j)
            Cmb[i][j]=Cmb[i-1][j]+Cmb[i-1][j-1];
    }
    printf("%lld",Cmb[2*n][n]-Cmb[2*n][n-1]);
    return 0;
}*/
