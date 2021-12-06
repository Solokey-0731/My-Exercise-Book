//CX07 Struct and Files

#include<stdlib.h>
#include<stdio.h>

//01 Teachers' Information
/*
struct TeachersInformation
{
    char name[21];
    int gender;
    int age;
};
typedef struct TeachersInformation Tpinfo;

int main()
{
    Tpinfo a[10];
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",a[i].name);
        scanf("%d",&a[i].gender);
        scanf("%d",&a[i].age);
    }
    i=n/2;
    printf("%s ",a[i].name);
    printf(a[i].gender?"Male ":"Female ");
    printf("%d ",a[i].age);
    return 0;
}*/

//02 Plural
/*
int main()
{
    float a,b,c,d,AA,BB;
    scanf("%f %f %f %f",&a,&b,&c,&d);
    //Addition
    AA=a+c;
    BB=b+d;
    if(BB>0) printf("%.2f+%.2fi    ",AA,BB);
    if(BB==0) printf("%.2f    ",AA);
    if(BB<0) printf("%.2f-%.2fi    ",AA,-1*BB);
    //Subtraction
    AA=a-c;
    BB=b-d;
    if(BB>0) printf("%.2f+%.2fi    ",AA,BB);
    if(BB==0) printf("%.2f    ",AA);
    if(BB<0) printf("%.2f-%.2fi    ",AA,-1*BB);
    //Multiplication
    AA=a*c-b*d;
    BB=a*d+b*c;
    if(BB>0) printf("%.2f+%.2fi",AA,BB);
    if(BB==0) printf("%.2f",AA);
    if(BB<0) printf("%.2f-%.2fi",AA,-1*BB);
    return 0;
}*/

