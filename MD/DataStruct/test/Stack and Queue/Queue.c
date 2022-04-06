/*
实现一个循环队列，采用顺序表的形式
仅实现基本功能：
1.Init 2.isEmpty 3.EnQueue 4. DeQueue
*/

#include <stdio.h>
#include <process.h>
#include <stdbool.h>
#define MaxSize 5
typedef int Elemtype;
typedef struct Queue
{
    Elemtype data[MaxSize];
    int front,rear;         //头尾指针
}SqQueue;

void Init(SqQueue * Q)
{
    Q->front = 0,Q->rear = 0;
}

bool isEmpty(SqQueue * Q)
{
    if(Q->front == Q->rear) return true;
    else return false;
}

void EnQueue(SqQueue * Q,int var)
{
    if((Q->rear+1)%MaxSize == Q->front)
    {
        printf("队列已满\n");
    }
    else
    {
        Q->data[Q->rear++] = var;
    }
}
void DeQueue(SqQueue * Q)
{
    if(isEmpty(Q)) printf("队列为空，无法出队\n");
    else
    {
        printf("出队元素是：%d",Q->data[Q->front++]);
    }
}

int main()
{
    SqQueue Q;
    Init(&Q);
    for(int i = 1;i<3;i++)
    {
        EnQueue(&Q,i);
    }
    DeQueue(&Q);
    DeQueue(&Q);
    EnQueue(&Q,6);
    DeQueue(&Q);
    DeQueue(&Q);


    return 0;
}