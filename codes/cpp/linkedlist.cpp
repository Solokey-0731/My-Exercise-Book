#include<iostream>
#include<malloc.h>
#include<time.h>
typedef struct Node
{
    int data;
    struct Node* nxt;
}Node;

typedef Node* pnode;

int GetElem(pnode head,int i,int *e)//Read an element
{
    int j;
    pnode p;
    p=head->nxt;
    j=1;
    while(p&&j<i)
    {
        p=p->nxt;
        ++j;
    }
    if(!p||j>i)
    {
        return 0;
    }
    *e=p->data;
    return 1;
}

int ListInsert(pnode head,int i,int e)//Insert an element
{
    int j;
    pnode p,s;
    p=head;
    j=1;
    while(p&&j<i)
    {
        p=p->nxt;
        ++j;
    }
    if(p==NULL||j>i)
    return 0;
    s=(pnode)malloc(sizeof(Node));
    s->data=e;
    s->nxt=p->nxt;
    p->nxt=s;
    return 1;
}

int ListDelete(pnode head,int i,int *e)
{
    int j=1;
    pnode p,q;
    p=head;
    while(p->nxt!=NULL&&j<i)
    {
        p=p->nxt;
        ++j;
    }
    if(p->nxt==NULL||j>i)
    {
        return 0;
    }
    q=p->nxt;
    p->nxt=q->nxt;
    *e=q->data;
    free(q);
    return 1;
}

void CreateListHead(pnode head,int n)
{
    pnode p;
    int i;
    srand(time(0));
    head=(pnode)malloc(sizeof(Node));
    p->nxt=NULL;
    for(i=0;i<n;i++)
    {
        p=(pnode)malloc(sizeof(Node));
        p->data=rand()%100+1;
        p->nxt=head->nxt;
        head->nxt=p;
    }
}

void CreateListRear(pnode head,int n)
{
    pnode p,r;
    int i;
    srand(time(0));
    head=(pnode)malloc(sizeof(Node));
    r=head;
    for(i=0;i<n;i++)
    {
        p=(pnode)malloc(sizeof(Node));
        p->data=rand()%100+1;
        r->nxt=p;
        r=p;
    }
    r->nxt=NULL;
}

int ClearList(pnode head)
{
    pnode p,q;
    p=head->nxt;
    while(p)
    {
        q=p->nxt;
        free(p);
        p=q;
    }
    head->nxt=NULL;
    return 1;
}

int main()
{

}