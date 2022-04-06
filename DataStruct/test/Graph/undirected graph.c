#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
//还可以继续进行优化
#define MaxVertusNum 100
#define INF 0xffffff
typedef struct 
{
    int Vex[MaxVertusNum]; //存放顶点信息
    int Edge[MaxVertusNum][MaxVertusNum];   //邻接矩阵
    int vernumx,auxnum; //边数和弧数
}MGraph;

void CreatUDG(MGraph *G)
{
    //先将基础信息读入
    int n,e;
    scanf("%d%d",&n,&e);
    G->auxnum = e,G->vernumx = n;
    //再将矩阵初始化一下
    for(int i = 0;i<n;i++)
        for(int j = 0;j<n;j++)
        {
            if(i == j) G->Edge[i][j]= 0;
            else
            {
                G->Edge[i][j] = -INF;
            }
        }
        for(int i = 0;i<n;i++)
        {//顶点信息
            printf("请输入顶点信息\n");
            scanf("%d",&G->Vex[i]);
        }
        for(int i = 0;i<e;i++)
        {
            int vi,vj,w;
            printf("请输入边的信息：如a b w\n");
            scanf("%d%d",&vi,&vj);
            //其中vi为出发点，vj为结束点,w为权值，非网图记为1
            G->Edge[vi-1][vj-1] = 1;
            G->Edge[vj-1][vi-1] = 1;
        }
}

int main()
{
    MGraph m;
    CreatUDG(&m);
    for(int i = 0;i<m.vernumx;i++)
    {
        for(int j = 0;j<m.vernumx;j++)
        {
            printf(" %d",m.Edge[i][j]);
        }
        printf("\n");
    }
}

