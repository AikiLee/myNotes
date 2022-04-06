#include <stdio.h>
#include <malloc.h>
#include <process.h>
#define error 0;
#define True 1;
#define False 0;
#define null 0;
typedef char TElemType;
typedef int Status;
typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild, *rchild; /* 左右孩子指针 */
} BiTNode, *BiTree;

void InitBiTree(BiTree *T){
    *T = null;
}

void CreatBitree(BiTree *T){    //还需要注意的是，传入的参数是一个二级指针
    TElemType ch;
    scanf("%c",&ch);
    if(ch == ' ')
    {
        *T = NULL;
    }
    else{
        (*T) = (BiTNode *)malloc(sizeof(BiTNode));
        if(!(*T))   //如果分配失败
            exit(-1);
            (*T)->data = ch;
        CreatBitree(&((*T)->lchild)); //递归创建结点
        CreatBitree(&((*T)->rchild));
    }
}

void Destroy(BiTree *T){
    if(*T){//先左后右再删根
        if((*T)->lchild) Destroy(&(*T)->lchild);
        if((*T)->rchild) Destroy(&(*T)->rchild);

        free(*T);   //所占空间还在，只是删了指针
        *T = NULL;  //保险，防止野指针
    }
    //空指针就不用管了
}

void PreOrderTraverse(BiTree T,void (*Visit)(TElemType))
{//前序
    if(T){
        Visit(T->data);
        PreOrderTraverse(T->lchild,Visit);
        PreOrderTraverse(T->rchild,Visit);
    }
}

void InOrderTraverse(BiTree T,void (*Visit)(TElemType))
{//中序
    if(T){
        InOrderTraverse(T->lchild,Visit);
        Visit(T->data);
        InOrderTraverse(T->rchild,Visit);
    }
}

void PostOrderTraverse(BiTree T,void (*Visit)(TElemType))
{//后序遍历
    if(T){
        PostOrderTraverse(T->lchild,Visit);
        PostOrderTraverse(T->rchild,Visit);
        Visit(T->data);
    }
}

void LevelOrderTraverse(BiTree T,void  (*Visit)(TElemType))
{//层序遍历
    if(T)
    {
        
    }
}

void Visit(TElemType e)
{
    printf("%c ",e);
}

Status BiTreeEmpty(BiTree T)
{
    if(T)
    {
        return False;
    }
    else return True;
}

//基础的实现完成了，现在实现几个功能
//1.求深度
//2.求叶子结点数
int main()
{
    BiTree T;
    TElemType e;
    InitBiTree(&T);
    printf("构造二叉树完成，树空否？%d(0:不是，1:是)",BiTreeEmpty(T));
    printf("现在开始创建二叉树,请输入二叉树：");
    CreatBitree(&T);
    printf("现在打印二叉树：\n");
    PreOrderTraverse(T,Visit);
    return 0;
}