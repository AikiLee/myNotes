#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#define max 1000
typedef int elemtype;
int visited[max];
typedef char VertexType;
// BFS
//队列的基本操作
typedef struct QueueNode
{
    elemtype data;
    struct QueueNode *next;
} Squeue, *queue;
typedef struct
{
    queue front, rear;
} Queue, *LinkQueue;
//图的声明
typedef struct EdgeNode
{
    int adjvex;            //指向对应顶点数组的头节点
    int value;             //权值
    struct EdgeNode *next; //指向下一条弧的指针
} EdgeNode;
//顶点表结点
typedef struct VertexNode
{
    VertexType data;     //顶点信息
    EdgeNode *firstedge; //头指针
} VertexNode, AdjList[max];

typedef struct
{
    AdjList adjlist;
    int numVertexes, numEdges;
} GraphAdjList, *Mgraph;
//创建邻接表

void init(LinkQueue Q)
{
    Q->front = Q->rear = (queue)malloc(sizeof(Squeue));
    Q->front->next = NULL;
}
bool isEmpty(LinkQueue Q)
{
    if (Q->front == Q->rear)
        return true;
    else
        return false;
}
void EnQueue(LinkQueue Q, elemtype x)
{
    queue s = (queue)malloc(sizeof(Squeue));
    s->data = x;
    s->next = NULL;
    Q->rear->next = s;
    Q->rear = s;
}
bool DeQueue(LinkQueue Q)
{
    if (Q->front == Q->rear)
        return false;
    queue p = Q->front->next;
    elemtype x = p->data;
    Q->front->next = p->next;
    if (Q->rear == p)
        Q->rear = Q->front;
    free(p);
    return true;
}
void Create(GraphAdjList *G)
{

    int i, j, k;
    EdgeNode *p;

    printf("输入顶点数和边数:\n");
    scanf("%d%d", &G->numVertexes, &G->numEdges);

    //输入顶点信息
    printf("输入顶点信息:\n");
    for (i = 0; i < G->numVertexes; i++)
    {
        getchar();
        scanf("%c", &G->adjlist[i].data);
        G->adjlist[i].firstedge = NULL; //将指向边表的指针初始化
    }

    //建立边表
    printf("输入边(Vi,Vj)中的下标i,j和权值:\n");
    for (k = 0; k < G->numEdges; k++)
    {
        int v = 0;
        p = (EdgeNode *)malloc(sizeof(EdgeNode));
        scanf("%d%d%d", &i, &j, &v);
        p->value = v;
        p->adjvex = j;                     //存储弧头
        p->next = G->adjlist[i].firstedge; //头插法插入边结点
        G->adjlist[i].firstedge = p;
        //下面代码有向图无,无向图有
        p = (EdgeNode *)malloc(sizeof(EdgeNode));
        p->value = v;
        p->adjvex = i;                     //存储弧头
        p->next = G->adjlist[j].firstedge; //头插法插入边结点
        G->adjlist[j].firstedge = p;
    }
}
void visit(GraphAdjList *G, int v)
{
    if (G != NULL)
        printf("%c ", G->adjlist[v].data);
}

void BFS(GraphAdjList *G, int v, LinkQueue Q)
{                //解决了图的遍历问题，以顺序访问了图的结点
    visit(G, v); //访问初始的结点
    visited[v] = 1;
    EnQueue(Q, v);
    while (!isEmpty(Q))
    {
        /* code */
        DeQueue(Q);
        EdgeNode *p = G->adjlist[v].firstedge;
        while(p != NULL)
        {
            if (!visited[p->adjvex])
            {
                visit(G, p->adjvex);
                visited[p->adjvex] = 1;
                EnQueue(Q, p->adjvex);
                // printf("现在访问的是：%d", p->adjvex);
            }
            p->next;
        }
    }
}

void BfsTraverse(GraphAdjList *G)
{ //实现遍历
    for (int i = 0; i < G->numVertexes; i++)
    {
        visited[i] = 0;
    }
    LinkQueue Q;
    init(Q);
    for (int i = 0; i < G->numVertexes; i++)
    {
        if (visited[i] == 1)
            BFS(G, i, Q);
    }
}


int main()
{
    GraphAdjList G;
    Create(&G);
    BfsTraverse(&G);
    return 0;
}