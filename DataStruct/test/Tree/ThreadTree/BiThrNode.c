#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

typedef enum {Link, Thread} PointerTag;

typedef struct ThreadNode
{
     ElemType data;
     struct ThreadNode *lchild,*rchild;      /*左右孩子指针*/
     PointerTag LTag,RTag;               /*左右标志*/
    //  LTag=0  lchild域指示结点的左孩子
    // LTag=1  lchild域指示结点的前驱
    // RTag=0  rchild域指示结点的右孩子
    // RTag=1  rchild域指示结点的后继
}ThreadNode,*ThreadTree;

//全局变量，指向刚刚访问的变量
ThreadTree pre;



void InThread(ThreadTree T)//中序线索化
{
    char ch;
    scanf("%s",&ch);
    if(ch == "#") *T = NULL;
    else
    {
        *T = (ThreadNode *)malloc(sizeof(ThreadNode));
        if(!*T) exit(-1);
        *T->data = ch;
        *T->LTag = 
    }
}

