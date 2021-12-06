#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>


//T1 括号是否匹配（栈）
/*#define size 100
char stack[size];//模拟栈的数组
char ch;//保存当前读入字符
int top;//栈顶指针
initial() { top = 0; }
int push(char x)//压栈
{
    if (top > size - 1) return 0;//栈满，无法压栈
    else
    {
        stack[top] = x;
        top = top + 1;
        return 1;
    }
}
char pop(void)//弹栈
{
    if (top == 0) return '\0';//栈空，返回空
    else
    {
        top--;
        return stack[top];
    }
}
void check(char x, char y)//检查栈顶元素与读入字符y进行比较
{
    if (x == '\0' || x == '@')//弹出字符为空或者@
    {
        printf("NO");//右括号多
        exit(0);
    }
    else
    {
        if (x != y)//弹出元素是左括号
        {
            printf("NO");//括号有交叉
            exit(0);
        }
    }
}

int main()
{
    //括号是否匹配（栈）
    char ch;
    char output;
    initial();
    push('@');
    ch = getchar();
    while (ch != '@')
    {
        switch (ch)
        {
        case'(':push(ch);break;
        case'[':push(ch);break;
        case'{':push(ch);break;//左括号压栈
        case')':output = pop(); check(output, '(');break;//检查“)”
        case']':output = pop(); check(output, '[');break;//检查“]”
        case'}':output = pop(); check(output, '{');break;//检查“}”
        }
        ch = getchar();
    }
    output = pop();
    if (output == '@')
        printf("YES");
    else
        printf("NO");
    return 0;
}*/

//T2 n倍数关系
/*
int input(int **p1)//输入一行元素
{
    int *p2;
    char ch;
    int i,j;
    for(p1;*p2!=-1;p1++)
    {
        ch=0;
        for(p2=*p1;ch!='\n';p2++)
        {
            scanf("%d",*p2);
            ch=getchar();
        }//不包括最后的0之外的元素个数
        if(*p2==-1) break;
    }
    return i;
}
void input2(int s[20][100],int i)//输入一行元素（第二版）
{
    char str[100];
    char *p;
    int j=0,sum;
    gets(str);
    for(p=str;*p!='0';p++)
    {
        sum=0;
        if(*p!=' ')
        {
            p++;
            for(;*p!=' ';p++)
            {
                sum=(sum*10+(int)(*p-48));//计算多位整数的值
            }
            s[i][j]=sum;
            j++;
        }
    }
    s[i][j]=0;//写入末尾0元素
}
void sortofdown(int *p,int i)//对该列元素进行排序，以便于比较
{
    int j,r,flag=1;
    while(flag)
    {
        flag=0;
        for(;*(p+1)!=0;p++)
        {
            if(*p<*(p+1))
            {
                flag=1;
                r=*p;
                *p=*(p+1);
                *(p+1)=r;
            }
        }
    }
}

void counta(int *p,int n)//比较倍数并输出
{
    int count=0,*q;//倍数的个数
    for(;*p!=0;p++)
    {
        for(q=p+1;*q!=0;q++)
        {
            if((*p)==(*q)*n) count++;
        }
    }
    printf("%d\n",count);
}

int main()
{
    int n,i,j,i0,sum,*p;//n是要比较的倍数
    int a[20][100];
    char b[100];
    scanf("%d\n",&n);
    getchar();
    if(n<5)
    {
        for(i=0;a[i][0]!=-1;i++)
        {
            gets(b);
            for(p=b;*p!='0';p++)
            {
                j=0;
                sum=0;
                if(*p!=' ')
                {
                    p++;
                    while(*p!=' ')
                    {
                        sum=(sum*10+(int)(*p-48));
                        p++;//计算多位整数的值
                    }
                    a[i][j]=sum;
                    j++;
                }
            }
            a[i][j]=0;//写入末尾0元素
        }
        for(i=0;i<i0;i++)//依次读入每一行,最后一行是-1,并且排序
        {
            p=&a[i][0];
            sortofdown(p,i);
        }
        for(i=0;i<i0;i++)
        {
            p=&a[i][0];
            counta(p,n);
        }

    }
    return 0;
}*/

//T3 三种排序算法的时间复杂度

//冒泡排序
/*
int main()
{
    int i,r,j,k,n=10,a[10],b[10],c[10],d[10];
    int cmpcount1=0,swapcount1=0,flag=1;
    for(i=0;i<10;i++) //读取元素
    {
        scanf("%d",&a[i]);
        b[i]=a[i];
        c[i]=b[i];
        d[i]=c[i];
    }
    //sortofselection(a[10],n)
    for(i=0;i<n-1;i++)
    {
        j=i;//找最小的元素a[j]
        for(k=i+1;k<n;k++)
        {
            cmpcount1++;
            if(a[k]<a[j])
            {
                j=k;
            }

        }
        r=a[i];
        a[i]=a[j];
        a[j]=r;
        swapcount1++;
    }
    printf("%d %d ",cmpcount1,swapcount1);

    //sortofup(b[10],n);
    int cmpcount2=0,swapcount2=0;//检测至少进行一次的先决条件
    while(flag)
    {
        flag=0;//先假设本次没交换
        for(i=0;i<n-1;i++)
        {
            cmpcount2++;
            if(b[i]>b[i+1])
            {
                r=b[i];
                b[i]=b[i+1];
                b[i+1]=r;
                swapcount2++;
                flag=1;//交换并记录
            }
        }
    }
    printf("%d %d ",cmpcount2,swapcount2);

    //sortofinsert(c[10],n);
    int cmpcount3=0,swapcount3=0;
    for(i=1;i<n;i++)//排序第i个元素
    {
        flag=0;
        j=i-1;//找位置
        while((c[j]>c[i])&&(j>=0))
        {
            j=j-1;
            flag=1;
            cmpcount3++;
        }
        r=c[i];//记录a[i]
        for(k=i-1;k>=j+1;k--)
        {
            c[k+1]=c[k];//其余元素向后窜
            if(flag) swapcount3++;
        }
        c[j+1]=r;
        if(flag) swapcount3++;
    }
    printf("%d %d",cmpcount3,swapcount3);
    return 0;
}
*/

//T4 删除重复的元素
/*
int main()
{
    int i,j,k,m,n,count=0,a[100],flag=1;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);//读入数组元素
    for(i=0;i<n;i++)
    {
        flag=1;
        m=a[i];
        n=n-count;//缩减数组元素个数
        count=0;//清除计数器
        while(flag)
        {
            flag=0;//先假设此次没有重复
            for(j=i+1;j<n;j++)
            {
                if(m==a[j])
                {
                    flag=1;
                    count++;//与该元素重复的元素的个数
                    for(k=j;k<n;k++)
                    {
                        a[k]=a[k+1];//其余元素往前窜
                    }
                }
            }
        }

    }
    for(i=0;i<n;i++) printf(i?" %d":"%d",a[i]);
    return 0;
}*/

//T5 转移0元素 把它们移到末尾
/*
int main()
{
    int i,number,n,n0=0,a[100];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&number);
        if(number!=0)//非零元素单独保存
        {
            a[n0]=number;
            n0++;
        }
    }
    for(i=0;i<n0;i++) printf(i?" %d":"%d",a[i]);
    for(i=n0;i<n;i++) printf(" 0");
    return 0;
}*/

//T6 循环右移
/*
int main()
{
    int i,j,n,a[100];
    scanf("%d %d",&n,&j);//n是数组的长度,j是右移的位数
    j=j%n;
    //读取数组元素
    for(i=j;i<n;i++) scanf("%d",&a[i]);//a[0]->a[j]
    for(i=0;i<j;i++) scanf("%d",&a[i]);
    for(i=0;i<n;i++) printf(i?" %d":"%d",a[i]);
    return 0;
}*/

//T7 检验矩阵重复元素
/*
int main()
{
    int n,i,j,a[100],flag=1;
    scanf("%d",&n);//n位 行列数目
    for(i=0;i<n*n;i++) scanf("%d",&a[i]);
    for(i=0;i<n*n;i++)
    {
        for(j=i+1;j<n*n;j++)//从该元素之后开始比较
        {
            if(a[i]==a[j])
            {
                flag=0;
                printf("YES");
                exit(0);//只要检测到相同元素，就打印yes后退出
            }
        }
    }
    if(flag) printf("NO");
    return 0;
}*/

//T8 矩阵转置
/*
int main()
{
    int n,i,j;
    int a[10][10];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[j][i]);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++) printf(j?" %d":"%d",a[i][j]);
        printf("\n");
    }
    return 0;
}
*/

//T9 检测矩阵主对角线是否对称
/*
int main()
{
    int n,i,j,flag;
    int a[10][10];
    scanf("%d",&n);
    for(i=0;i<n;i++)//读取
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    flag=1;
    for(i=1;i<n;i++)//检查
    {
        for(j=0;j<i;j++)
        {
            if(a[i][j]!=a[j][i])
            {
                flag=0;
                printf("NO");
                exit(0);
            }
        }
    }
    printf("YES");
    return 0;
}*/

//T10 字符串反序
/*
int main()
{
    char a[255],swap;
    int i,l;
    gets(a);
    l=strlen(a);
    for(i=0;i<l/2;i++)//交换
    {
        swap=a[i];
        a[i]=a[l-1-i];
        a[l-1-i]=swap;
    }
    printf("%s",a);
}*/

//T11 约瑟夫问题(参见猴子当大王）
/*
int main()
{
    int i,j,n,m,s,count=0,count0=0,flag,a[1000];
    scanf("%d %d %d",&n,&s,&m);//总猴子数量，最大的报数
    for(i=0;i<n-s+1;i++) a[i]=s+i;//给数组赋值
    for(i=n-s+1;i<n;i++) a[i]=i-n+s;
    do{
        for(i=0;i<n;i++)
        {
            if(a[i]!=0) count++;//跳过淘汰的猴子
            while(count%m==0&&count>count0)//报数到m的倍数，该猴子就淘汰
            {
                printf("%d ",a[i]);//打印淘汰的猴子
                a[i]=0;
                count0=count0+m;//决赛圈不打印别的猴子
                break;
            }
        }
        j=0;
        for(i=0;i<n;i++)//检测是否还有猴子
        {
            if(a[i]!=0)
            {
                flag=1;
                j++;//留存的猴子数量
            }
            if(j==1) flag=0;
        }
    }while(flag==1);
    return 0;
}*/

//T12 索引数组排序
/*
int main()
{
    int i,n,a[100],b[100],c[100],flag=1,swap,count=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        c[i]=a[i];
        b[i]=i;
    }
    //利用数组a对数组b进行排序
    while(flag)
    {
        flag=0;//先假设本次没交换
        for(i=0;i<n-1;i++)
        {
            if(c[i]>c[i+1])
            {
                swap=b[i];
                b[i]=b[i+1];
                b[i+1]=swap;
                swap=c[i];
                c[i]=c[i+1];
                c[i+1]=swap;
                flag=1;//交换并记录
            }
        }
    }
    for(i=0;i<n;i++) printf(i?" %d":"%d",a[i]);
    printf("\n");
    for(i=0;i<n;i++) printf(i?" %d":"%d",b[i]);
    return 0;
}*/

//T13 螺旋矩阵
/*
int main()
{
    int direct=0;//right 0,down 1,left 2,up 3
    int number=1,i,j,n,mup=0,mdown,nleft=0,nright,a[30][30];
    scanf("%d",&n);//矩阵的行列数
    mdown=n;
    nright=n;
    while(number<=n*n)//要铺上的数
    {
        direct=direct%4;
        if(direct==0)
        {
            i=mup;
            for(j=nleft;j<nright;j++)
            {
                a[i][j]=number;
                number++;
            }
            mup++;
            direct++;
        }
        else if (direct==1)
        {
            j=nright-1;
            for(i=mup;i<mdown;i++)
            {
                a[i][j]=number;
                number++;
            }
            nright--;
            direct++;
        }
        else if(direct==2)
        {
            i=mdown-1;
            for(j=nright-1;j>=nleft;j--)
            {
                a[i][j]=number;
                number++;
            }
            mdown--;
            direct++;
        }
        else if(direct==3)
        {
            j=nleft;
            for(i=mdown-1;i>=mup;i--)
            {
                a[i][j]=number;
                number++;
            }
            nleft++;
            direct++;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++) printf("%4d",a[i][j]);
        printf("\n");
    }
    return 0;
}*/


/*void sort(int *a,int l);
int main()
{
int num[100],n;
int i,k,g,f=0,a[100];
for(n=0;n<100;n++)
{
    num[n]=0;
}
scanf("%d",&n);
if(n!=0)
{
    int j;
    while(scanf("%d",&num[0]))
    {
        j=0;
        if(num[0]==0||n==0)
        {
            a[f]=0;
            f++;
        }
        else
        {
            if(num[0]==-1) break;
            for(j=1;j<100;j++)
            {
                scanf("%d",&num[j]);
                if(num[j]==0) break;
            }
            sort(num,j);
            int sum=0;
            for(i=0;i<j;i++)
            {
                for(k=0;k<i;k++)
                {
                    if(num[i]==num[k]*n) sum++;
                }
            }
            a[f]=sum;
            f++;
        }
    }
    for(g=0;g<f;g++)
    {
        printf("%d",a[g]);
        if(g<f-1) pprintf("\n");
    }
}
else printf("%d",0);
return 0;
}

void sort(int *a,int l)
{
    int i,j;
    int v;
    for(i=0;i<l-1;i++)
        for(j=i+1;j<l;j++)
    {
        if(a[i]>a[j])
        {
            v=a[i];
            a[i]=a[j];
            a[j]=v;
        }
    }
}*/

/*int a[20][100],b[100];
int input()
{
    char ch=0;
    int size,i,k=0;
    for(i=0;;i++)
    {
        ch=0;
        for(k=0;ch!='\n';k++)
        {
            scanf("%d",&a[i][k]);
            ch=getchar();
        }
        k=k-1;
        if(a[i][k]==-1) break;
        b[i]=k;
    }
    return i;
}
void judge(int n,int size)
{
    int i,j,k,sum;
    if(n!=1)
    {
        for(i=0;i<size;i++)
        {
            sum=0;
            for(j=0;j<b[i];j++)
            {
                for(k=0;k<b[i];k++)
                {
                    if(a[i][j]*n==a[i][k]) sum++;
                }
        }
        b[i]=sum;
        }
    }
    else
    {
        for(i=0;i<size;i++)
        {
            sum=0;
            for(j=0;j<b[i];j++)
            {
                for(k=j+1;k<b[i];k++)
                {
                    if(a[i][j]==a[i][k]) sum++;
                }
            }
            b[i]=sum;
        }
    }
}
int main()
{
    int n,size;
    scanf("%d",&n);
    size=input();
    judge(n,size);
    for(i=0;i<size;i++)
    {
        printf("%d",b[i]);
        if(i!=size-1) printf("\n");
    }
    return 0;
}
*/
