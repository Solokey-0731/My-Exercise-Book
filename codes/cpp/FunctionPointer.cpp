// Function Pointer Eg.01
/*
bool ascending(int a ,int b){return a>b;}
bool descending(int a,int b){return a<b;}
void SortAorD(int a[],int n,char *flag)
{
    bool(*ad)(int,int);// Function Pointer
    int temp;
    int pass,c;
    if(strcmp(flag,"ascending")==0) ad=ascending;//
    else ad=&descending;// With a & before function = without a &
    for(pass=0;pass<n;pass++)
    {
        for(c=0;c<n-1;c++)
        {
            if((*ad)(a[c],a[c+1]))// Swap according to the request
            {
                temp=a[c];
                a[c]=a[c+1];
                a[c+1]=temp;
            }
        }
    }
}
// flag(input value out-place)->ad(value: a>b or a<b)->swap according to ad's value

// Function Pointer Eg.02 Calculate the Integrate
#include<bits/stdc++.h>
using namespace std;
float Integrate(float (*fx)(float),float a,float b,int n)
{
    float h,s;
    int i;
    h=(b-a)/n;
    s=((*fx)(a)+(*fx)(b))/2.0;
    for(i=1;i<=n-1;i++) s+=(*fx)(a+i*h);
    return s*h;
}
float CubeX(float x) {return x*x*x;}
float SinX2(float x) {return (float)(sin(x)*sin(x));}
float Cos2X(float x) {return 0.5*(1-(float)cos(2*x));}
int main()
{
    printf("cube=%f\n",Integrate(CubeX,0.0,1.0,100));
    printf("Sin=%f\n",Integrate(SinX2,-1.0,1.0,200));
    printf("cos=%f\n",Integrate(Cos2X,0.0,2.0,300));
    return 0;
}*/
