#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 100 /* 最大顶点数,应由用户定义 */

typedef int Status;	/* Status是函数的类型,其值是函数结果状态代码,如OK等 */
typedef char VertexType; /* 顶点类型应由用户定义 */
typedef int EdgeType; /* 边上的权值类型应由用户定义 */

typedef struct EdgeNode
{
    int adjvex;
    EdgeType weight;
    struct EdgeNode *next;
} EdgeNode;

typedef struct VertexNode
{
    VertexType data;
    EdgeNode *firstedge;
} VertexNode, AdjList[MAXVEX];

typedef struct
{
    AdjList adjList;
    int numVertexes, numEdges;
} GraphAdjList;

void CreateALGraph(GraphAdjList *G)
{
    int i, j ,k;
    EdgeNode *e;
    printf("输入顶点数和边数：\n");
    scanf("%d, %d", &G->numVertexes, &G->numEdges);
    for (i = 0; i < G->numVertexes; ++i)
    {
        scanf(&G->adjList[i].data);
        G->adjList[i].firstedge = NULL;
    }
    for (k = 0; k < G->numEdges; ++k)
    {
        printf("输入边(vi, vj)上的顶点序号：\n");
        scanf("%d, %d", &i, &j);
        e = (EdgeNode *)malloc(sizeof(EdgeNode));

        e->adjvex = j;
        e->next = G->adjList[i].firstedge;
        G->adjList[i].firstedge = e;

        e = (EdgeNode *)malloc(sizeof(EdgeNode));

        e->adjvex = i;
        e->next=G->adjList[j].firstedge;
        G->adjList[j].firstedge = e;

    }
}

int main(void)
{    
    GraphAdjList G;    
    CreateALGraph(&G);
    return 0;
}