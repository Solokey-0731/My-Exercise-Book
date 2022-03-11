#include<bits/stdc++.h>
#include<malloc.h>
#define MAX_TREE_SIZE 1000
using namespace std;

// ## Notation and Record Ways

// Parent Notation
/*
typedef struct TNode
{
    int data;
    int parent;
}Tnode;
typedef struct
{
    Tnode nodes[MAX_TREE_SIZE];
    int r,n;
}PTree;
*/

// Child Notation
/*
typedef struct childptr
{
    int name;
    struct childptr* nxt;
}*childptr;
typedef struct
{
    int data;
    childptr firstchild;
}childlist;
typedef struct Treenode
{
    int r,n;
    childlist nodes[MAX_TREE_SIZE];
}Tnode;
*/


// Par-Child Notation
// just adding a parent to every node 

// Sib-Child Notation(!*!)
/*    //Like a Binary Tree
typedef struct TreeNode
{
    int data;
    struct TreeNode* fstchild,*rgtsib;
}TreeNode,*pTreeNode;//its firstchild and rightsibling
*/

// Binary Tree

// Properties:
// 1 Each Floor 2^(n-1) node(s) 2^(n-1)~2^n-1
// 2 Leaf=Terminal Node 
// 3 Nodes' degree n0=n2+1
// 4 Degree k=floor(log2n)+1
// 5 Node's Parent floor(i/2)(i>1)  null(i=1)
// 6 Left Child: 2i   Right Child: 2i+1

// Record
/*
// 1 Sequential
// 2 Listlink(*) lchild/data/rchild

typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode,*BiTree;*/

// Traversal (Recursion)
/*
// 1 DLR
void PreOrder(BiTree T)
{
    if(T==NULL) return ;
    printf("%c", T->data);
    PreOrder(T->lchild);
    PreOrder(T->rchild);
}

// 2 LDR
void InOrder(BiTree T)
{
    if(T==NULL) return ;
    InOrder(T->lchild);
    printf("%c", T->data);
    InOrder(T->rchild);
}

// 3 LRD
void PostOrder(BiTree T)
{
    if(T==NULL) return ;
    PostOrder(T->lchild);
    PostOrder(T->rchild);
    printf("%c",T->data);
}*/

// Create a Binary Tree (Recursion and Linklist)
/*
void Build(BiTree *T)
{ 
    char ch;
    ch=getchar();
    if(ch=='*') 
    {
        *T=NULL;
    }
    else
    {
        *T=(BiTree)malloc(sizeof(BiTNode));
        (*T)->data=ch;
        Build(&(*T)->lchild);
        Build(&(*T)->rchild);
    }
}
int main()
{
    BiTree *T;
    Build(T);
    return 0;
}*/

// Binary Thread Tree--Traversal with modifying the null pointer
// Record
typedef enum{Link,Thread}PointerTag;
typedef struct BiThrNode
{
    char data;
    struct BiThrNode *lchild;
    struct BiThrNode *rchild;
    PointerTag ltag;
    PointerTag rtag;
}BiThrNode,*BiThrTree;

// LDR InThreding
BiThrTree pre=NULL;
void InThreading(BiThrTree p)
{
    if(p)
    {
        InThreading(p->lchild);// recursion to inthread left Subtree
        if(!p->lchild)
        {
            p->ltag=Thread;
            p->lchild=pre;
        }
        if(!pre->rchild)
        {
            pre->rtag=Thread;
            pre->rchild=p;
        }
        pre=p;
        InThreading(p->rchild); // recursion to inthread right Subtree
    }
}



