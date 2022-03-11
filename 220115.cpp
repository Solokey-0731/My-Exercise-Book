//T01 Output Arrangement
/*
#include<cstdio>
#include<iostream>
using namespace std;
int A[10];
int B[10];
void Outpt();
void Dfs(int count,int n);
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=9;i++) A[i]=0;
    for(int i=1;i<=9;i++) B[i]=0;
    Dfs(1,n);
    //DFS+Huisu3
    return 0;
}
void Outpt(int n)
{
    for(int i=1;i<=n;i++) printf("%5d",A[i]);
    printf("\n");
    return;
}
void Dfs(int count,int n)
{
    int i;
    if(count>n)
    {
        Outpt(n);
        return;
    }
    for(i=1;i<=n;i++)
    {
        if(B[i]==0)
        {
            B[i]=1;
            A[count]=i;
            Dfs(count+1,n);
            B[i]=0;
        }
    }    
}*/

//T02 Output Combination
/*
#include<iostream>
using namespace std;
int A[22]={0},B[22]={0};
void Dfs(int count,int r,int n);
void Outpt(int r);
int main()
{
    int n,r;
    cin>>n>>r;
    Dfs(1,r,n);
    return 0;
}
void Outpt(int r)
{
    for(int i=1;i<=r;i++) printf("%3d",A[i]);
    cout<<'\n';
    return ;
}
void Dfs(int count, int r, int n)
{
    int i;
    if(count>r)
    {
        Outpt(r);
        return ;
    }
    for(i=1;i<=n;i++)
    {
        if(B[i]==0&&i>A[count-1])
        {
            A[count]=i;
            B[i] = 1;
            Dfs(count+1,r,n);
            B[i]=0;
        }
    }
}*/

//T03 Select Numbers
/*
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int pcnt=0;
int A[21]={0},B[21]={0},C[21]={0};
int PrimeCheck(int x);
void Dfs(int count, int fr,int k, int n);
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>A[i];
    sort(A+1,A+n+1);
    Dfs(1,1,k,n);
    cout<<pcnt;
    return 0;
}
int PrimeCheck(int x)
{
    int i;
    if(x==0) return 0;
    if(x==1) return 0;
    if(x==2) return 1;
    for(i=sqrt(x);i>=2;i--)
    {
        if(x%i==0) return 0;
    }
    return 1;
}

void Dfs(int count, int fr,int k, int n)
{
    if (count > k)
    {
        int add = 0, flag = 0;
        for (int i = 1; i <= k; i++)
            add = add + C[i];
        flag = PrimeCheck(add);
        if (flag)
            pcnt += 1;
        return;
    }
    int j;
    for (j = fr; j <= n; j++)
    {
        if (B[j] == 0 && A[j] >= C[count - 1])
        {
            C[count] = A[j];
            B[j] = 1;
            Dfs(count + 1, fr+1,k, n);
            B[j] = 0;
        }
    }
}*/

