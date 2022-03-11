// P2249 Binary Search
/*
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int a[1000001];
int n, m;
int BrySearch(int key,int l,int r);
void QuickRead(int i);
int main()
{
    int q;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) QuickRead(i);
    for(int i=0;i<m;i++)
    {
        scanf("%d",&q);
        int mid=BrySearch(q,1,n);
        if(mid!=-1&&mid>=2) 
        {
            int *midd;
            midd=lower_bound(a+1,a+mid+1,a[mid]);
            mid=midd-a;
        }
        printf("%d ",mid);
    }
    return 0;
}
void QuickRead(int i)
{
    int x=0;
    char c=getchar();
    while (c < '0' || c > '9')
    {
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = (x << 3) + (x << 1) + (c ^ 48); // x=x*10+c-'0'
        c = getchar();
    }
    a[i]=x;
    //cout<<x<<' ';
}
int BrySearch(int key, int l, int r)
{
    int mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (a[mid] == key)
            return mid;
        if (a[mid] > key)
            r = mid - 1;
        if (a[mid] < key)
            l = mid + 1;
    }
    return -1;
}*/

// P1102 A-B Problem
/*
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll num[1000010];
void QuickRead(int i);
int main()
{
    ll n,c;
    ll ans=0;
    scanf("%lld %lld",&n,&c);
    for(ll i=1;i<=n;++i) QuickRead(i);
    sort(num+1,num+n+1);
    for(ll i=1;i<=n;++i)
    {
        ans+=upper_bound(num+1,num+n+1,num[i]+c)-lower_bound(num+1,num+n+1,num[i]+c);
    }
    printf("%lld",ans);
}
void QuickRead(ll i)
{
    ll x=0;
    int f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        x=(x<<3)+(x<<1)+(c^48);
        c=getchar();
    }
    num[i]=x*f;
    return;
}*/

