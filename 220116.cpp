//T1 P3156
/*
#include<bits/stdc++.h>
using namespace std;
int a[2000001];
int main()
{
    int n,m,w;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) 
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<m;i++)
    {
        scanf("%d",&w);
        printf("%d\n",a[w-1]);
    }
    return 0;
}*/

//T2 P1996
/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,count=0,i,i0=0,die=0;
    cin>>n>>m;
    int alive[n+1];
    for(i=1;i<=n;i++)
    {
        alive[i]=1;
    }
    count=0;
    i=1;
    for(;die<=n;i++)
    {
        if(i>n) i%=n;
        if(count==m-1&&alive[i]==1)
        {
            alive[i]=0;
            die+=1;
            count=0;
            if(die<n) cout<<i<<' ';
            if(die==n) 
            {
                cout<<i;
                break;
            }
        }
        if(count==m&&alive[i]==0)
        {
            continue;
        }
        if(alive[i]==1&&count<m-1) count+=1;
    }
    return 0;
}*/

//T3 P4387
/*
#include<bits/stdc++.h>
using namespace std;
stack<int>s;
int q,n,psh[100001],pp[100001];
int top;
int Check()
{
    for(int i=1;i<=n;i++)
    {
        if(!s.empty()&&s.top()==pp[i])
        {
            s.pop();
            continue;
        }
        while(top<=n&&psh[top]!=pp[i])
        {
            s.push(psh[top]),top++;
        }
        if(top>n) return 0;
        top++;
    }
    return 1;
}
int main()
{
    cin>>q;
    int m;
    for(m=0;m<q;m++)
    {
        top=1;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>psh[i];
        for(int i=1;i<=n;i++) cin>>pp[i];
        while(!s.empty()) s.pop();//Empty the Stack for the next time
        if(Check()) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}*/

//T4 P2670
/*
#include<bits/stdc++.h>
using namespace std;
char map1[100][101];
int xs[8]={-1,-1,-1,0,0,1,1,1};
int ys[8]={-1,0,1,-1,1,-1,0,1};
char Search(int x,int y,int n,int m)
{
    char count='0';
    int i,xi,yi;
    if(map1[x][y]=='*') return '*';
    for(i=0;i<8;i++)
    {
        xi=x+xs[i];
        yi=y+ys[i];
        if(xi>=0&&yi>=0&&xi<n&&yi<m)
        {
            if(map1[xi][yi]=='*') count=count+1;
        }
    }
    return count;
}
int main()
{
    int n,m,i,j;
    cin>>n>>m;
    char w;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>map1[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            w=Search(i,j,n,m);
            cout<<w;
        }
        if(i<n-1) cout<<endl;
    }
    return 0;
}*/

//T5 P1009
/*
#include<bits/stdc++.h>
using namespace std;
int a[1001]={0},b[1001]={0};
void HighAdd(int c[],int d[])
{
    int stp=0;
    for(int i=1;i<1000;i++)
    {
        d[i]=d[i]+stp+c[i]  ;
        stp=d[i]/10;
        d[i]%=10;
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
}
int main()
{
    int n;
    cin>>n;
    a[1]=1;
    for(int i=1;i<=n;i++)
    {
        HighMult(a,i);
        HighAdd(a,b);
    }
    int flag=0;
    for(int i=1000;i>=1;i--)
    {
        if(b[i]!=0) flag=1;
        if(flag) cout<<b[i];
    }
    return 0;
}*/

/*
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[2000];
int b[2000];
int c[2000];
int sum[2000];
void pplus(int *a, int *c)
{
    int jw = 0;
    for (int i = 1; i <= 1000; i++)
    {
        c[i] += a[i] + jw;
        jw = c[i] / 10;
        c[i] %= 10;
    }
}
void cheng(int *a, int c)
{
    int jw = 0;
    for (int i = 1; i <= 1000; i++)
    {
        a[i] = a[i] * c + jw;
        jw = a[i] / 10;
        a[i] %= 10;
    }
}
int main()
{
    int n;
    cin >> n;
    a[1] = 1;
    for (int i = 1; i <= n; i++)
    {
        cheng(a, i);
        pplus(a, c);
    }
    bool flag = 0;
    for (int i = 1000; i >= 1; i--)
    {
        if (c[i] != 0)
            flag = 1;
        if (flag)
            cout << c[i];
    }
}*/
