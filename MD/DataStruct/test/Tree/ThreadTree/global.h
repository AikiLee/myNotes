#ifndef INDEX_TREE_H 
#define INDEX_TREE_H 
#include "global.h" 
#define NULL 0
 
typedef enum{Link,Thread} PointerTag;     //指针标志 
typedef int DataType; 
typedef struct BiThreTree 
{               //定义结点元素 
    PointerTag LTag,RTag; 
    DataType data; 
    struct BiThreTree *lchild,*rchild; 
}BiThreTree; 
 
BiThreTree *pre;                     //全局变量，用于二叉树的线索化 
 
BiThreTree *CreateTree(void); 
void InThread(BiThreTree *T); 
BiThreTree *InOrderThrTree(BiThreTree *T); 
void InThrTravel(BiThreTree *Thre); 
 
#endif
