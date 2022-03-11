//Quick Sort
/*
#include<bits/stdc++.h>
using namespace std;
int n,a[1000001];
void swap(int &a,int &b)
{
    int tmp=a;
    a=b;
    b=tmp;
}
void QuickSort(int a[],int left,int right)
{
    if(left>=right) return;
    int i=left,j=right;
    int pivot=a[i];
    while(i<j)
    {
        while(i<j&&a[j]>=pivot) j--;
        if(i<j) a[i]=a[j];
        while(i<j&&a[i]<=pivot) i++;
        if(i<j) a[j]=a[i];
        if(i>=j) a[i]=pivot;
    }
    QuickSort(a,left,j-1);
    QuickSort(a,j+1,right);
}
void qsort2(int left,int right) 
{
    int mid=a[(left+right)/2];
    int i=left,j=right;
    do
    {
        while(a[i]<mid) i++;
        //Search for the number on the left side which smaller than mid 
        while(a[j]>mid) j--;
        if(i<=j)
        {
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }while(i<=j);
    if(i<j) qsort2(left,j);
    if(i<right) qsort2(i,right);
    return;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    QuickSort(a,0,n-1);
    for(int i=0;i<n;i++) cout<<a[i]<<' ';
    return 0;
}*/

// P1068
/*
#include<bits/stdc++.h>
using namespace std;
typedef struct cmptr
{
    int k;
    int s;
}cmptr;
int main()
{
    int n,m;
    int mm;
    cin>>n>>m;
    cmptr cpt[5001];
    for(int i=1;i<=n;i++) cin>>cpt[i].k>>cpt[i].s;
    int flag=1;
    while(flag)
    {
        flag=0;
        for(int i=1;i<=n-1;i++)
        {
            if(cpt[i].s<cpt[i+1].s) 
            {
                cmptr r=cpt[i];
                cpt[i]=cpt[i+1];
                cpt[i+1]=r;
                flag=1;
            }
            if(cpt[i].s==cpt[i+1].s&&cpt[i].k>cpt[i+1].k)
            {
                cmptr t = cpt[i];
                cpt[i] = cpt[i + 1];
                cpt[i + 1] = t;
                flag = 1;
            }
        }
    }
    mm=floor(m*1.5);
    int j=mm+1,mmm=mm;
    while(cpt[j].s==cpt[mmm].s) 
    {
        mm+=1;
        j+=1;
    }
    cout<<cpt[mm].s<<' '<<mm<<endl;
    for(int i=1;i<=mm;i++) cout<<cpt[i].k<<' '<<cpt[i].s<<endl;
    return 0;
}*/

// Union-find Sets
#include<bits/stdc++.h>
using namespace std;
#define MAXN 10000001
int fa[MAXN];
inline void Intl(int n)
{
    for(int i=1;i<=n;i++) fa[i]=i;
}// Record the parent of node, and initially regard itself as its parents
int Fnd(int x)
{
    if(fa[x]==x) return x;
    else return Fnd(fa[x]);
} // Recursively access the parent node
inline void UnionSt(int i,int j)
{
    fa[Fnd(i)]=Fnd(j);
}
//Union-Sets
int FndCompressed(int x)
{
    if(x==fa[x]) return x;
    else
    {
        fa[x]=FndCompressed(fa[x]);//set its parent as the new root node
        return fa[x];
    }
    //or directly: return x==fa[x]?x:(fa[x]=FndCompressed(fa[x]));
}