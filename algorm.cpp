
// HighPrecision
/*
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1e4+5;
int num1[MAXN],num2[MAXN],c[MAXN];
char str1[MAXN],str2[MAXN];
void str2int(char s[],int a[])
{
    a[0]=strlen(s);
    for(int i=a[0];i>0;i--)
        a[a[0]+1-i]=s[i-1]-'0';
}
void otput(int c[])
{
    int i=c[0]+1;
    while(c[i]==0&&i>1) i--;
    while(i>0) 
    {
        printf("%d",c[i]);
        i--;
    }
}
void highadd(int a[],int b[])
{
    c[0]=max(a[0],b[0])+1;
    int step;
    for(int i=1;i<=c[0];i++)
    {
        c[i]=c[i]+a[i]+b[i];
        step=c[i]/10;
        c[i+1]+=step;
        c[i]%=10;
    }
}

void highminus(int a[],int b[])
{
    c[0]=a[0];
    for(int i=1;i<=a[0];i++)
    {
        c[i]=a[i]-b[i];
        if(c[i]<0) 
        {
            a[i+1]--;
            c[i]+=10;
        }
    }
}
void highmult(int a[],int b[])
{
    c[0]=a[0]+b[0];
    int step;
    for(int i=1;i<=a[0];i++)
    {
        step=0;
        for(int j=1;j<=b[0];j++)
        {
            c[i+j-1]=a[i]*b[j]+step+c[i+j-1];
            step=c[i+j-1]/10;
            c[i+j-1]%=10;
        }
        c[i+b[0]]=step;
    }

}
void highdiv(int a[],int b)
{
    int step=0;
    c[0]=a[0];
    for(int i=1;i<=a[0];i++)
    {
        c[i]=(step*10+a[i])/b;
        step=(step*10+a[i])%b;
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    memset(num1,0,sizeof(num1));// 初始化
    memset(num2,0,sizeof(num2));
    memset(c,0,sizeof(c));
    scanf("%s",str1);
    scanf("%s",str2);
    //str2int(str1,num1);
    //str2int(str2,num2);
    for(int i=0;i<strlen(str1);i++)
    {
        num1[i+1]=str1[i]-48;
    }
    // highadd(num1,num2);
    // himinus
    
    int flag=1;
    if(strcmp(str1,str2)>0) 
    {
        highminus(num2,num1);
        flag=0;
    }
    else highminus(num1,num2);
    if(flag==0) printf("-");
    
    //highmult(num1,num2);
    highdiv(num1,5);
    otput(c);
    return 0;
}*/

// Sort
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
// QuickSort 运用了二分法,先找基准再递归排序

int paritition(int a[],int low,int high)
{
    int pivot=a[low];
    while(low<high)
    {
        while(low<high&&a[high]>=pivot)
        {
            --high;
        }
        a[low]=a[high];
        while(low<high&&a[low]<=pivot)
        {
            ++low;
        }
        a[high]=a[low];
    }
    a[low]=pivot;
    return low;
}
void quicksort(int a[],int low,int high)
{
    if(low<high)
    {
        int pivot=paritition(a,low,high);
        quicksort(a,low,pivot-1);
        quicksort(a,pivot+1,high);
    }
}


//MergeSort 二分，递归，双指针
void merge(int a[],int l,int r,int mid)
{
    int lenl=mid-l+1,lenr=r-mid;
    int numl[lenl],numr[lenr];
    memcpy(numl,a+l,sizeof(int)*lenl);
    memcpy(numr,a+mid+1,sizeof(int)*lenr);
    int i=0,j=0,k=l;
    while(i<lenl&&j<lenr)
    {
        a[k++]=numl[i]<numr[j]?numl[i++]:numr[j++];
    }
    while(i<lenl)
    {
        a[k++]=numl[i++];
    }

}
void mergesort(int a[],int l,int r)
{
    if(l>=r) return ;
    int mid=(l+r)>>1;
    mergesort(a,l,mid);
    mergesort(a,mid+1,r);
    merge(a,l,r,mid);
}

/*
int main()
{
    int a[100];
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    //quicksort(a, 1, n);
    mergesort(a,1,n);
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    return 0;
}*/