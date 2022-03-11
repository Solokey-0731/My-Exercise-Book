//T01 3n+1 Problem
/*
#include<iostream>
using namespace std;
int Calc(int n,int *m)
{
    if(n==0) return 1;
    if(n==1) return 1;
    else
    {
        (*m)+=1;
        if(n%2==0) 
        {
            return Calc(n/2,m);
        }
        else return Calc(3*n+1,m);
    }
}
void Clear(int m,int a[],int i,int j)
{
    if(m<i) return;
    if((m-1)%3==0) 
    {
        a[(m-1)/3]=0;
        Clear((m-1)/3,a,i,j);
    }
    if(m%2==0) 
    {
        a[m/2]=0;
        Clear(m/2,a,i,j);
    }
}
int main()
{
    int i,j,k,t=1,tmax=1;
    int a[10001];
    cin>>i>>j;
    for(k=0;k<i;k++) a[k]=0;
    for(k=j+1;k<10001;k++) a[k]=0;
    for(k=i;k<=j;k++) a[k]=k;
    for(k=j;k>=i;k--) Clear(k,a,i,j);
    for(k=j;k>=i;k--)
    {
        if(a[k]!=0)
        {
            Calc(a[k],&t);
            if(t>=tmax) tmax=t;
            t=1;
        }
    }
    cout<<i<<' '<<j<<' '<<tmax<<endl;
    return 0;
}*/

