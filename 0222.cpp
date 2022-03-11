// Problem A solution1: sort
/*
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int stk[50010],n,top=1;
struct node
{
    int val;
    int id;
}a[50010];
bool cmp(struct node c,struct node d)
{
    if(c.val!=d.val) return c.val<d.val;
    else return c.id<d.id;
}
int main()
{
    scanf("%d",&n);
    int ans=0;
    for(int i=0;i<n;i++) 
    {
        scanf("%d",&a[i].val);
        a[i].id=i;
    }
    sort(a,a+n,cmp);
    int idx=0;
    for(int i=0;i<n;++i)
    {
        if(i==0||idx>a[i].id) idx=a[i].id;
        else ans=max(ans,a[i].id-idx);
    }
    printf("%d",ans);
    return 0;
}*/

// Problem A solution 2: monotonous stack

// Problem B solution 1: mergesort
/*
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
long long ans=0;
struct point
{
    int x,y;
}pt[50010];
int numy[50010];
bool cmp(struct point a, struct point b)
{
    if(a.x!=b.x) return a.x<b.x;
    else return a.y<b.y;
}
void mergesort(int l,int r)
{
    if(l==r) return ;
    int mid=(l+r)>>1;
    mergesort(l,mid);
    mergesort(mid+1,r);
    int i=l,j=mid+1,tot=l;
    while(i<=mid&&j<=r)
    {
        if(pt[i].y<=pt[j].y) numy[tot++]=pt[i++].y;
        else
        {
            ans+=(long long)(mid-i+1);
            numy[tot++]=pt[j++].y;
        }
    }
    while(i<=mid) numy[tot++]=pt[i++].y;
    while(j<=r) numy[tot++]=pt[j++].y;
    for(int k=l;k<=r;k++) pt[k].y=numy[k];
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%d%d",&pt[i].x,&pt[i].y);
    sort(pt+1,pt+n+1,cmp);
    mergesort(1,n);
    printf("%lld\n",ans);
    return 0;
}*/

// Problem B solution 2: BIT

// Problem C solution: search for reverse
/*
#include<cstdio>
#include<algorithm>
using namespace std;
int t,n;
int main()
{
    //freopen("in.txt","r",stdin);
    scanf("%d",&t);
    for(int i=1;i<=t;++i)
    {
        scanf("%d",&n);
        int odd=1,even=2,x,flag=1;
        for(int j=1;j<=n;++j)
        {
            scanf("%d",&x);
            if(x%2==0) 
            {
                if(x>=even) even=x;
                else 
                {
                    flag=0;
                    for(int k=0;k<n-j;k++) scanf("%d",&x);
                    j=n+1;
                }
            }
            else
            {
                if(x>=odd) odd=x;
                else
                {
                    flag=0;
                    for (int k = 0; k < n - j; k++) scanf("%d", &x);
                    j=n+1;
                }
            }
        }
        if(flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}*/

// Problem D solution: BIT
/*
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define ll long long
#define MAXN 200010
using namespace std;
ll a[MAXN];
int c[MAXN];
vector<int>b[MAXN];
int n;
ll ans=0;
int lowbit(int x) { return(x&(-x)); }
void update(int x,ll y)
{
    while(x<=n)
    {
        a[x]+=y;
        x+=lowbit(x);
    }
}
long long searchsum(int x)
{
    ll sum=1;
    while(x)
    {
        sum+=a[x];
        x-=lowbit(x);
    }
    return sum;
}
int main()
{
    memset(a,0,sizeof(a));
    freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&c[i]);
        if(c[i]>n) c[i]=n;
        b[min(i-1,c[i])].push_back(i);
    }
    for(int i=1;i<=n;i++)
    {
        update(c[i],1);
        for(vector<int>::iterator it=b[i].begin();it!=b[i].end();it++)
            ans+=searchsum(n)-searchsum(*it-1);
    }
    printf("%lld",ans);
    return 0;
}
void check()
{
    for (int i = 1; i <= n; i++)
        printf("%d ", c[i]);
    printf("\n");
    for (int i = 1; i <= n; i++)
        printf("%lld ", a[i]);
    printf("\n");
}*/

// Problem D solution 2: President Tree

// Problem E solution 1:BIT
/*
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long 
const int MAXN=2e5+5;
int n,q;
ll a[MAXN],b[MAXN];
struct node
{
    int id;
    int data;
}cnt[MAXN];
int lowbit(int x){return (x&-x);}
void update(int x,ll y)
{
    while(x<=n)
    {
        a[x]+=y;
        x+=lowbit(x);
    }
}
long long searchsum(int x)
{
    ll sum=1;
    while(x)
    {
        sum+=a[x];
        x-=lowbit(x);
    }
    return sum;
}*/


/*
int main()
{
    scanf("%d%d",&n,&q);
    a[0]=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        b[i]=a[i]-a[i-1];
        update(i,b[i]);
    }
    for(int i=1;i<=q;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        update(l,1);
        update(r+1,-1);
    }
    sort(b+1,b+n+1);
    int nn=n;
    long long ans;
    
    return 0;
}*/

// solution 2: Difference series 差分数列
/*
int s[MAXN];
int main()
{
    //freopen("in.txt","r",stdin);
    memset(s,0,sizeof(s));
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        b[i]=0;
    }
    for(int i=1;i<=q;++i)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        b[l]++;
        b[r+1]--;
    }
    s[0]=0;
    for(int i=1;i<=n;i++)
        s[i]=s[i-1]+b[i];
    sort(a+1,a+n+1);
    sort(s+1,s+n+1);
    ll ans=0;
    for(int i=1;i<=n;i++) ans+=(ll)a[i]*s[i];
    printf("%lld",ans);
    return 0;
}*/

// solution 2.5: 暴力解法 TLE
/*
bool cmp1(int a,int b)
{
    return a>b;
}
bool cmp2(struct node a,struct node b)
{
    return(a.data>b.data);
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;++i)
    {
       scanf("%d",&a[i]);
       cnt[i].id=i;
       cnt[i].data=0;
    }
    sort(a+1,a+n+1,cmp1);
    for(int i=1;i<=q;++i)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        for(int j=l;j<=r;++j)
        {
            cnt[j].data++;
        }
    }
    sort(cnt+1,cnt+n+1,cmp2);
    long long ans=0;
    for(int i=1;i<=q;i++)
    {
        ans=ans+(long long)a[i]*(cnt[i].data);
    }
    printf("%lld",ans);
    return 0;
}*/

// Problem F Greedy
/*
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct act
{
    int s,t;
}ac[10002];
bool cmp(struct act a,struct act b)
{
    if(a.s!=b.s) return a.s<b.s;
    else return a.t<b.t;
}
int n;
int main()
{
    //freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d%d",&ac[i].s,&ac[i].t);
    sort(ac+1,ac+n+1,cmp);
    int last[10010];
    bool sel[10010];
    int cla=1;
    memset(sel,0,sizeof(sel));
    last[1]=0;
    for(int i=1;i<=n;i++) 
    {
        int j;
        for(j=1;j<=cla;j++)
        {
            if(!sel[i]&&ac[i].s>=last[j])
            {
                sel[i]=1;
                last[j]=ac[i].t;
                break;
            }
        }
        if (j > cla)
        {
            sel[i] = 1;
            last[++cla] = ac[i].t;
        }
    }
    printf("%d",cla);
    return 0;
}*/


// Problem G  TLE x  BIT √ 
/*
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e5+10;
int n,q;
struct node
{
    int l,r,k;
}a[MAXN];
bool cmp(struct node x,struct node y)
{
    if(x.l!=y.l) return x.l<y.l;
    else return x.k>y.k;
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].l,&a[i].r);
        a[i].k=a[i].r-a[i].l;
    }
    sort(a+1,a+n+1,cmp);
    for(int m=1;m<=q;++m)
    {
        int ll,rr,kk,ans=0;
        scanf("%d%d%d",&ll,&rr,&kk);
        if(kk<=rr-ll)
        {
            for(int i=1;i<=n;i++)
            {
                if(a[i].l>=ll&&a[i].r<=rr&&a[i].k>=kk) ans+=1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}*/


// Problem H Greedy
/*
#include<cstdio>
using namespace std;
const int MAXN=1e5+10;
struct node
{
    int l,r,c;
}a[MAXN];
int main()
{
    int t;
    freopen("in.txt","r",stdin);
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int n;
        scanf("%d",&n);
        for(int j=1;j<=n;j++)
            scanf("%d%d%d",&a[j].l,&a[j].r,&a[j].c);
        int left=a[1].l,right=a[1].r,maxj=a[1].r-a[1].l+1;
        int x1=1,x2=1,x3=1;
        for(int j=1;j<=n;j++)
        {
            if(a[j].r-a[j].l+1>maxj)
            {
                maxj=a[j].r-a[j].l+1;
                x3=j;
            }
            else if(a[j].r-a[j].l+1==maxj&&a[j].c<a[x3].c) x3=j;
            if(a[j].l<left)
            {
                x1=j;
                left=a[j].l;
            }
            else if(a[j].l==left&&a[j].c<a[x1].c) x1=j;
            if (a[j].r >right)
            {
                x2 = j;
                right = a[j].r;
            }
            else if (a[j].r == right && a[j].c < a[x2].c) x2 = j;
            int sum;
            if (x1 == x2)
                sum = a[x1].c;
            else
                sum = a[x1].c + a[x2].c;
            if (a[x3].l == a[x1].l && a[x3].r == a[x2].r && a[x3].c < sum)  sum = a[x3].c;
            printf("%d\n", sum);
        }

    }
    return 0;
}*/

