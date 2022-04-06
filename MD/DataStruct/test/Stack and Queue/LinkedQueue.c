/*
实现链式队列的存储，并完成基本的功能：
1.初始化 2.判空 3.入队 4.出队
采用尾插法，设置两个指针
*/

#include <stdio.h>
#include <process.h>
#include <malloc.h>
#include <stdbool.h>

#define MaxSize 50
typedef int Elemtype;
typedef struct LinkedNode
{
    /* data */
    Elemtype data;
    struct LinkedNode * next; //指针域
}LinkedNode;

typedef struct LinkedQueue
{
    /* data */
    LinkedNode *front,*rear;    //头尾指针
}LinkedQueue;

void Init(LinkedQueue * LQ)
{//建立头节点,直接用front作为头指针，并初始化头尾指针的关系
    LQ->front = LQ->rear = (LinkedNode *)malloc(sizeof(LinkedNode));
    LQ->front->next = NULL;
}

bool isEmpty(LinkedQueue * LQ)
{//判断是否为空
    if(LQ->front == LQ->rear) return true;
    else return false;
}

void EnQueue(LinkedQueue * LQ,Elemtype var)
{//入队，具体操作步骤：1.新建一个结点并尾插(由于是链队列，不许要判断是否为满) 2.给结点赋值 3.更新指针
    LinkedNode * p = (LinkedNode * )malloc(sizeof(LinkedNode));
    p->data = var;
    p->next = NULL;

    LQ->rear->next = p;
    LQ->rear = p;
}


void DeQueue(LinkedQueue * LQ)
{//出队，操作步骤：1.判断是否队为空 2.将front结点指向的结点删除，并返回值 3.更新指针
    if(isEmpty(LQ) printf("链队列为空，无法出队\n");
    else
    {
        LinkedNode * p =  LQ->front->next;
        LQ->front->next = p->next;
        printf("删除的结点值为：%d",p->data);
        if(Q->rear == p) Q->front = Q->rear;    //原队列只有一个结点，删除后变空
        free(p);

    }
}

int main()
{
    

    return 0;
}