#include <stdbool.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define maxSize 10

typedef int QElemType;
typedef int Status;

typedef struct      //定义队列的结构体,储存基址，队头和队尾指针
{
    QElemType * base;
    int front;
    int rear;
}SqQueue; 

Status InitQueue(SqQueue *Q)
{
    Q->base = (QElemType *)malloc(sizeof(QElemType)*maxSize);
    if (!Q->base)
        exit(-1);       //储存空间分配失败
    Q->front=Q->rear=0;
    return OK;
}

int QueueuLength(SqQueue Q)
{
    return (Q.rear-Q.front+maxSize)%maxSize;    //循环队列的缘故，防止队尾跑到对头之前
}

Status EnQueue(SqQueue *Q,QElemType e)
{
    if((Q->rear+1)%maxSize==Q->front)
        return ERROR;           //此时队列满
    Q->base[Q->rear] = e;
    Q->rear = (Q->rear+1)%maxSize;      //依照循环队列的特性
}

Status IsEmpty(SqQueue Q)
/*判断队列是否为空*/
{
    if(Q.front == Q.rear)
        return TRUE;
    else
        return FALSE;
}

Status DeQueue(SqQueue * Q,QElemType * e)
/*删除队首元素，并返回其值*/
{
    if(IsEmpty(*Q))
        return ERROR;
    *e = Q->base[Q->front];
    Q->front = (Q->front+1)%maxSize;
}
void Clear(SqQueue *Q)
{
    Q->front=Q->rear=0;     //清空“指针”中的数据
}

void Destroy(SqQueue *Q)
{
    free(Q->base);
    Q->base = NULL;
    Q->front = 0;
    Q->rear=0;
}
void Traverse(SqQueue Q)
{
    QElemType p = Q.front;
    while(p!=Q.rear)
    {
        printf(" %d",Q.base[p]);
        p=(p+1)%maxSize;
    }
    printf("\n");
}
void main()
{
    SqQueue Q;
    QElemType e;
    InitQueue(&Q);
    for(int i = 1;i<9;i++)
    {
        EnQueue(&Q,i);
    }
    printf("\n初始循环队列为：");
    Traverse(Q);
    DeQueue(&Q,&e);
    EnQueue(&Q,5);
    EnQueue(&Q,5);
    EnQueue(&Q,5);
    printf("\n增加删除几个数据后：");
    Traverse(Q);
    Clear(&Q);
    printf("\n清空后队列为：");
    Traverse(Q);
    Destroy(&Q);
}
