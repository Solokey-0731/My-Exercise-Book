//T1 P
/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int i;
    int a[n+1];
    for(i=n;i>=0;i--)
    {
        cin>>a[i];
    }
    for(i=n;i>=0;i--)
    {
        if(a[i]!=0)
        {
            if(i==0) cout<<a[i];
            else
            {
            if(a[i]!=1&&a[i]!=-1) cout<<a[i];
            if(a[i]==-1) cout<<'-';
            if(i!=0) 
            {
                cout<<'x';
                if(i!=1) cout<<'^'<<i;
            }
            }
        }
        if(i>=1&&a[i-1]>0) cout<<'+';
    }
    return 0;
}*/

//T2 P1563
/*
#include<bits/stdc++.h>
using namespace std;
typedef struct people
{
    int drt;
    char pfs[11];
}ppl;
ppl a[100001];
int main()
{
    int n,m;
    cin>>n>>m;
    int i,j;
    int ai,si,flag;
    for(i=1;i<=n;i++)
    {
        cin>>a[i].drt;
        cin>>a[i].pfs;
    }
    i=1;
    for(j=1;j<=m;j++)
    {
        cin>>ai>>si;
        flag=1;
        if(flag==1&&((ai==0&&a[i].drt==0)||(ai==1&&a[i].drt==1)))
        {
            i=i-si;
            if(i<1) i=i+n;
            flag=0;
        }
        if(flag==1&&((ai==0&&a[i].drt==1)||(ai==1&&a[i].drt==0)))
        {
            i=i+si;
            if(i>n) i=i%n;
            flag=0;
        }
    }
    cout<<a[i].pfs;
    return 0;
}*/

//T3 P1045
/*
#include<bits/stdc++.h>
using namespace std;
int num[909526]={0};
int main()
{
    int p;
    cin>>p;
    return 0;
}*/

