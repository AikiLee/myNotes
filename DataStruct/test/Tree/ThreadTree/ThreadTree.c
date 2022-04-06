#include "./global.h"
#include <stdio.h>
#include <malloc.h>

/***************************************************************************************************** 
 *Copyright:Yue Workstation 
 * 
 *FileName: IndexTree.c 
 * 
 *Function: 线索二叉树操作 
 * 
 *Author:Abel Lee 
 * 
 *CreateOn:2012-2-19 
 * 
 *Log:2011-5-3 由Abel Lee创建 
 *****************************************************************************************************/ 
 
/**************************************************************************************************** 
 *Function Name: CreateTree 
 * 
 *Function: 按先序输入建立二叉树 
 * 
 *Parameter:   无 
 * 
 *Return Value:成功返回树的指针，失败返回NULL 
 * 
 *Author:Abel Lee 
 * 
 *Log:2012-2-19 
 ***************************************************************************************************/ 
BiThreTree *CreateTree(void) 
{ 
    BiThreTree *T; 
    DataType e; 
    scanf("%d",&e); 
    if(e==0) 
    { 
        T=NULL; 
    } 
    else 
    { 
        T=(BiThreTree *)malloc(sizeof(BiThreTree)); 
        T->data=e; 
        T->LTag=Link;          //初始化时指针标志均为Link 
        T->RTag=Link; 
        T->lchild=CreateTree(); 
        T->rchild=CreateTree(); 
    } 
    return T; 
} 
 
/**************************************************************************************************** 
 *Function Name: InThread 
 * 
 *Function: 
 * 
 *Parameter:   无 
 * 
 *Return Value:成功返回树的指针，失败返回NULL 
 * 
 *Author:Abel Lee 
 * 
 *Log:2012-2-19 
 ***************************************************************************************************/ 
void InThread(BiThreTree *T) 
{ 
    BiThreTree *p; 
    p=T; 
 
    if(p) 
    { 
        InThread(p->lchild); 
        if(!p->lchild) 
        { 
            p->LTag=Thread; 
            p->lchild=pre; 
        } 
        if(!pre->rchild) 
        { 
            pre->RTag=Thread; 
            pre->rchild=p; 
        } 
        pre=p; 
        InThread(p->rchild); 
    } 
} 
 
/**************************************************************************************************** 
 *Function Name: InOrderThrTree 
 * 
 *Function: 中序线索化二叉树 
 * 
 *Parameter:   T:二叉树指针 
 * 
 *Return Value:成功返回树的指针，失败返回NULL 
 * 
 *Author:Abel Lee 
 * 
 *Log:2012-2-19 
 ***************************************************************************************************/ 
BiThreTree *InOrderThrTree(BiThreTree *T) 
{ 
    BiThreTree *Thre;                  //Thre为头结点的指针 
 
    Thre=(BiThreTree *)malloc(sizeof(BiThreTree)); 
    if(Thre == NULL) 
    { 
        perror("Thre == NULL,malloc error!\n"); 
        return NULL; 
    } 
    Thre->lchild=T; 
    Thre->rchild=Thre; 
    pre=Thre; 
    InThread(T); 
    pre->RTag=Thread; 
    pre->rchild=Thre; 
    Thre->rchild=pre; 
    return Thre; 
} 
 
/**************************************************************************************************** 
 *Function Name: InThrTravel 
 * 
 *Function: 中序遍历二叉树 
 * 
 *Parameter:   Thre:二叉树指针 
 * 
 *Return Value:成功返回树的指针，失败返回NULL 
 * 
 *Author:Abel Lee 
 * 
 *Log:2012-2-19 
 ***************************************************************************************************/ 
void InThrTravel(BiThreTree *Thre) 
{ 
    BiThreTree *p; 
 
    p=Thre->lchild; 
    while(p!=Thre)                  //指针回指向头结点时结束 
    { 
        while(p->LTag==Link) 
          p=p->lchild; 
        printf("%4d",p->data); 
        while(p->RTag==Thread&&p->rchild!=Thre) 
        { 
            p=p->rchild; 
            printf("%4d",p->data); 
        } 
        p=p->rchild; 
    } 
}

int main()
{
    BiThreTree *T,*B;
    T = CreateTree();
    B = InOrderThrTree(T);
    InThrTravel(B);

    return 0;
}