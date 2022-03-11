// 引用类型
/*
#include<iostream>
using namespace std;
bool fibon_elem(int pos,int &elem)
{
    if(pos<=0&&pos>=1024) return false;
    else
    {
        elem=1;
        int n_1=1,n_2=1;
        for(int ix=3;ix<=pos;++ix)
        {
            elem=n_2+n_1;
            n_2=n_1;
            n_1=elem;
        }
        return true;
    }
}
int main()
{
    int pos;
    cin>>pos;
    int elem;
    if(fibon_elem(pos,elem))
        cout<<elem<<endl;
    else
        cout<<"false";
    return 0;
}*/

// istream & ostream
#include<iostream>
#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,m;
int w[3410],d[3410];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)
    {
        scanf("%d%d",&w[i],&d[i]);
    }
    
    return 0;
}