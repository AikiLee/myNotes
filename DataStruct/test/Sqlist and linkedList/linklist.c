#include<ctype.h>
#include<malloc.h> /* malloc()等 */
#include<stdio.h>
#include<stdlib.h>
#include<process.h> /* exit() */
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status; /* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int Boolean; /* Boolean是布尔类型,其值是TRUE或FALSE */
typedef int ElemType;
/*线性表的单链表存储结构 */
struct LNode
 {
   ElemType data;
   struct LNode *next;
 };
typedef struct LNode *LinkList; /* 另一种定义LinkList的方法 */

/* 带有头结点的单链表的基本操作,包括算法2.8,2.9,2.10 */

void InitList(LinkList *La)
{ /* 操作结果：构造一个空的线性表L */
   *La=(LinkList)malloc(sizeof(struct LNode)); /* 产生头结点，并使L指向此头结点 */
   if(!*La) /* 存储分配失败 */
     exit(OVERFLOW);
   (*La)->next=NULL; /* 指针域为空 */
}

void DestroyList(LinkList *La)
{ /* 初始条件：线性表L已存在。操作结果：销毁线性表L */
   LinkList p,q;
   p = *La;
   while(p)
   {
    q = p->next;
    free(p);
    p = NULL;
    p=q;
   }
   *La = NULL;
}

void Delete_x(LinkList L,ElemType x)      //将后一节点的值复制到前面，删除该节点的后一个节点
{
    struct LNode *p,*q;
    q=L;
    p=L->next;
    while (p&&p->next->data != x)   //循环终止条件，p==NULL和找到该值
    {
        q=p;                //用于存储p的前一个节点
        p=p->next;
    }
    if(p->data=x)       //当找到该值的时候，将
    {
        q->next = p->next;
    }
    free(q);
}

void Peulinklists(LinkList L)       //函数的就地逆置
{
    struct  LNode *p,*q;
    if (L)
        exit(-1);
    p=L->next;
    L->next = NULL;
    while (q)
    {
        q = p->next;        //暂存插入节点后一个节点的节点
        L->next = p;
        p->next = L->next;
         p = q;
    }
    
}       


Status GetElem(LinkList La,int i,ElemType *e) /* 算法2.8 */
{ /* L为带头结点的单链表的头指针。当第i个元素存在时，其值赋给e并返回OK，否则返回ERROR */
   int j=1; /* j为计数器 */
   LinkList p=La->next; /* p指向第一个结点 */
   while(p&&j<i) /* 顺指针向后查找，直到p指向第i个元素或p为空 */
   {
     p=p->next;
     j++;
   }
   if(!p||j>i) /* 第i个元素不存在 */
     return ERROR;
   *e=p->data; /* 取第i个元素 */
   return OK;
}


/* 请将下面函数补充完整 */
Status ListInsert(LinkList La,int i,ElemType e) /* 算法2.9。不改变L */
 { /* 在带头结点的单链线性表L中第i个位置之前插入元素e */
    int j=0;
    LinkList p = La;

    while (p && j<i-1)    //定位
    {
        p=p->next;
        j++;

    }
    if (j>i-1 || !p)      //对例外情况的排查
        return FALSE;
    LinkList pNew = (LinkList)malloc(sizeof(struct LNode));
    if (!pNew)
    {
        printf("分配空间失败");
        exit(OVERFLOW);
    }
    /*开始插入*/
    pNew->next = p->next;
    p->next=pNew;
    pNew->data = e;
    return OK;

}

/* 请将下面函数补充完整 */
Status ListDelete(LinkList La,int i,ElemType *e) /* 算法2.10。不改变L */
 { /* 在带头结点的单链线性表L中，删除第i个元素，并由e返回其值 */
   int j=0;
   LinkList p = La;

   while (p && j<i-1)
   {
       p= p->next;
       j++;
   }
   if (j>i-1 || !(p->next))
   {
       return FALSE;
   }
   *e = p->next->data;

    LinkList q = p->next;
    p->next=p->next->next;
    free(q);
    return OK;
}

void ListTraverse(LinkList La)
{
   LinkList p=La->next;
   while(p)
   {
     printf("%3d",p->data);
     p=p->next;
   }
   printf("\n");
}

void MergeList(LinkList La,LinkList Lb)
{
    LinkList p = La->next;
    while (p->next)
    {
        p=p->next;
    }
    p->next=Lb->next;
    free(Lb);
}
    

void Reverlist(LinkList L)  //借助p,q两个指针变量，之后通过将各个节点重新连接到头节点之上
{
     struct LNode * p,*q;
     p=q= L->next;
     L->next = NULL;
     while (q)
     {
         q=p->next;
         p->next=L->next;
         L->next=p;
         p=q;
     }
     

}


int main()
 {
	LinkList La,Lb,Lc;
	ElemType e;
	Status i;
	int j;
	InitList(&La);
    InitList(&Lb);
    InitList(&Lc);
	for(j=1;j<=5;j++)
    {
		i=ListInsert(La,1,j);
        i=ListInsert(Lb,1,j);
    }
    printf("在La,Lb的表头依次插入1～5后：L=");
	ListTraverse(La); /* 依次对元素调用print()，输出元素的值 */
    printf("\t");
    ListTraverse(Lb);

    MergeList(La,Lb);
    printf("合并之后的链表为：");
	ListTraverse(La);
    Reverlist(La);
    ListTraverse(La);
	DestroyList(&Lb);
    ListTraverse(Lc);
    return 0;
 }
