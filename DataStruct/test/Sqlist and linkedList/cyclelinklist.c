#include <stdio.h>
#include <process.h>
#include <malloc.h>
#define ERROR 0
#define OK 1

typedef char Elemtype;
/*
相较于单链表，单循环链表只是增加了一个尾指针，使得对尾部的操作更加方便
*/
typedef struct CLinkNode
{
    Elemtype data ;
    struct CLinkNode * next;
}CLinkNode,*CLinkList;


void InitCLinkList(CLinkList * p)
{//初始化：通过用户输入，通过头插法，直接生成链表
    if(!p)
    {
        exit(-1);
        printf("没有头节点\n");
    }
    (*p)->next = NULL;
}

void CreatNode(CLinkList * p)
{
    if(!p) exit(-1);
    while(1)
    {
        int d;
        CLinkNode * new = (CLinkNode *)malloc(sizeof(CLinkNode));
        (*p)->next = new;

        printf("请输入数据，如果输入#，则结束\n");
        scanf("%c",&d);
        if(d == '#') break;
        else ;


     }

}