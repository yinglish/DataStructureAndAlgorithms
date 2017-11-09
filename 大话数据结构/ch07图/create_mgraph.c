#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 100 /* 最大顶点数，应由用户定义 */
#define INFINITY 65535

typedef int Status;	/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef char VertexType; /* 顶点类型应由用户定义  */
typedef int EdgeType; /* 边上的权值类型应由用户定义 */

typedef struct
{
    VertexType vexs[MAXVEX];
    EdgeType arc[MAXVEX][MAXVEX];
    int numVertexes, numEdges;
} MGraph;

void CreateMGraph(MGraph *G)
{
    int i, j, k, w;
    printf("输入顶点数和边数：\n");
    scanf("%d,%d", &G->numVertexes, &G->numEdges);
    for (i = 0; i < G->numVertexes; i++)
    {
        scanf(&G->vexs[i]);
    }
    for (i = 0; i < G->numVertexes; ++i)
        for(j = 0; j < G->numVertexes; ++j)
        {
            G->arc[i][j] = INFINITY;
        }
    for (k = 0; k < G->numEdges; ++k)
    {
        printf("输入边(vi, vj)的上下标和权w：\n");
        scanf("%d, %d, %d", &i, &j, &w);
        G->arc[i][j] = w;
        G->arc[j][i] = G->arc[i][j];
    }
}


int main(void)
{    
	MGraph G;    
	CreateMGraph(&G);
	
	return 0;
}