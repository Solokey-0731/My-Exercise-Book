// Coin
/*
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAX_INT 0x3f3f3f3f
int a[10];
int coin[100001];
int main()
{
    int n,x,m;
    scanf("%d%d",&n,&m);
    memset(coin,MAX_INT,sizeof(coin));
    for(int i=0;i<n;++i)
    {
        scanf("%d",&x);
        a[i]=x;
    }
    for(int j=0;j<n;++j) 
    {
        coin[a[j]]=1;
    }
    for(int i=1;i<=m;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(i>=a[j]&&coin[i-a[j]]!=MAX_INT&&coin[i-a[j]]+1<coin[i])
            {
                coin[i]=coin[i-a[j]]+1;
            }
        }
    }
    if(coin[m]==MAX_INT) printf("-1");
    else printf("%d",coin[m]);
    return 0;
}*/

// Right or Down
/*
#include<iostream>
#include<cstdio>
#include<cstring>
#define MAXINT 0x3f3f3f3f
int main()
{
    int mp[20][20];
    int m,n;
    scanf("%d%d",&n,&m);
    mp[0][0]=1;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(i==0||j==0) mp[i][j]=1;
            else mp[i][j]=mp[i-1][j]+mp[i][j-1];
        }
    }
    printf("%d",mp[n-1][m-1]);
    return 0;
}*/

// P1002 Horse and Soldier
/*
#include<bits/stdc++.h>
using namespace std;
long long mp[22][22];
bool hrs[22][22];
int hx[9]={0,-2,-1,1,2,-2,-1,1,2};
int hy[9]={0,-1,-2,-2,-1,1,2,2,1};
int main()
{
    int n,m;
    int x,y;
    int i,j;
    scanf("%d%d%d%d",&n,&m,&x,&y);
    n+=1;m+=1;x+=1;y+=1;
    mp[1][1]=1;
    for(i=0;i<9;++i)
    {
        if (x - hx[i] >= 1 && y - hy[i] >= 1&&x - hx[i] <= n && y - hy[i] <= m)
        {
            hrs[x - hx[i]][y - hy[i]]=1;
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(hrs[i][j]==0&&(i!=1||j!=1))
            {
                mp[i][j]=mp[i-1][j]+mp[i][j-1];
            }
        }
    }
    printf("%lld",mp[n][m]);
    return 0;
}*/

// P1216 Number Triangles
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

// P1048 Gather Hurbs
/*
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int tme[101],val[101];
int hb[1001][101];
int main()
{
    int t,m;
    int ans=0;
    scanf("%d %d",&t,&m);
    for(int i=1;i<=m;i++) scanf("%d %d",&tme[i],&val[i]);
    for(int i=1;i<=m;i++)
    {
        for(int j=t;j>=0;j--)
        {
            if(j>=tme[i])
            {
                hb[i][j]=max(hb[i-1][j-tme[i]]+val[i],hb[i-1][j]);
            }
            else hb[i][j]=hb[i-1][j];
        }
    }
    printf("%d",hb[m][t]);
    return 0;
}*/

// P2196 Dig LandMine
/*
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
bool way[21][21];
int mp[21];
int dp[21];
int pre[21];
void otpt(int x)
{
    if(pre[x]==0) printf("%d",x);
    else
    {
        otpt(pre[x]);
        printf(" %d",x);
    }
}
int main()
{
    int n,cnt=0,last;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&mp[i]);
    for(int i=1;i<=n-1;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            scanf("%d",&way[i][j]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(way[j][i]) 
            {
                dp[i]=max(dp[i],dp[j]);
                if(dp[i]==dp[j]) pre[i]=j;
            }
        }
        dp[i] += mp[i];
        cnt = max(cnt, dp[i]);
        if (cnt == dp[i]) last = i;
    }
    otpt(last);
    printf("\n%d",cnt);
    return 0;
}*/

// P1434 Ski
/*
#include<cmath>
#include<iostream>
#include<cstdio>
using namespace std;
int sk[101][101],r,c,ans=0;
int dp[101][101]={0};
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
int Dfs(int x,int y);
int main()
{
    scanf("%d %d",&r,&c);
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
            scanf("%d",&sk[i][j]);
    }
    // turn over *^*
    int t;
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            t=Dfs(i,j);
            dp[i][j]=t;
            ans=max(dp[i][j],ans);
        }
    }
    printf("%d",ans);
    return 0;
}
int Dfs(int x,int y)
{
    if(dp[x][y]) return dp[x][y];
    int t=1;
    for(int i=0;i<4;i++)
    {
        int x1=x+dx[i];
        int y1=y+dy[i];
        if(x1>=1&&x1<=r&&y1>=1&&y1<=c&&sk[x][y]<sk[x1][y1])
        {
            t=max(Dfs(x1,y1)+1,t);
        }
    }
    dp[x][y]=t;
    return t;
}*/

// P1115 The largest subsequence sum
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
}*/

// P1077 Place the Flower