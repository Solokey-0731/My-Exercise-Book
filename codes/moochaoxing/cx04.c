#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>


//T1 �����Ƿ�ƥ�䣨ջ��
/*#define size 100
char stack[size];//ģ��ջ������
char ch;//���浱ǰ�����ַ�
int top;//ջ��ָ��
initial() { top = 0; }
int push(char x)//ѹջ
{
    if (top > size - 1) return 0;//ջ�����޷�ѹջ
    else
    {
        stack[top] = x;
        top = top + 1;
        return 1;
    }
}
char pop(void)//��ջ
{
    if (top == 0) return '\0';//ջ�գ����ؿ�
    else
    {
        top--;
        return stack[top];
    }
}
void check(char x, char y)//���ջ��Ԫ��������ַ�y���бȽ�
{
    if (x == '\0' || x == '@')//�����ַ�Ϊ�ջ���@
    {
        printf("NO");//�����Ŷ�
        exit(0);
    }
    else
    {
        if (x != y)//����Ԫ����������
        {
            printf("NO");//�����н���
            exit(0);
        }
    }
}

int main()
{
    //�����Ƿ�ƥ�䣨ջ��
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
        case'{':push(ch);break;//������ѹջ
        case')':output = pop(); check(output, '(');break;//��顰)��
        case']':output = pop(); check(output, '[');break;//��顰]��
        case'}':output = pop(); check(output, '{');break;//��顰}��
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

//T2 n������ϵ
/*
int input(int **p1)//����һ��Ԫ��
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
        }//����������0֮���Ԫ�ظ���
        if(*p2==-1) break;
    }
    return i;
}
void input2(int s[20][100],int i)//����һ��Ԫ�أ��ڶ��棩
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
                sum=(sum*10+(int)(*p-48));//�����λ������ֵ
            }
            s[i][j]=sum;
            j++;
        }
    }
    s[i][j]=0;//д��ĩβ0Ԫ��
}
void sortofdown(int *p,int i)//�Ը���Ԫ�ؽ��������Ա��ڱȽ�
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

void counta(int *p,int n)//�Ƚϱ��������
{
    int count=0,*q;//�����ĸ���
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
    int n,i,j,i0,sum,*p;//n��Ҫ�Ƚϵı���
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
                        p++;//�����λ������ֵ
                    }
                    a[i][j]=sum;
                    j++;
                }
            }
            a[i][j]=0;//д��ĩβ0Ԫ��
        }
        for(i=0;i<i0;i++)//���ζ���ÿһ��,���һ����-1,��������
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

//T3 ���������㷨��ʱ�临�Ӷ�

//ð������
/*
int main()
{
    int i,r,j,k,n=10,a[10],b[10],c[10],d[10];
    int cmpcount1=0,swapcount1=0,flag=1;
    for(i=0;i<10;i++) //��ȡԪ��
    {
        scanf("%d",&a[i]);
        b[i]=a[i];
        c[i]=b[i];
        d[i]=c[i];
    }
    //sortofselection(a[10],n)
    for(i=0;i<n-1;i++)
    {
        j=i;//����С��Ԫ��a[j]
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
    int cmpcount2=0,swapcount2=0;//������ٽ���һ�ε��Ⱦ�����
    while(flag)
    {
        flag=0;//�ȼ��豾��û����
        for(i=0;i<n-1;i++)
        {
            cmpcount2++;
            if(b[i]>b[i+1])
            {
                r=b[i];
                b[i]=b[i+1];
                b[i+1]=r;
                swapcount2++;
                flag=1;//��������¼
            }
        }
    }
    printf("%d %d ",cmpcount2,swapcount2);

    //sortofinsert(c[10],n);
    int cmpcount3=0,swapcount3=0;
    for(i=1;i<n;i++)//�����i��Ԫ��
    {
        flag=0;
        j=i-1;//��λ��
        while((c[j]>c[i])&&(j>=0))
        {
            j=j-1;
            flag=1;
            cmpcount3++;
        }
        r=c[i];//��¼a[i]
        for(k=i-1;k>=j+1;k--)
        {
            c[k+1]=c[k];//����Ԫ������
            if(flag) swapcount3++;
        }
        c[j+1]=r;
        if(flag) swapcount3++;
    }
    printf("%d %d",cmpcount3,swapcount3);
    return 0;
}
*/

//T4 ɾ���ظ���Ԫ��
/*
int main()
{
    int i,j,k,m,n,count=0,a[100],flag=1;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);//��������Ԫ��
    for(i=0;i<n;i++)
    {
        flag=1;
        m=a[i];
        n=n-count;//��������Ԫ�ظ���
        count=0;//���������
        while(flag)
        {
            flag=0;//�ȼ���˴�û���ظ�
            for(j=i+1;j<n;j++)
            {
                if(m==a[j])
                {
                    flag=1;
                    count++;//���Ԫ���ظ���Ԫ�صĸ���
                    for(k=j;k<n;k++)
                    {
                        a[k]=a[k+1];//����Ԫ����ǰ��
                    }
                }
            }
        }

    }
    for(i=0;i<n;i++) printf(i?" %d":"%d",a[i]);
    return 0;
}*/

//T5 ת��0Ԫ�� �������Ƶ�ĩβ
/*
int main()
{
    int i,number,n,n0=0,a[100];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&number);
        if(number!=0)//����Ԫ�ص�������
        {
            a[n0]=number;
            n0++;
        }
    }
    for(i=0;i<n0;i++) printf(i?" %d":"%d",a[i]);
    for(i=n0;i<n;i++) printf(" 0");
    return 0;
}*/

//T6 ѭ������
/*
int main()
{
    int i,j,n,a[100];
    scanf("%d %d",&n,&j);//n������ĳ���,j�����Ƶ�λ��
    j=j%n;
    //��ȡ����Ԫ��
    for(i=j;i<n;i++) scanf("%d",&a[i]);//a[0]->a[j]
    for(i=0;i<j;i++) scanf("%d",&a[i]);
    for(i=0;i<n;i++) printf(i?" %d":"%d",a[i]);
    return 0;
}*/

//T7 ��������ظ�Ԫ��
/*
int main()
{
    int n,i,j,a[100],flag=1;
    scanf("%d",&n);//nλ ������Ŀ
    for(i=0;i<n*n;i++) scanf("%d",&a[i]);
    for(i=0;i<n*n;i++)
    {
        for(j=i+1;j<n*n;j++)//�Ӹ�Ԫ��֮��ʼ�Ƚ�
        {
            if(a[i]==a[j])
            {
                flag=0;
                printf("YES");
                exit(0);//ֻҪ��⵽��ͬԪ�أ��ʹ�ӡyes���˳�
            }
        }
    }
    if(flag) printf("NO");
    return 0;
}*/

//T8 ����ת��
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

//T9 ���������Խ����Ƿ�Գ�
/*
int main()
{
    int n,i,j,flag;
    int a[10][10];
    scanf("%d",&n);
    for(i=0;i<n;i++)//��ȡ
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    flag=1;
    for(i=1;i<n;i++)//���
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

//T10 �ַ�������
/*
int main()
{
    char a[255],swap;
    int i,l;
    gets(a);
    l=strlen(a);
    for(i=0;i<l/2;i++)//����
    {
        swap=a[i];
        a[i]=a[l-1-i];
        a[l-1-i]=swap;
    }
    printf("%s",a);
}*/

//T11 Լɪ������(�μ����ӵ�������
/*
int main()
{
    int i,j,n,m,s,count=0,count0=0,flag,a[1000];
    scanf("%d %d %d",&n,&s,&m);//�ܺ������������ı���
    for(i=0;i<n-s+1;i++) a[i]=s+i;//�����鸳ֵ
    for(i=n-s+1;i<n;i++) a[i]=i-n+s;
    do{
        for(i=0;i<n;i++)
        {
            if(a[i]!=0) count++;//������̭�ĺ���
            while(count%m==0&&count>count0)//������m�ı������ú��Ӿ���̭
            {
                printf("%d ",a[i]);//��ӡ��̭�ĺ���
                a[i]=0;
                count0=count0+m;//����Ȧ����ӡ��ĺ���
                break;
            }
        }
        j=0;
        for(i=0;i<n;i++)//����Ƿ��к���
        {
            if(a[i]!=0)
            {
                flag=1;
                j++;//����ĺ�������
            }
            if(j==1) flag=0;
        }
    }while(flag==1);
    return 0;
}*/

//T12 ������������
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
    //��������a������b��������
    while(flag)
    {
        flag=0;//�ȼ��豾��û����
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
                flag=1;//��������¼
            }
        }
    }
    for(i=0;i<n;i++) printf(i?" %d":"%d",a[i]);
    printf("\n");
    for(i=0;i<n;i++) printf(i?" %d":"%d",b[i]);
    return 0;
}*/

//T13 ��������
/*
int main()
{
    int direct=0;//right 0,down 1,left 2,up 3
    int number=1,i,j,n,mup=0,mdown,nleft=0,nright,a[30][30];
    scanf("%d",&n);//�����������
    mdown=n;
    nright=n;
    while(number<=n*n)//Ҫ���ϵ���
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
