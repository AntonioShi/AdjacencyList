//
// Created by antonio on 17-12-2.
//

#ifndef ADJACENCYLIST_ADJMGRAPH_H
#define ADJACENCYLIST_ADJMGRAPH_H

typedef int DataType ;
#define MaxVertices 10


typedef struct Node {
    int ArcHead;	           //弧头顶点序号
    struct Node *next;        //单链表下一个结点
} Edge;		            /*邻接边单链表的结点结构体*/

typedef struct {
    DataType data;		/*顶点数据元素*/
    int source;		    /*邻接边的弧尾顶点序号*/
    Edge *adj;		    /*邻接边的头指针*/
} AdjLHeight;	     	/*数组的数据元素类型结构体*/

typedef struct {
    AdjLHeight a[MaxVertices];		/*邻接表数组*/
    int numOfVerts;			/*顶点个数*/
    int numOfEdges;			/*边个数*/
} AdjLGraph;				/*图的邻接表结构体*/

//创建图
typedef struct {
    int row ;
    int col ;
    int weight ;
}RowColWeight;


void AdjInitiate(AdjLGraph * G) ;

void InsertVertex(AdjLGraph * G, int i, DataType vertex) ;

void InsertEdge(AdjLGraph* G, int v1, int v2, int weight) ;

void DeleteEdge(AdjLGraph *G, int v1, int v2) ;

int GetFirstVex(AdjLGraph G, int v) ;

int GetNextVex(AdjLGraph G, int v1, int v2) ;

void AdjDestroy(AdjLGraph* G) ;

void CreateGraph(AdjLGraph *G, DataType v[], int n, RowColWeight d[], int e) ;

#endif //ADJACENCYLIST_ADJMGRAPH_H
