#include<bits/stdc++.h>
using namespace std;
#define MAXINT 0x3f3f3f3f
#define MAXN 1000001
// Dijkstra 
/*
int n;
int dis[MAXN],head[MAXN],val[MAXN],nxt[MAXN],to[MAXN];
bool vis[MAXN];
void Dijkstra(int s)
{
    for(int i=1;i<=n;i++) 
    {
        dis[i]=MAXINT;// 没计算的节点一律算无穷
        vis[i]=0;// 表示节点是否删去
    }
    dis[s]=0;// 初始化
    for(int i=1;i<=n;i++)
    {
        int u = -1;// 初始化最近节点
        for(int j=1;j<=n;j++)
            if(!vis[j]&&(u==-1||dis[j]<dis[u])) u=j;
        // 找连通点，
        for(int j=head[u];~j;j=nxt[j])
        {
            int v=to[j],w=val[j];
            if(!vis[v]&&dis[u]+w<dis[v])
            dis[v]=dis[u]+w;
        }
        vis[u]=1;
    }
}*/

// Bellman-Ford
int n,m;
int dis[MAXN];
int U[MAXN],V[MAXN],W[MAXN];
void BellmanFord(int s)
{
    for(int i=1;i<=n;++i) dis[i]=MAXINT;
    dis[s]=0;
    // Normal
    for(int i=1;i<n;++i)
    {
        for(int j=1;j<=m;++j)// 枚举每条边,并松弛
        {
            int u=U[j],v=V[j],w=W[j];
            if(dis[u]+w<dis[v])
            {
                dis[v]=dis[u]+w;
            }
        }
    }
    // 存在性问题
    while(true)
    {
        bool flg=0;
        for(int i=1;i<=m;++i)
        {
            int u=U[i],v=V[i],w=W[i];
            if(dis[u]+w<dis[v])
            {
                dis[v]=dis[u]+w;
                flg=1;
            }
        }
        if(!flg) break;
    }
}
