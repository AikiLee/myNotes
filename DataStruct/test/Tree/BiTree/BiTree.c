#include <ctype.h>
#include <malloc.h> /* malloc()等 */
#include <stdio.h>
#include <stdlib.h>
#include <process.h> /* exit() */
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;  /* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int Boolean; /* Boolean是布尔类型,其值是TRUE或FALSE */
typedef char TElemType;
TElemType Nil = ' '; /* 字符型以空格符为空 */

/*二叉树的二叉链表存储表示 */
typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild, *rchild; /* 左右孩子指针 */
} BiTNode, *BiTree;

void InitBiTree(BiTree *T)
{ /* 操作结果：构造空二叉树T */
    *T = NULL;
}

void CreateBiTree(BiTree *T)
{ /* 按先序次序输入二叉树中结点的值(可为字符型或整型，在主程中定义)，*/
    /* 构造二叉链表表示的二叉树T。变量Nil表示空(子)树。有改动 */
    TElemType ch;
    scanf("%c", &ch);
    if (ch == ' ')
        *T = NULL;
    else
    {
        (*T) = (BiTNode *)malloc(sizeof(BiTNode));
        if (!(*T))
            exit(OVERFLOW);
        (*T)->data = ch;
        CreateBiTree(&((*T)->lchild));
        CreateBiTree(&((*T)->rchild));
    }
}

void DestroyBiTree(BiTree *T)
{           /* 初始条件：二叉树T存在。操作结果：销毁二叉树T */
    if (*T) /* 非空树 */
    {
        if ((*T)->lchild)                 /* 有左孩子 */
            DestroyBiTree(&(*T)->lchild); /* 销毁左孩子子树 */
        if ((*T)->rchild)                 /* 有右孩子 */
            DestroyBiTree(&(*T)->rchild); /* 销毁右孩子子树 */
        free(*T);                         /* 释放根结点 */
        *T = NULL;                        /* 空指针赋0 */
    }
}

void PreOrderTraverse(BiTree T, void (*Visit)(TElemType))
{ /* 初始条件：二叉树T存在，Visit是对结点操作的应用函数。算法6.1，有改动 */
    /* 操作结果：先序递归遍历T，对每个结点调用函数Visit一次且仅一次 */
    if (T) /* T不空 */
    {
        Visit(T->data);                     /* 先访问根结点 */
        PreOrderTraverse(T->lchild, Visit); /* 再先序遍历左子树 */
        PreOrderTraverse(T->rchild, Visit); /* 最后先序遍历右子树 */
    }
}

void InOrderTraverse(BiTree T, void (*Visit)(TElemType))
{ /* 初始条件：二叉树T存在，Visit是对结点操作的应用函数 */
    /* 操作结果：中序递归遍历T，对每个结点调用函数Visit一次且仅一次 */
    if (T)
    {
        InOrderTraverse(T->lchild, Visit); /* 先中序遍历左子树 */
        Visit(T->data);                    /* 再访问根结点 */
        InOrderTraverse(T->rchild, Visit); /* 最后中序遍历右子树 */
    }
}

void PostOrderTraverse(BiTree T, void (*Visit)(TElemType))
{ /* 初始条件：二叉树T存在，Visit是对结点操作的应用函数 */
    /* 操作结果：后序递归遍历T，对每个结点调用函数Visit一次且仅一次 */
    if (T) /* T不空 */
    {
        PostOrderTraverse(T->lchild, Visit); /* 先后序遍历左子树 */
        PostOrderTraverse(T->rchild, Visit); /* 再后序遍历右子树 */
        Visit(T->data);                      /* 最后访问根结点 */
    }
}

Status BiTreeEmpty(BiTree T)
{ /* 初始条件：二叉树T存在。操作结果：若T为空二叉树，则返回TRUE，否则FALSE */
    if (T)
        return FALSE;
    else
        return TRUE;
}
TElemType Root(BiTree T)
{ //初始条件：二叉树T存在。操作结果：返回T的根
    if (BiTreeEmpty(T))
        return Nil;
    else
        return T->data;
}

void visitT(TElemType e)
{
    printf("%c ", e);
}

int depth(BiTree T)
/*求二叉树深度*/
{
    int dep = 0, depl, depr;
    if (T)
    {
        depl = depth(T->lchild);
        depr = depth(T->rchild);

        return depl>depr?(depl+1):(depr+1);
    }
}

int CalculateTreeNode(BiTree T)
{
    int m=0;
    if (T) /* T不空 */
    {
        m = 1+CalculateTreeNode(T->lchild)+CalculateTreeNode(T->rchild);
    }
    return m;

}
void CopyTree(BiTree T,BiTree * NewTree)
{
    if(T)
    {
        *NewTree = (BiTree)malloc(sizeof(BiTNode));
        (*NewTree)->data = T->data;
        CopyTree(T->lchild,&((*NewTree)->lchild));
        CopyTree(T->rchild,&((*NewTree)->rchild));
    } 
    else
    {
        *NewTree = NULL;
    }
    
}
int CalculateLeave(BiTree T,int num)
{
    if(T)
    {
        if (!T->lchild && !T->rchild)
            num++;
        num = CalculateLeave(T->lchild, num);
        num = CalculateLeave(T->rchild, num);
	}
    return num;
}

void main()
{
        BiTree T,NewTree;
        TElemType e1;
        InitBiTree(&T);
        printf("构造空二叉树后,树空否？%d(1:是 0:否)\n", BiTreeEmpty(T));
        e1 = Root(T);
        if (e1 != Nil)
            printf("二叉树的根为: %c\n", e1);
        else
            printf("树空，无根\n");
        printf("请先序输入二叉树(如:ab三个空格表示a为根结点,b为左子树的二叉树)\n");
        CreateBiTree(&T);
        printf("建立二叉树后,树空否？%d(1:是 0:否) \n", BiTreeEmpty(T));
        e1 = Root(T);
        if (e1 != Nil)
            printf("二叉树的根为: %c", e1);
        else
            printf("树空，无根");
        printf("\n先序递归遍历二叉树:");
        PreOrderTraverse(T, visitT);
        printf("\n中序递归遍历二叉树:");
        InOrderTraverse(T, visitT);
        printf("\n后序递归遍历二叉树:");
        PostOrderTraverse(T, visitT);
        printf("\n二叉树的深度为:%d",depth(T));
        printf("\n二叉树的节点数:%d",CalculateLeave(T,0));

        printf("\n复制一棵树之后");
        CopyTree(T,&NewTree);
        printf("\n先序递归遍历复制的二叉树:");
        PreOrderTraverse(NewTree,visitT);


        DestroyBiTree(&T);
}
