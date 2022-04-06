#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include<process.h>
#include<stdbool.h>
#include<limits.h>
#include<string.h>

#define INFINITY INT_MAX;      //最大值
#define MAX_VERTEX_NUM  20        //最大顶点数
#define error 0

typedef int VRType;
typedef int VertexType;
typedef bool InfoType;

typedef enum{DG,DN,UDG,UDN}GraphKind;    //定义{有向图，有向网，无向图，无向网}
typedef struct ArcCell{
    VRType adj;     //VRType为顶点关系类型，有权图为1

    InfoType *info;  //该弧相关的信息指针
}ArcCell,AdMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct {
    VertexType vexs[MAX_VERTEX_NUM];        //顶点向量
    AdMatrix arcs;                          //邻接矩阵
    int vexnum,arcnum;                    //图的当前顶点数和弧数
    GraphKind kind;                              //图的种类
}MGraph;


int LocateVex(MGraph *G, VertexType u)
{ /* 初始条件:图G存在,u和G中顶点有相同特征 */
  /* 操作结果:若G中存在顶点u,则返回该顶点在图中位置;否则返回-1 */
	for (int i = 0; i < G->vexnum; ++i)
		if (strcmp(u,G->vexs[i]) == 0)
			return i;
	return -1;
}


bool CreateGraph(MGraph *G){
    scanf(&G->kind);
    switch (G->kind)
    {
    case DG:
        return CreateDG(G);         //构造有向图
        break;
    case DN:
        return CreateDN(G);         //构造有向网
        break;
    case UDG:
        return CreateUDG(G);        //构造无向图
        break;
    case UDN:
        return CreateUDN(G);        //构造无向网
        break;
    default:
        return error;
        break;
    }
}


bool CreateUDN(MGraph *G)
{
    /*采用邻接矩阵法构造无向网G*/
    int v1,v2,w,IncInfo;   
    scanf(&G->vexnum,&G->arcnum,&IncInfo);
    for(int i=0;i<G->vexnum;i++){
        scanf(&G->vexs[i]);         //构造顶点向量
    }
    for (int i = 0; i < G->vexnum; i++)
    {
        for(int j=0;j<G->vexnum;j++){
            G->arcs[i][j].adj = 0;    //初始化邻接矩阵，赋值为{adj,info}     
            G->arcs[i][j].info= NULL;     
        }
    }
    for(int k=0;k<G->vexnum;k++)        //构造临界矩阵
    {
        scanf(&v1,&v2,&w);              //获取一条边的依附顶点和权值
        int i = LocateVex(G,v1);
        int j = LocateVex(G,v2);
        G->arcs[i][j].adj = w;              
        if(IncInfo)
            Input(*G->arcs[i][j].info);     //若弧含有相关关系，即开始输入
        G->arcs[j][i] = G->arcs[i][j];      //设置<v1,v2>的对称弧<v2,v1>
    }
    return true;
}

int main(void)
{

}