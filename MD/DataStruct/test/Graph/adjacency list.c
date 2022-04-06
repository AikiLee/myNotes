#include<stdio.h>
#include<malloc.h>
#define maxSize 1000         
typedef struct ArcNode {//弧结点
    int adjvex;//指向对应顶点数组的头节点
    struct ArcNode *nextarc;    //指向下一条弧的指针
} ArcNode;
  
typedef struct {
    int data;
    ArcNode *firstarc;
} Vnode;
  
//可以利用结构体整体结构，也可以拆分结构体变为单独搜索
typedef struct {
    Vnode adjlist[maxSize];
    int n, e;
} AGraph;
  
AGraph *graph;
  
//插入链表末尾
void  insertNode(ArcNode *node, ArcNode *newNode) {
    ArcNode *p = node;
    while(p->nextarc != NULL) {
        p = p->nextarc;
    }
    p->nextarc = newNode;
}
  
void create() {
    graph = (AGraph*)malloc(sizeof(AGraph));
    printf("输入顶点的数目: ");
    scanf("%d",&graph->n);
    printf( "输入图中边的数目: ");
    scanf("%d",&graph->e);
  
    int u = -1, v = -1;
    for(int i = 0; i < graph->n; i++) {
        graph->adjlist[i].firstarc = NULL;
    }
  
    ArcNode *node;
    for(int i = 0; i < graph->e; i++) {
        printf("请输入联通点A与B:");
        scanf("%d%d",&u,&v);
        node = (ArcNode *)malloc(sizeof(ArcNode));
        node->adjvex = v;   //存储
        node->nextarc = NULL;
        // graph->adjlist[u].data = u;
        if(graph->adjlist[u].firstarc == NULL) {
            //边
            graph->adjlist[u].firstarc = node;
        } else {
            //插入边
            insertNode(graph->adjlist[u].firstarc, node);
        }
    }
}
  
void  travseTree() {
    for(int i = 0; i < graph->n; i++) {
        if(graph->adjlist[i].firstarc != NULL) {
            printf("与%d连接的点有：",i);
            ArcNode *p = graph->adjlist[i].firstarc;
            while(p != NULL) {
                printf("%d",p->adjvex);
                p = p->nextarc;
            }
            printf("\n");
        }
    }
}
  
void InsertEdge()
{//插入一条边的顺序：1.定位到结点2.头插
    ArcNode * p = (ArcNode *)malloc(size(ArcNode));
    int v1,v2;
    printf("请输入要插入的边，从A指向B: ");
    scanf("%d%d",&v1,&v2);

    //无向图写法
    p->nextarc = graph->adjlist[v1]
    graph->adjlist[v1] = p;
    p->adjvex = v2;

    ArcNode * q = (ArcNode *)malloc(size(ArcNode));
    q->nextarc = graph->adjlist[v2]
    graph->adjlist[v2] = q;
    q->adjvex = v1;
}

void Visit(int V)
{
    printf("正在访问的结点时:%d",v);
}

void dfs(int V,void (*Visit)(int))
{
    ArcNode * p;
    
}

int main(void) {
    create();
    travseTree();
    return 0;
}