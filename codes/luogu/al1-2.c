//Algorithm 1-2 sort
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int cmp(char *x,char *y)
{
    while(*(x+1)!='\0'&&*(y+1)!='\0')
    {
    int flag1;
    flag1=strcmp(x,y);
    if(flag1>0) return 1;
    else if(flag1==0) return cmp(x+1,y+1);
    else return 0;
    }
    return 0;
}
int main()
{
    char str[20][11],*pmax;
    int n,i,count,flag;
    scanf("%d",&n);
    count=n;
    for(i=0;i<n;i++) scanf("%s",str[i]);
    pmax=str[0];
    while(count>0)
    {
        for(i=0;i<n;i++)
        {
            flag = cmp(str[i], pmax);
            if(flag) pmax=str[i];
        }
        printf("%s", pmax);
        *(pmax) = '\0';
        count--;
    }
    return 0;
}