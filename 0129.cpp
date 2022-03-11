// Problem A
/*
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
long long a[50001],ans[50001]={0};
long long sum=0;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        scanf("%lld",&a[i]);
        ans[i]=max(ans[i-1]+a[i],a[i]);
        sum=max(sum,ans[i]);
    }
    //if(sum<0) sum=0;
    printf("%lld",sum);
    return 0;
}
*/

// Problem B
/*
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int a[1002][1002];
int main()
{
    int r,i,j;
    scanf("%d",&r);
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=i;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=r-1;i>=1;i--)
    {
        for(j=1;j<=i;j++) a[i][j]+=max(a[i+1][j+1],a[i+1][j]);
    }
    printf("%d",a[1][1]);
    return 0;
}*/

// Problem C
/*
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,m;
int w[3410],d[3410];
int dp[2][12881];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d%d",&w[i],&d[i]);
    memset(dp,0,sizeof(dp));
    int now=0;
    for(int i=1;i<=n;i++)
    {
        now=1-now;
        for(int j=0;j<=m;j++)
        {
            dp[now][j]=dp[1-now][j];
            if(j>=w[i]) dp[now][j]=max(dp[now][j],dp[1-now][j-w[i]]+d[i]);
        }
    }
    printf("%d\n",dp[now][m]);
    return 0;
}*/

// Problem D
/*
#include <algorithm>
#include <cstdio>
using namespace std;
int n, m, a[101];
int dp[102][102];
int main()
{
    scanf("%d %d", &n, &m);
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            for (int k = 0; k <= min(j, a[i]); ++k)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % 1000007;
            }
        }
    }
    printf("%d", dp[n][m]);
    return 0;
}*/

// Problem E 完全背包
/*
#include<cstdio>

*/

// Problem F 区间dp
/*
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=202;
int dp[MAXN][MAXN],a[MAXN],ans;
int n;
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        a[i+n]=a[i];
    }
    for(int len=2;len<=n;len++)
    {
        for(int i=1;i+len-1<2*n;i++)
        {
            int j=i+len-1;
            for(int k=i;k<j;k++)
            {
                dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]+a[i]*a[k+1]*a[j+1]);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        ans=max(dp[i][i+n-1],ans);
    }
    printf("%d",ans);
    return 0;
}*/

// Problem G 树形dp
/*
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f3f
const int MAXN=1005;
int n,cnt=0;
int fa[MAXN][5]={0};
int head[MAXN]={0};
struct edge
{
    int to;
    int nxt;
}e[MAXN];
void addedge(int u,int v)
{
    cnt++;
    e[cnt].to=v;
    e[cnt].nxt=head[u];
    head[u]=cnt;
}
void dfs(int tot)
{
    fa[tot][0]=1;
    fa[tot][3]=0;
    fa[tot][4]=0;
    for(int i=head[tot];i;i=e[i].nxt)
    {
        int v=e[i].to;
        dfs(v);
        fa[tot][0]+=fa[v][4];
        fa[tot][3]+=fa[v][2];
        fa[tot][4]+=fa[v][3];
    }
    if(head[tot]==0)
    {
        fa[tot][1]=fa[tot][2]=1;
    }
    else
    {
        fa[tot][1]=fa[tot][2]=INF;
        for(int i=head[tot];i;i=e[i].nxt)
        {
            int s=e[i].to;
            int f1=fa[s][0];
            int f2=fa[s][1];
            for(int j=head[tot];j;j=e[j].nxt)
            {
                if(i==j) continue;
                int t=e[j].to;
                f1+=fa[t][3];
                f2+=fa[t][2];
            }
            fa[tot][1]=min(fa[tot][1],f1);
            fa[tot][2]=min(fa[tot][2],f2);
        }
    }
    for(int i=1;i<=4;i++)
    {
        fa[tot][i]=min(fa[tot][i],fa[tot][i-1]);
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        int f;
        scanf("%d",&f);
        addedge(f,i);
    }
    dfs(1);
    printf("%d",fa[1][2]);
    return 0;
}*/

/*
#include <iostream>
#include <algorithm>
using namespace std;
#define maxN 1010
#define INF 2000000000

int N;
struct edge
{
    int to;
    int next;
} sons[maxN];         //前向星存图
int head[maxN] = {0}; //前向星存图
int F[maxN][5];

int nowEdge = 0;
void addSon(int u, int v)
{
    nowEdge++;
    sons[nowEdge].to = v;
    sons[nowEdge].next = head[u];
    head[u] = nowEdge;
}

void dfs(int now)
{
    F[now][0] = 1;
    F[now][3] = 0;
    F[now][4] = 0;
    for (int i = head[now]; i; i = sons[i].next)
    {
        int s = sons[i].to;
        dfs(s);
        F[now][0] += F[s][4];
        F[now][3] += F[s][2];
        F[now][4] += F[s][3];
    }
    if (head[now] == 0)
    {
        F[now][1] = F[now][2] = 1;
        //特殊情况：如果now没有儿子，特殊处理
    }
    else
    {
        F[now][1] = F[now][2] = INF;
        for (int i = head[now]; i; i = sons[i].next)
        {
            int s = sons[i].to;
            int F1 = F[s][0];
            int F2 = F[s][1];
            for (int j = head[now]; j; j = sons[j].next)
            {
                if (i == j)
                    continue;
                int t = sons[j].to;
                F1 += F[t][3];
                F2 += F[t][2];
            }
            F[now][1] = min(F[now][1], F1);
            F[now][2] = min(F[now][2], F2);
        }
    }
    for (int i = 1; i <= 4; i++)
    {
        F[now][i] = min(F[now][i], F[now][i - 1]);
        //把F[now][i]和前面取最小值的工作放在这里统一进行
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    cin >> N;
    for (int i = 2; i <= N; i++)
    {
        int f;
        cin >> f;
        addSon(f, i);
    }
    dfs(1);
    cout << F[1][2];
    return 0;
}*/

// Problem H 树形dp
/*
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e6+10;
int n;
struct soldier
{
    int id,bat,dis;
}s[MAXN];
bool cmp(struct soldier a,struct soldier b)
{
    if(a.bat!=b.bat) return a.bat>b.bat;
    else return a.id<b.id;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        s[i].id=i;
        scanf("%d%d",&s[i].bat,&s[i].dis);
    }
    sort(s+1,s+n+1,cmp);
    
    return 0;
}*/

// Luogu P1352
/*
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define MAXN 6005
int head[MAXN],v[MAXN];
vector<int>son[MAXN];
int f[MAXN][2];
void dp(int x)
{
    f[x][0]=0;
    f[x][1]=head[x];
    for(int i=0;i<son[x].size();i++)
    {
        int y=son[x][i];
        dp(y);
        f[x][0]+=max(f[y][0],f[y][1]);
        f[x][1]+=f[y][0];

    }
}
int main()
{
    freopen("in.txt","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&head[i]);
    for(int i=1;i<=n-1;i++) 
    {
        int x,y;
        scanf("%d%d",&x,&y);
        son[y].push_back(x);
        v[x]=1;
    }
    int root;
    for(int i=1;i<=n;i++)
    {
        if(!v[i]) 
        {
            root=i;
            break;
        }
    }
        dp(root);
        int manx=max(f[root][0],f[root][1]);
        printf("%d",manx);
        return 0;
}*/ 


// Problem J 状态压缩dp
/*
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int dp[10][10][10];
int n,k,ans=0;
void king(int n,int k)
{

}
int main()
{
    scanf("%d%d",&n,&k);
    king(n,k);
    printf("%d",ans);
    return 0;
}*/