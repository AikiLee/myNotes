#include <stdio.h>
#include <process.h>
#define MaxSize 50

typedef int Elemtype;

typedef struct SqStack{
    Elemtype data[MaxSize];
    int top;        //point to the top
}SqStack;

void Init(SqStack * S)
{
    S->top = -1;    
}

void Push(SqStack * S,Elemtype var)
{
    //full
    if(S->top == MaxSize -1)
    {
        printf("Stack is empty\n");
        exit(-1);
    }
    else
    {
        S->data[++S->top] = var;
    }
}

void Pop(SqStack * S)
{
    //empty
    if(S->top == -1) 
    {
        printf("Stack is full\n");
        exit(-1);
    }
    else
    {
        printf("弹出的是: %d",S->data[S->top]);
    }
}


int main()
{
    SqStack S;
    Init(&S);
    for(int i = 0;i<5;i++)
    {
        Push(&S,i);
        Pop(&S);
    }



    return 0;
}

