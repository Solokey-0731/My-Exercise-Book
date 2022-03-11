// Dynamic Programming

// P1255 Counting Stairs
// DP model+ Record array bits dynamically(*)
/*
#include<bits/stdc++.h>
using namespace std;
int n,ns=1;
int a[5010],b[5010],temp[5010];
void HighAddGetWay()
{
    for(int i=3;i<=n;++i)
    {
        for(int j=1;j<=ns;++j) temp[j]=a[j]+b[j];
        for(int j=1;j<=ns;++j)
        {
            if(temp[j]>9)
            {
                temp[j+1]+=temp[j]/10;
                temp[j]%=10;
                if(j+1>ns) ns+=1;
            }
        }
        for(int j=1;j<=ns;++j) a[j]=b[j];
        for(int j=1;j<=ns;++j) b[j]=temp[j];//Swap 
    }
}
int main()
{
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(temp,0,sizeof(temp));
    a[1] = 1;
    b[1] = 2;
    scanf("%d",&n);
    if(n<3) printf("%d",n);
    else 
    {
        HighAddGetWay();
        for(int i=ns;i>0;i--) printf("%d",temp[i]);
    }
    return 0;
}*/


