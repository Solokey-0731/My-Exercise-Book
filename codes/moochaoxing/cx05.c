#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


//T1 ɾ���ַ�
/*
char* str_delete(char* s, int v, int w)
{
    int i,l;
    l=strlen(s);
    for(i=0;i<l-w;i++)
    {
        if(i>=v-1)//�滻
        *(s+i)=*(s+i+w);
    }
    return s;
}


//T1 �ַ�������ɾ��
/*char* str_delete(char* s, int v, int w)
{
    int i, i1,i2, l, space1 = 0, space2 = 0, count = 0;
    l = strlen(s);
    for (i = 0;count < v;i++)//ͳ�Ƶ�v���ַ�֮ǰ�Ŀո�
    {
        if (*(s + i) != ' ') count++;
        else space1++;
    }
    //����ʱ��i-1��Ӧ��v���ַ�,��Ҫ���������ĵ�һ��
    i1 = i-1;
    count = 0;//����������
    //ͳ��w���ַ��еĿո�
    for (i = i1;count < w;i++)
    {
        if (*(s + i) == ' ') space2++;
        else
        {
            count++;//����ʱi��Ӧ����ĵ�w���ַ�
        }
    }
    count = 0;//�������ٴ�����
    for (i = i1;count < w;i++)
    {
        if (i < i1 + space2)
        {
            *(s + i) = ' ';//���Ҫɾ����w���ַ��еĿո�
        }
        else
        {
                *(s + i) = *(s + i1+w+space2+count);
                count++;//����ʱ�Ѿ��滻�����һ���ַ�
        }
    }
    i2 = i;//��ʱi��Ӧ���滻������һ���ַ�֮����ַ�
    //������ַ���ǰ��
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
    for (i = 0;i < l - w;i++) printf("%c", *(s + i));//ֻ��ӡl-w���ַ�
    return 0;
}
*/

//T2 �����ά����
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

//T3 �Ϸ���ʶ��
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
        if(p==0)//�жϿ�ͷ
        {
            if(m!='_'&&((m<65||m>90)&&(m<97||m>122)))//�����»��ߺ���ĸ
               {
                   return 0;
               }
        }
        else
        {
           if(m!='_'&&((m<65||m>90)&&(m<97||m>122))&&(m<48||m>57))//�����»��ߡ���ĸ������
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

//T4 ����ͳ���ַ�
/*
void count(char* str, int* upper, int* lower, int* space, int* num, int* other)
{
    while (*str != '\0')
    {
        if (*str >= 65 && *str <= 90) *upper=*upper+1;//������uper++
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

//T5 �ַ�������
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
