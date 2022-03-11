// 0226
/*
#include<iostream>
using namespace std;
int main()
{
    int n;
    char a[101][101];
    cin>>n;
    int flag=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n+1-i;j++)
        {
            if(flag==1) 
            {
                a[i][j]='+';
                a[j][i]='+';
                a[j][n-i+1]='+';
                a[n+1-i][j]='+';
                
            }
            if(flag==0) 
            {
                a[i][j] = '.';
                a[j][i] = '.';
                a[j][n - i + 1] = '.';
                a[n + 1 - i][j] = '.';
            }
        }
        flag=1-flag;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<a[i][j];
        }
        if(i!=n) cout<<endl;
    }
    return 0;
}*/

// 0227 
/*
#include<iostream>
using namespace std;
long long dp[51];
long long count(int n,int status)
{
    if(n<1) return 0;
    if(n==1) return 1;
    if(n==2) 
    {
        if(status<=2) return 2;
        if(status==3) return 1;
    }
    if(n>2)
    {
        if(status<=2) return (long long)(count(n-1,0)+count(n-2,status+1));
        if(status==3) return (long long)count(n-1,0);
    }
}
int main()
{
    int n;
    cin>>n;
    cout<<count(n,0);
    return 0;
}*/


// 0228