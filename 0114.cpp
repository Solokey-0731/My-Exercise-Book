#include<bits/stdc++.h>
// T01 Binary Search
/*
int MoveStone(int x,int N,int M,int *elem)
{
    int count=0,s=0;
    for(int i=1;i<=N+1;i++)
    {
        if(*(elem+i)-s<x)
        count++;
        else
        s=*(elem+i);
    }
    if(count>M) return 0;
    else return 1;
}
int main()
{
    int L,M,N;
    int first=0,last=L,mid,ans;
    cin>>L>>N>>M;
    vector<int>elem(N+2);
    for(int i=1;i<=N;++i)
    {
        cin>>elem[i];
    }
    elem[0]=0;
    elem[N+1]=L;
    while(last>=first)
    {
        mid=(first+last)/2;
        if(MoveStone(mid,N,M,&elem[0]))
        {
            ans=mid;
            first=mid+1;
        }
        else last=mid-1;
    }
    cout<<ans<<endl;
    return 0;
}*/

/*
#include <cstdio>
using namespace std;
int dis[2000000];
int L, N, M;
int Move(int x)
{
    int s = 0, count = 0;
    for (int i = 1; i <= N + 1; i++)
    {
        if (dis[i] - s < x)
            count++;
        else
            s = dis[i];
    }
    if (count > M)
        return 0;
    return 1;
}
int main()
{
    int ans;
    scanf("%d %d %d", &L, &N, &M);
    dis[0] = 0;
    for (int i = 1; i <= N; i++)
        scanf("%d", &dis[i]);
    dis[N + 1] = L;
    int first = 0, last = L, mid;
    while (first <= last)
    {
        mid = (first + last) / 2;
        if (Move(mid))
        {
            first = mid + 1;
            ans = mid;
        }
        else
            last= mid - 1;
    }
    printf("%d", ans);
    return 0;
}*/

// T02 DFS
/*
char farm[100][101];
int m, n;
int xt[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, yt[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
void dfs(int x,int y)
{
    //int xt[8]={-1,-1,-1,0,0,1,1,1},yt[8]={-1,0,1,-1,1,-1,0,1};
    int x1,y1;
    int i;
    for(i=0;i<8;i++)
    {
        x1=x+xt[i];
        y1=y+yt[i];
        if (farm[x1][y1] == 'W' && x1 < m && y1 < n && x1 >= 0 && y1 >= 0)
        {
            farm[x1][y1] = '.';
            dfs(x1, y1);
        }
    }
}
int main()
{
    cin>>m>>n;
    int i,j,ans=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++) cin>>farm[i][j];
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(farm[i][j]=='W')
            {
                farm[i][j]='.';
                ans = ans + 1;
                dfs(i,j);
            }
        }
    }
    cout<<ans;
    return 0;
}*/

// T03
/*
char A[1001][1001], B[1001][1001];
int main()
{
    int n,m,count;
    int i,j;
    cin>>n>>m;
    for(i=0;i<n;i++)
    for(j=0;j<m;j++)
        cin >> A[i][j];
    for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
        cin >> B[i][j];
    int sum=0;
    for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
        if(A[i][j]!=B[i][j]) sum+=1;
    if(sum>(n*m/2))
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                printf((A[i][j]=='X')?".":"X");
            }
            printf("\n");
        }
    }
    else
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                printf("%c",A[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}*/

// T04 Ternary Search
/*
int a[10000],b[10000],c[10000];
double Calc(double x,int n)
{
    double si;
    double maxsi=(double)a[0]*x*x+(double)b[0]*x+(double)c[0];
    for(int i=1;i<n;i++)
    {
        si=(double)a[i] * x * x + (double)b[i] * x + (double)c[i];
        if(si>maxsi) maxsi=si;
    }
    return maxsi;
}
int main()
{
    int t,n;
    int i,j;
    double maxsi;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin >> n;
        for(j=0;j<n;j++)
        {
            cin>>a[j]>>b[j]>>c[j];
        }
        double left=0;
        double right=1000;
        double lftmid,rgtmid;
        double maxlft,maxrgt;
        while(right-left>(1e-9)||left-right>(1e-9))
        {
            lftmid=left+(right-left)/3;
            rgtmid=right-(right-left)/3;
            maxlft=Calc(lftmid,n);
            maxrgt=Calc(rgtmid,n);
            if(maxlft<=maxrgt) right=rgtmid;
            else left=lftmid;
        }
        maxsi=Calc(lftmid,n);
        printf("%.4lf\n", maxsi);
    }
    return 0;
}*/

// T05
/*
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
const int maxn = 1e5 + 100;
int ans,n,m;
map<int,int> G[maxn];
set<int> s;
void dfs(int u){
    vector<int> tmp;
    for(int v : s)
        if(G[u].find(v) == G[u].end())tmp.push_back(v);
    for(int v : tmp)s.erase(v);
    for(int v : tmp)dfs(v);
}
int main(){
    cin >> n >> m;
    for(int u,v,i = 1;i <= m;i++)
        cin >> u >> v,G[u][v] = G[v][u] = 1;
    for(int i = 1;i <= n;i++)s.insert(i);
    while(!s.empty()){
        int u = *s.begin();
                s.erase(u);
        dfs(u);
        ans++;
    }
    cout << ans - 1 << '\n';
    return 0;
}*/

// T06 Greedy
/*
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    int t, n, k, ltr[26] = {0};
    char st[200010];
    scanf("%d",&t);
    for(int i=1;i<=t;++i)
    {
        int ans=0,odd=0,evn=0;
        memset(ltr,0,sizeof(ltr));
        scanf("%d%d%s",&n,&k,st);
        for(int j=0;j<n;++j) ltr[st[j]-'a']+=1;
        for(int j=0;j<26;++j) 
        {
            evn+=ltr[j]/2;
            odd+=ltr[j]%2;
        }
        ans=evn/k*2;
        odd+=evn%k*2;
        if(odd>=k) ans++;
        printf("%d\n",ans);
    }
    return 0;
}*/

// T07 QuickPow
/*
#include <iostream>
using namespace std;
long long QuickPow(int a, int n, int M)
{
    long long ans = 1, base = a;
    while (n)
    {
        if (n & 1) // the last bit of n is 1
            ans = base * ans % M;
        base = base * base % M;
        n >>= 1; // n/2
    }
    return ans;
}
int main()
{
    int Z, M, H, a, b;
    long long md = 0;
    cin >> Z;
    while (Z--)
    {
        cin >> M >> H;
        for (int i = 0; i < H; i++)
        {
            cin >> a >> b;
            md = md + QuickPow(a, b, M);
        }
        md = md % M;
        cout << md << endl;
        md = 0;
    }
    return 0;
}*/

// T08
/*
#include<cstdio>
#include<stdlib.h>
#include<algorithm>
using namespace std;
const int nn=1e6+3;
typedef long long ll;
int n;
ll sum=0;
int size[nn];
bool vis[nn];
struct edge
{
    int fr,to,ver,nex;
}e[2*nn];
int num=0;
int last[nn];
void add(int x,int y,int z)
{
    e[++num].fr=x; e[num].to=y; e[num].ver=z;
    e[num].nex=last[x]; last[x]=num;
}

inline int read()
{
    int x=0,f=1; char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}

void dfs(int x)
{
    size[x]=1;
    for(int i=last[x];i;i=e[i].nex)
    {
        int y=e[i].to;
        if(vis[y])	continue;
        vis[y]=true;
        dfs(y);
        size[x]+=size[y];
    }
}

int main()
{
    n=read();
    for(int i=1;i<n;++i)
    {
        int a=read(), b=read(), c=read();
        add(a,b,c); add(b,a,c);
    }
    vis[1]=true;
    dfs(1);
    for(int i=1;i<=num;i+=2)
    {
        int x=e[i].fr, y=e[i].to, z=e[i].ver;
        if(size[x]<size[y])	swap(x,y);
        ll ans=abs(n-size[y]-size[y]);
        ans*=z;
        sum+=ans;
    }
    printf("%lld\n",sum);
    return 0;
}
*/

// T09 Greedy
/*
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int num[100010];
int main()
{
    int n,k,max;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&num[i]);
    sort(num+1,num+n+1);
    int m=1;
    max=num[n];
    for(int i=n-1;i>=1;i--)
    {
        if(abs(num[i]-max)>=k)
        {
            max=num[i];
            m++;
        }
    }
    printf("%d",m);
    return 0;
}
*/

