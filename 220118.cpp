// Quick Pow
/*
#include<bits/stdc++.h>
using namespace std;
int QuickPowR(int a,int n)//Recursion
{
    if(n==0) return 1;
    else if(n%2==1) return QuickPowR(a,n-1)*a;
    else
    {
        int tmp=QuickPowR(a,n/2);
        return tmp*tmp;
    }
}
int QuickPowL(int a,int n)//Loop
{
    int ans=1;
    while(n)
    {
        if(n&1)//the last bit of n is 1
            ans*=a;
        a*=a;
        n>>=1;//n/2
    }
    return ans;
}
//Combined with HighPrecisionComputation
int main()
{
    int a,n;
    cin>>a>>n;
    int x=QuickPowL(a,n);
    cout<<x;
    return 0;
}
int ansh[6400000]=0;
int* QuickPowH(int a,int n)
{

}
char d[6200000];
void HighMlt(char b[],char c[])
{
    int b1[3100000],c1[3100000];
    int d1[6200000];
    char d[6200000];
    memset(b1,0,sizeof(b1));
    memset(c1,0,sizeof(c1));
    memset(d1,0,sizeof(d1));
    int i,j;
    int lenb=strlen(b),lenc=strlen(c),lend;
    for(i=0;i<=lenb-1;i++) b1[lenb-i]=b[i]-48;
    for(i=0;i<=lenc-1;i++) c1[lenc-i]=c[i]-48;
    for(i=1;i<=lenb;i++)
    {
        x=0;
        for(j=1;j<=lenc;i++)
        {
            d1[i+j-1]=b1[i]*c1[j]+x+c1[i];
            d1[i+j-1]%=10;
        }
        d1[i+lenb]=x;
    }
    lend=lenb+lenc;
    while(d1[lend]==0&&lend>1)
    {
        lend--;
    }
    for(i=lend;i>=1;i--)
    {

    }
}
void HighMult(int d[],int e)
{
    int stp=0;
    for(int i=1;i<1000;i++)
    {
        d[i]=d[i]*e+stp;
        stp=d[i]/10;
        d[i]%=10;
    }
}*/

// P1042 Pinpong
/*
int cpt[62501]={0};
int main()
{
    int aw,bw;
    int i=0;
    char x;
    int flag=1;
    while(flag)//Input
    {
        cin>>x;
        if(x=='W') 
        {
            cpt[i]=1;
            i+=1;
        }
        if(x=='L') 
        {
            cpt[i]=-1;
            i+=1;
        }
        if(x=='E') flag=0;
    }
    i=0;
    aw=0;
    bw=0;
    while(cpt[i]!=0)
    {
        if(cpt[i]==1) 
        {
            aw+=1;
        }
        if(cpt[i]==-1)
        { 
            bw+=1;
        }
        i+=1;
        if((aw>=11||bw>=11)&&(aw-bw>=2||aw-bw<=-2)) 
        {
            cout<<aw<<':'<<bw<<endl;
            aw=0;
            bw=0;
        }
    }
    cout<<aw<<':'<<bw<<endl;
    cout<<endl;
    i=0;
    aw=0;
    bw=0;
    while(cpt[i]!=0)
    {
        if(cpt[i]==1) 
        {
            aw+=1;
        }
        if(cpt[i]==-1)
        { 
            bw+=1;
        }
        i+=1;
        if((aw>=21||bw>=21)&&(aw-bw>=2||aw-bw<=-2)) 
        {
            cout<<aw<<':'<<bw<<endl;
            aw=0;
            bw=0;
        }
    }
    cout<<aw<<':'<<bw<<endl;
    return 0;
}*/

// P1098 String 

// P1591 Factorial Digital
/*
#include<bits/stdc++.h>
using namespace std;
void HighMult(int a[],int n)
{
    int stp=0;
    for(int i=1;i<2600;i++)
    {
        a[i]=a[i]*n+stp;
        stp=a[i]/10;
        a[i]%=10;
    }
}
int main()
{
    int t,n,a;
    cin>>t;
    int i,j;
    int num[2600];
    int flag=0,len,count=0;
    for(j=0;j<t;j++)
    {
        flag=0;
        count=0;
        memset(num,0,sizeof(num));
        num[1]=1;
        cin>>n>>a;
        for(i=1;i<=n;i++)
        {
            HighMult(num,i);
        }
        for(i=2599;i>=1;i--)
        {
            if(num[i]!=0) 
            {
                flag=1;
                break;
            }
        }
        len=i;
        for(i=len;i>=1;i--)
        {
            if(num[i]==a) count+=1;
        }
        cout<<count<<endl;
    }
    return 0;
}*/

//
/*
#include<bits/stdc++.h>
using namespace std;
long long QuickPow(int a, int n,int M)
{
    long long ans = 1,base=a;
    while (n)
    {
        if (n & 1) // the last bit of n is 1
            ans = base*ans%M;
        base = base*base%M;
        n >>= 1; // n/2
    }
    return ans;
}
int main()
{
    int Z,M,H,a,b;
    long long md=0;
    cin>>Z;
    while(Z--)
    {
        cin>>M>>H;
        for(int i=0;i<H;i++)
        {
            cin>>a>>b;
            md = md + QuickPow(a,b,M);
        }
        md=md%M;
        cout<<md<<endl;
        md=0;
    }
    return 0;
}*/

/*
#include <cstdio>
long long pow(int n, int m, int mod)
{
    long long ans = 1, base = n;
    while (m)
    {
        if (m & 1)
        {
            ans = base * ans % mod;
        }
        base = base * base % mod;
        m >>= 1;
    }
    return ans;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int mod, n, a, b;
        int modd = 0;
        scanf("%d %d", &mod, &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d", &a, &b);
            modd += pow(a, b, mod);
        }
        modd %= mod;
        printf("%d\n", modd);
    }
    return 0;
}*/
 
// P2052 NOI2011 Road Construction
/*
#include<iostream>
#include<cmath>
using namespace std;
const int maxn=10000010;
#define ll long long
ll n,m,ans=0,sum[maxn],head[maxn];
struct TreeNode
{
    ll val,len,nxt;
}TNode[2*maxn];

void AddEdge(ll sn,ll vl,ll len)
{
    m+=1;
    TNode[m].nxt=head[sn];
    TNode[m].val=vl;
    TNode[m].len=len;
    head[sn]=m;
}
void Dfs(ll cur,ll prt)
{
    sum[cur]=1;
    for(ll i=head[cur];i;i=TNode[i].nxt)
    {
        if(TNode[i].val!=prt)
        {
            Dfs(TNode[i].val,cur);
            ans=ans+abs(sum[TNode[i].val]-n+sum[TNode[i].val])*TNode[i].len;
            sum[cur]+=sum[TNode[i].val];
        }
    }
}
int main()
{
    cin>>n;
    ll sn,vl,len;
    ll i;
    for(i=1;i<n;i++)
    {
        cin>>sn>>vl>>len;
        AddEdge(sn,vl,len);
        AddEdge(vl,sn,len);
    }
    Dfs(1,0);
    cout<<ans;
    return 0;
}*/

// Strange Integers
/*
#include<bits/stdc++.h>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
    int n,k,max;
    int num[100010];
    cin>>n>>k;
    for(int i=1;i<=n;i++) scanf("%d",&num[i]);
    sort(num+1,num+n+1);
    //可以排序的理由：排序后，相邻两数之间的差值最小，便于筛查
    //为什么排序不会影响结果（Q1)
    //如果k!=0，排序可以筛除相同元素，因为相同元素差值为0
    int m=1;
    max=num[n];//从最大开始，不能从最小的数开始算（Q2）
    for(int i=n-1;i>=1;i--)//从第二大的数开始减
    {
        if(abs(num[i]-max)>=k)
        {
            max=num[i];//如果差值>=k，说明满足条件，m+1，同时，Abj改变,找下一对满足条件的
            m++;
        }//如果不满足条件，则找更小的数，使得条件满足
    }
    printf("%d",m);
    return 0;
}*/




