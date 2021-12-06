#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


//T1 删除字符
/*
char* str_delete(char* s, int v, int w)
{
    int i,l;
    l=strlen(s);
    for(i=0;i<l-w;i++)
    {
        if(i>=v-1)//替换
        *(s+i)=*(s+i+w);
    }
    return s;
}


//T1 字符串部分删除
/*char* str_delete(char* s, int v, int w)
{
    int i, i1,i2, l, space1 = 0, space2 = 0, count = 0;
    l = strlen(s);
    for (i = 0;count < v;i++)//统计第v个字符之前的空格
    {
        if (*(s + i) != ' ') count++;
        else space1++;
    }
    //结束时，i-1对应第v个字符,即要清除的里面的第一个
    i1 = i-1;
    count = 0;//计数器清零
    //统计w个字符中的空格
    for (i = i1;count < w;i++)
    {
        if (*(s + i) == ' ') space2++;
        else
        {
            count++;//结束时i对应清除的第w个字符
        }
    }
    count = 0;//计数器再次清零
    for (i = i1;count < w;i++)
    {
        if (i < i1 + space2)
        {
            *(s + i) = ' ';//填充要删除的w个字符中的空格
        }
        else
        {
                *(s + i) = *(s + i1+w+space2+count);
                count++;//结束时已经替换完最后一个字符
        }
    }
    i2 = i;//此时i对应被替换完的最后一个字符之后的字符
    //后面的字符向前窜
    for (i = i2;*(s + i + w) != '\0';i++)
    {
        *(s + i) = *(s + i + w);
    }
    return s;
}

int main()
{
    int i, l, v, w, space;
    char str[256], * s, * s0;
    scanf("%d%d", &v, &w);
    getchar();
    gets(str);
    l = strlen(str);
    s0 = str;
    s = str_delete(s0, v, w);
    for (i = 0;i < l - w;i++) printf("%c", *(s + i));//只打印l-w个字符
    return 0;
}
*/

//T2 排序二维数组
/*
void input(int *a,int n,int m)
{
    int i,j,p;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",a+i*50+j);
        }
    }
}
void sort(int *a,int n,int m)
{
    int i=0,j=0,r,p1,p2;
    int flag=1;
    while(flag)
    {
        flag=0;
        for(i=0,j=0;i*50+j<50*(n-1)+m-1;)
        {
            p1=i*50+j;
            p2=p1+1;
            if(j==m-1) p2=(i+1)*50;
            if(*(a+p1)>*(a+p2))
            {
                flag=1;
                r=*(a+p1);
                *(a+p1)=*(a+p2);
                *(a+p2)=r;
            }
            j++;
            if(j==m)
            {
                i++;
                j=0;
            }
        }
    }
}
void output(int *a,int n,int m)
{
    int i,j,p;
    for(i=0;i<n;i++)
    {
        if(i>0) printf("\n");
        for(j=0;j<m;j++)
        {
            p=i*50+j;
            printf(j?" %d":"%d",*(a+p));
        }
    }
}
int main()
{
    int m,n;
    scanf("%d %d",&n,&m);
    int a0[50][50],*a=&a0[0];
    input(a,n,m);
    a=a0[0];
    sort(a,n,m);
    output(a,n,m);
    return 0;
}
*/

//T3 合法标识符
/*
int check(char *a,int i)
{
    int l,p;
    char m;
    l=strlen(a);
    for(p=0;p<l;p++)
    {
        m=*(a+p);
        if(m==' '||m=='\n') return 0;
        if(p==0)//判断开头
        {
            if(m!='_'&&((m<65||m>90)&&(m<97||m>122)))//不是下划线和字母
               {
                   return 0;
               }
        }
        else
        {
           if(m!='_'&&((m<65||m>90)&&(m<97||m>122))&&(m<48||m>57))//不是下划线、字母、数字
           {
               return 0;
           }
        }
    }
    return 1;
}

int main()
{
    int n,i,x=0,y=0;
    char str[100][256],*p;
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++)
    {
        gets(str[i]);
    }
    for(i=0;i<n;i++)
    {
        if(check(str[i],i)) x++;
        else y++;
    }
    printf("Valid:%d\n",x);
    printf("Invalid:%d",y);
    return 0;
}
*/

//T4 分类统计字符
/*
void count(char* str, int* upper, int* lower, int* space, int* num, int* other)
{
    while (*str != '\0')
    {
        if (*str >= 65 && *str <= 90) *upper=*upper+1;//不能用uper++
        else if (*str >= 97 && *str <= 112) *lower=*lower+1;
        else if (*str == 32) *space=*space+1;
        else if (*str >= 48 && *str <= 57) *num=*num+1;
        else *other=*other+1;
        str++;
    }
}
int main()
{
    char str[256];
    int sc[5] = { 0,0,0,0,0 }, i;
    char* st = str;
    gets(str);
    count(st, &sc[0], &sc[1], &sc[2], &sc[3], &sc[4]);
    for (i = 0;i < 5;i++) printf(i ? " %d" : "%d", sc[i]);
    return 0;
}*/

//T5 字符串长度
/*
int strleng(char *str)
{
    int length=0;
    while(*str!='\0')
    {
        str++;
        length++;
    }
    return length;
}
int main()
{
    char b[256];
    char *bp=b;
    int length;
    gets(b);
    length=strleng(bp);
    printf("%d",length);
    return 0;
}*/
