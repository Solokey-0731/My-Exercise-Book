// Vjudge Problem A Dijkstra
/*
//#include<bits/stdc++.h>
//
#include<cstdio>
#include<cstring>
using namespace std;
#define MAXN 2001
#define inf 0x3f3f3f3f
int dis[MAXN],vis[MAXN],n,m;
int maps[MAXN][MAXN];
void Dijkstra(int n)
{
    dis[1]=0;
    for(int i=0;i<n-1;i++)
    {
        int u = -1;
        for(int j=1;j<=n;j++) if(!vis[j]&&(u==-1||dis[j]<dis[u])) u=j;
        vis[u]=1;
        for(int j=1;j<=n;j++)
        if(dis[j]>dis[u]+maps[u][j])
        {
            dis[j]=dis[u]+maps[u][j];
        }
    }
}
int main()
{
    scanf("%d %d",&m,&n);
    memset(maps,inf,sizeof(maps));
    memset(dis,inf,sizeof(dis));
    memset(vis,0,sizeof(vis));
    for(int i=0;i<m;i++)
    {
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        if(maps[x][y]>z)
        {
            maps[x][y]=z;
            maps[y][x]=z;
        }
    }
    Dijkstra(n);
    printf("%d",dis[n]);
    return 0;
}*/
/*
#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
//#include<bits/stdc++.h>
using namespace std;
const int nmax = 2000, mmax = 2010;
int n, m;
int maps[nmax][nmax];
int dist[nmax];
bool vis[nmax];
void dijkstra()
{
    dist[1] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && (t == -1 || dist[j] < dist[t]))
                t = j;
        }
        vis[t] = true;
        for (int j = 1; j <= n; j++)
        {
            dist[j] = min(dist[j], dist[t] + maps[t][j]);
        }
    }
}
int main()
{
    scanf("%d%d", &m, &n);
    memset(maps, 0x3f, sizeof(maps));
    memset(dist, 0x3f, sizeof(dist));
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        if (maps[u][v] > w)
        {
            maps[u][v] = w;
            maps[v][u] = w;
        }
    }
    dijkstra();
    cout << dist[n];
}*/

// Vjudge Problem B  Bellman-Ford
/*
#include<cstdio>
#include<cstring>
using namespace std;
typedef struct station
{
    int a;
    int b;
    double hl,yj;
}station;
station stn[210];
int n, m, s,cnt;
double v;
bool flg;
double dis[210];
bool Change()
{
    flg=false;
    memset(dis,0,sizeof(dis));
    dis[s]=v;
    for(int i=1;i<n;i++)
    {
        flg=false;
        for(int j=1;j<cnt;j++)
        {
            if((dis[stn[j].a]-stn[j].yj)*stn[j].hl>dis[stn[j].b])
            {
                dis[stn[j].b]=(dis[stn[j].a]-stn[j].yj)*stn[j].hl;
                flg=true;
            }
        }   
        if(!flg) break;
    }
    for(int j=1;j<cnt;j++)
    {
        if(dis[stn[j].b]<(dis[stn[j].a]-stn[j].yj)*stn[j].hl) 
            return true;
    }
    return false;
}
int main()
{
    scanf("%d%d%d%lf", &n, &m, &s, &v);
    cnt=1;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&stn[cnt].a,&stn[cnt].b);
        stn[cnt+1].b=stn[cnt].a;
        stn[cnt+1].a=stn[cnt].b;
        scanf("%lf%lf%lf%lf", &stn[cnt].hl, &stn[cnt].yj, &stn[cnt+1].hl, &stn[cnt+1].yj);
        cnt+=2;
    }
    if(Change()) printf("YES");
    else printf("NO");
    return 0;
}*/

// Vjudge Problem C SPFA
/*
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define INF 0x3f3f3f3f
using namespace std;
int n,ml,md;
int dis[10010],head[10010],vis[10010],out[10010];
int cur,flag=0;
struct Edge
{
    int fr,to,nxt,val;
}e[200010];
void addedge(int from,int too,int value)
{
    e[cur].to=too;
    e[cur].val=value;
    e[cur].nxt=head[from];
    head[from]=cur++;
}
void spfa()
{
    queue<int>s;
    s.push(1);
    while(!s.empty())
    {
        int u=s.front();
        out[u]++;
        if(out[u]>n)
        {
            flag=1;
            break;
        }
        s.pop();
        vis[u]=0;
        for(int i=head[u];i!=-1;i=e[i].nxt)
        {
            int t=e[i].to;
            int v=e[i].val;
            if(dis[t]>dis[u]+v)
            {
                dis[t]=dis[u]+v;
                if(vis[t]==0)
                {
                    vis[t]=1;
                    s.push(t);
                }
            }
        }
    }
    if(flag==1) printf("-1");
    else if (dis[n]>=INF) printf("-2");
    else printf("%d",dis[n]);
}
int main()
{
    memset(dis,INF,sizeof(dis));
    memset(vis,0,sizeof(vis));
    memset(head,-1,sizeof(head));
    memset(out,0,sizeof(out));
    dis[1]=0;
    cur=0;
    scanf("%d%d%d",&n,&ml,&md);
    for(int i=1;i<=ml;i++)
    {
        int a,b,d;
        scanf("%d%d%d",&a,&b,&d);
        addedge(a,b,d);
    }
    for(int i=1;i<=md;i++)
    {
        int a,b,d;
        scanf("%d%d%d",&a,&b,&d);
        addedge(b,a,-d);
    }
    spfa();
    return 0;
}*/

// Vjudge Problem D Prim
/*
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int mp[101][101];
int n,q;
int qs[102];
bool vis[102];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            scanf("%d",&mp[i][j]);
            mp[j][i]=mp[i][j];
        }
    }
    scanf("%d",&q);
    for(int i=1;i<=q;++i)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        mp[x][y]=0;
        mp[y][x]=0;
    }// Input
    // Prim
    memset(vis,false,sizeof(vis));
    qs[1]=1;
    vis[1]=true;
    int cnt=1;
    int min=0x3f3f3f3f;
    int mina=0,minb=0;
    int dis=0;
    int a,b;
    while(cnt<n)
    {
        for(a=1;a<=n;a++)
        {
            for(b=1;b<=n;b++)
            {
                if(a!=b&&mp[a][b]<min&&vis[a]==true&&vis[b]==false)
                {
                    min=mp[a][b];
                    mina=a;
                    minb=b;
                    //printf("%d %d %d %d\n",min,mina,minb,cnt);//
                }
            }
        }
        //printf("%d %d %d %d\n",min,mina,minb,cnt);//
        cnt+=1;
        qs[cnt]=minb;
        vis[minb]=true;
        dis+=min;
        min=0x3f3f3f3f;
        mina=0,minb=0;
    }
    printf("%d",dis);
    return 0;
}*/

// Vjudge Problem E Dijkstra
/*
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;
int t,ans;
int dis[1010];
bool vis[1010];
int mp[1010][1010];
void dijkstra(int n)
{
    for(int i=1;i<=n;++i) dis[i]=mp[1][i];
    memset(vis,false,sizeof(vis));
    dis[1]=INF;
    for (int i = 1; i <= n; i++)
    {
        int u=-1;
        for(int j=1;j<=n;++j)
        {
            if(!vis[j]&&(u==-1||dis[u]<dis[j]))
            {
                u=j;
            }
        }
        vis[u]=true;
        for(int j=1;j<=n;++j)
        {
            dis[j]=max(dis[j],min(dis[u],mp[u][j]));
        }   
    }
}
int main()
{
    scanf("%d",&t);
    for(int i=1;i<=t;++i)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        memset(mp,0,sizeof(mp));
        for(int j=1;j<=m;++j)
        {
            int u, v, w; 
            scanf("%d%d%d", &u, &v, &w);
            mp[u][v] = w;
            mp[v][u] = w;
        }
        dijkstra(n);
        ans=dis[n];
        printf("Scenario #%d:\n%d\n",i,ans);
    }
    return 0;
}*/

// Vjudge Problem F LCA BEIZENG
/*
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXN 40010
#define maxLog 17
int dis[MAXN],fa[MAXN][20];
bool vis[2*MAXN];
struct edge
{
    int to,w,nxt;
}e[MAXN];
int head[MAXN];
int depth[MAXN];
int n,m,k;
int ecnt=0;
void initgraph()
{
    memset(node,0,sizeof(node));
    ecnt=0;
}
void init()
{
    initgraph();
    memset(depth,0,sizeof(depth));
    memset(dis,0,sizeof(dis));
    memset(fa,0xff,sizeof(fa));
}
void add(int from,int to,int w=-1)
{
    e[++ecnt].to=to;
    e[ecnt].w=w;
    e[ecnt].nxt=head[from];
    head[from]=ecnt;
}
void addedge(int u,int v,int w,int fa[])
{
    add(u,v,w);
    add(v,u,w);
}
void dfs(int root,int father)
{
    if(~father) 
    {
        fa[root][0]=father;
        depth[root]=depth[father]=1;
        dis[root]=dis[father]+w;
    }
    for(int i=1;(1<<i)<=depth[root];i++)
        fa[root][i]=fa[fa[root][i-1]][i-1];
    for(int i=head[root];i;i=e[i].nxt)
    {
        if(e[i].to==father) continue;
        dfs(e[i].to,e[i].w,root);
    }
}
int lca(int nodea,int nodeb)
{
    if(depth[nodea]>depth[nodeb]) 
    {
        int r=nodeb;
        nodeb=nodea;
        nodea=r;
    }
    for(int i=maxLog;i>=0;i--)
    {
        if(fa[nodeb][i]!=-1&&depth[fa[nodeb][i]]>=depth[nodea])
            nodeb=fa[nodeb][i];
        if(nodea==nodeb) return nodea;
    }
    for(int i=maxLog;i>=0;i--)
    {
        if(fa[nodea][i]!=-1&&fa[nodeb][i]!=-1&&fa[nodea][i]!=fa[nodeb][i])
        {
            nodea=fa[nodea][i];
            nodeb=fa[nodeb][i];
        }
    }
    return fa[nodea][0];
}
int main()
{
    // Input
    freopen("in.txt","r",stdin);
    scanf("%d%d",&n,&m);
    int cnt=1;
    for(int i=1;i<=m;++i)
    {
        int a1,b1,c1;
        char x1;
        scanf("%d%d%d %c",&a1,&b1,&c1,&x1);
        e[i].to=a1;
        e[i].nxt=b1;
        e[i].w=c1;
    }

    // Search
    scanf("%d",&k);
    for(int i=1;i<=k;i++)
    {
        int a2,b2,ans;
        scanf("%d%d",&a2,&b2);
        printf("%d\n",ans);
    }
}*/

// Vjudge Problem F LCA Tarjan
/*
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=4e4+10;
int n,m;
struct edge
{
    int end,nxt,w;
}e[2*MAXN];
struct edge qe[2*MAXN];
int fa[MAXN],head[MAXN],qhead[MAXN];
int dis[MAXN],ans[MAXN],rnk[MAXN];
bool vis[MAXN];
int cnt=1,qcnt=1;
void init()
{
    memset(fa,-1,sizeof(fa));
    memset(head,-1,sizeof(head));
    memset(qhead,-1,sizeof(qhead));
    memset(rnk,0,sizeof(rnk));
    memset(vis,0,sizeof(vis));
    cnt=0;
    qcnt=0;
}
void addedge(int start,int end,int w)
{
    e[cnt].end=end;
    e[cnt].nxt=head[start];
    e[cnt].w=w;
    head[start]=cnt++;
}
void qadd(int start, int end, int w)
{
    qe[qcnt].end = end;
    qe[qcnt].nxt = qhead[start];
    qe[qcnt].w = w;
    qhead[start]=qcnt++;
}
int find(int x)
{
    if(x!=fa[x]) fa[x]=find(fa[x]);
    return fa[x];
}
void tarjan(int start,int disnow)
{
    int j,end,w;
    dis[start]=disnow;
    vis[start]=1;
    for(int i=qhead[start];i!=-1;i=qe[i].nxt)
    {
        end=qe[i].end;
        w=qe[i].w;
        if(vis[end]) ans[w]=dis[start]+dis[end]-2*dis[find(end)];
    }
    for(int i=head[start];i!=-1;i=e[i].nxt)
    {
        end=e[i].end;
        w=e[i].w;
        if(!vis[end])
        {
            tarjan(end,disnow+w);
            fa[end]=start;
        }
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        char ch;
        scanf("%d%d%d %c",&a,&b,&c,&ch);
        addedge(a,b,c);
        addedge(b,a,c);
    }
    int k;
    scanf("%d",&k);
    for(int i=1;i<=k;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        qadd(a,b,i);
        qadd(b,a,i);
    }
    tarjan(1,0);
    for(int i=1;i<=k;i++) 
    {
        printf("%d\n",ans[i]);
    }
    return 0;
}*/

// Vjudge Problem F LCA BEIZENG
/*
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=4e4+5;
int n,m;
struct edge
{
    int to,nxt,w;
}e[2*MAXN];
int head[MAXN],dis[MAXN];
int cnt,depth[MAXN],fa[20][MAXN];
void addedge(int u,int v,int w)
{
    e[cnt].to=v;
    e[cnt].w=w;
    e[cnt].nxt=head[u];
    head[u]=cnt++;
}
void dfs(int u,int father)
{
    fa[0][u]=father;
    for(int i=head[u];~i;i=e[i].nxt)
    {
        int too=e[i].to;
        if(too!=father)
        {
            depth[too]=depth[u]+1;
            dis[too]=dis[u]+e[i].w;
            dfs(too,u);
        }
    }
}
void init(int n)
{
    depth[1]=1;
    dfs(1,-1);
    for(int i=1;i<20;i++)
        for(int j=1;j<=n;j++)
            fa[i][j]=fa[i-1][fa[i-1][j]];
}
int lca(int x,int y)
{
    if(depth[x]>depth[y]) 
    {
        int r=x;
        x=y;
        y=r;
    }
    for(int i=0;i<20;i++)
    {
        if(depth[y]-depth[x]>>(i&1))
        y=fa[i][y];
    }
    if(x==y) return x;
    for(int i=19;i>=0;i--)
    {
        if(fa[i][x]!=fa[i][y])
        {
            x=fa[i][x];
            y=fa[i][y];
        }
    }
    return fa[0][x];
}
int main()
{
    scanf("%d%d",&n,&m);
    cnt=0;
    memset(head,-1,sizeof(head));
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        char ch;
        scanf("%d%d%d %c",&a,&b,&c,&ch);
        addedge(a,b,c);
        addedge(b,a,c);
    }
    init(n);
    int k;
    scanf("%d",&k);
    for(int i=1;i<=k;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        int ans=dis[a]+dis[b]-2*dis[lca(a,b)];
        printf("%d\n",ans);
    }
    return 0;
}*/

// Problem H LCA
/*
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1e4+10;
int n;
int cnt=0;
int head[MAXN];
struct edge
{
    int to,nxt,w;
}c[MAXN];
void addedge(int u,int v)
{
    c[++cnt].to=v;
    c[cnt].nxt=head[u];
    head[u]=cnt;
}*/

// Vjudge Problem G LCA Tree
/*
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=1e5+10;
int n,m;
struct edge
{
    int to,nxt;
}e[2*MAXN];
void addedge(int u,int v)
{

}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        addedge(a,b);
    }
    return 0;
}*/

// Vjudge Problem J Kosaraju
/*
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
using namespace std;
const int MAXN=1e4+10;
int n,m;
vector<int>g[MAXN],gr[MAXN],s;
bool vis[MAXN];
int snum;
int scnum[MAXN];
void dfs1();
void dfs2();
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        g[b].push_back(a);
        gr[a].push_back(b);
    }
    return 0;
}
*/

// Vjudge Problem J tarjan
/*
#include<cstdio>
#include<cstring>
#include<stack>
#include<algorithm>
using namespace std;
const int MAXN=1e4+5;
const int MAXM=5e4+5;
stack<int>s;
int dfn[MAXN],low[MAXN],vis[MAXN],head[MAXN],scc[MAXN],numscc[MAXN],head2[MAXN];
int dfsnum=0,scccnt=0;
int n,m,cnt=0,cnt2=0;
struct edge
{
    int v,nxt;
}e[MAXM],b[MAXM];
void addedge(int u,int v)
{
    e[++cnt].v=v;
    e[cnt].nxt=head[u];
    head[u]=cnt;
}
void addedgeb(int u,int v)
{
    b[++cnt2].v=v;
    b[cnt2].nxt=head2[u];
    head2[u]=cnt2;
}
void tarjan(int u)
{
    s.push(u);
    vis[u]=1;
    dfn[u]=++dfsnum;
    low[u]=dfn[u];
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int x=e[i].v;
        if(!dfn[x])
        {
            tarjan(x);
            low[u]=min(low[u],low[x]);
        }
        else if(!scc[x])
        {
            low[u]=min(low[u],dfn[x]);
        }
    }
    if(low[u]==dfn[u])
    {
        scccnt+=1;
        int x=0;
        while(x!=u)
        {
            x=s.top();
            s.pop();
            scc[x]=scccnt;
            numscc[scccnt]++;
        }
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        addedge(u,v);
    }
    for(int i=1;i<=n;i++)
    {
        if(!dfn[i]) tarjan(i);
    }
    bool flag[scccnt+10][scccnt+10];
    for(int i=1;i<=n;i++)
    {
        for(int p=head[i];p;p=e[p].nxt)
        {
            if(!flag[scc[i]][scc[e[p].v]]&&scc[i]!=scc[e[p].v])
            {
                addedgeb(scc[i],scc[e[p].v]);
                flag[scc[i]][scc[e[p].v]]=1;
            }
        }
    }
    int p0 = 0, starscc = 0;
    for (int i=1;i<=scccnt;++i)
    {
        if(!head2[i])
        {
            p0++;
            starscc=i;
        }
    }
    if(p0==1)
        printf("%d",numscc[starscc]);
    else printf("0");
    return 0;
}*/

/*
#include <bits/stdc++.h>
using namespace std;
stack<int> sta;
int e = 0, f = 0, low[10004], nscc[10004], dfn[10004], head[10004], head2[10004], dfs_clock, sccno[10004], sccw[10004], scc_cnt, w[10004], dp[10004], ans, n, m;
bool vis[10004];
struct node
{
    int v, next;
} a[100004], b[100004];
void insert(int u, int v)
{
    a[++e].v = v;
    a[e].next = head[u];
    head[u] = e;
}
void insert2(int u, int v)
{
    b[++f].v = v;
    b[f].next = head2[u];
    head2[u] = f;
}
void tarjan(int u)
{
    low[u] = dfn[u] = ++dfs_clock;
    sta.push(u);
    for (int p = head[u]; p != 0; p = a[p].next)
    {
        int v = a[p].v;
        if (!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (!sccno[v])
        {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u])
    {
        scc_cnt++;
        int x = 0;
        for (;;)
        {
            x = sta.top();
            sta.pop();
            sccno[x] = scc_cnt;
            nscc[scc_cnt]++;
            if (x == u)
                break;
        }
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        insert(u, v);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!dfn[i])
            tarjan(i);
    }
    bool flag[scc_cnt + 10][scc_cnt + 10];
    for (int i = 1; i <= n; i++)
        for (int p = head[i]; p; p = a[p].next)
        {
            if (!flag[sccno[i]][sccno[a[p].v]] && sccno[i] != sccno[a[p].v])
            {
                insert2(sccno[i], sccno[a[p].v]);
                flag[sccno[i]][sccno[a[p].v]] = 1;
            }
        }
    int po = 0, starscc = 0;
    for (int i = 1; i <= scc_cnt; i++)
        if (!head2[i])
        {
            po++;
            starscc = i;
        }
    if (po == 1)
    {
        cout << nscc[starscc] << endl;
        return 0;
    }
    cout << 0 << endl;
}*/
