#include <ctype.h>
#include <malloc.h> /* malloc()等 */
#include <stdio.h>
#include <stdlib.h>
#include <process.h> /* exit() */
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define maxsize 10
#define increasment 5
typedef int Status;
typedef int Elemtype;

typedef struct 
/*定义线性表的结构体*/
{
    Elemtype * Base;
    int length;
    int listSize;
}Sqlist;

void Init_Sqlist(Sqlist * S)
/*初始化要用malloc函数分配空间，将结构体中的成员初始化*/
{
    S->Base = (Elemtype *)malloc(sizeof(Elemtype)*maxsize);
    if(!S)
    {
        printf("分配内存空间失败");
        exit(-1);
    }
    S->length=0;        
    S->listSize=maxsize;
}

Status Insert(Sqlist * S,Elemtype val,int pos)
/*在线性表中插入某个数，先要判断位置的合法性，之后再确定位置。插入时要注意有效长度，同时内存空间不够的时候可以再追加一个增量*/
{
    if(pos<1 || pos>S->listSize+1)      //基址就不存东西了
        return ERROR;
    if(S->length >= S->listSize)         //在此处进行检查是否超过线性表长度
    {
        Elemtype * newBase = (Elemtype *)realloc(S->Base,sizeof(Elemtype)*(maxsize+increasment));       //存储空间再分配
        if(!newBase)
            exit(-1);
        S->Base = newBase;
        S->listSize += increasment; 
    }
    Elemtype* q = &(S->Base[pos-1]);        //确定插入位置
    for(Elemtype* p = &(S->Base[S->length-1]);p>=q;--p)
    {
        *(p+1) = *p; 
    }
        *q = val;
        ++S->length;
    return OK;
}
void Travse(Sqlist * S)
{
    printf("线性表中元素为：\n");
    for(int i=0;i<S->length;i++)
    {
        printf(" %d",S->Base[i]);
    }
}

void main()
{
    Sqlist * S;
    Init_Sqlist(S);
    for (int i =0;i<maxsize;i++)
    {
        Insert(S,i,i);
    }
    Travse(S);
    printf("\n %d",S->length);
    printf("\n %d",S->listSize);
}