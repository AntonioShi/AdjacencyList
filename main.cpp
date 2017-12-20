#include <stdio.h>
#include "AdjMGraph.h"
#define MaxSize 10
#define MaxVertices 10
#define MaxWeight 10000

int main() {

    AdjLGraph graph ;
    DataType dataType[] = {'A', 'B', 'C', 'D', 'E'};
    RowColWeight rcw[] = {{0,1,10},{0,4,20},
                          {1,3,30}, {2,1,40},{3,2,50}};
    int vertex = 5, edge = 5;//5dian5bian
    int i, j ;
    CreateGraph(&graph, dataType, vertex, rcw, edge) ;
    printf("顶点集合为：") ;
    for (int i = 0; i < graph.numOfVerts; ++i) {
        printf("%c ", graph.a[i].data) ;
    }
    printf("\n") ;
    printf("权值集合：\n") ;
    for (int i = 0; i < graph.numOfEdges; ++i) {
        if (graph.numOfEdges)
        printf("%d ", graph.a[i].source) ;
    }
    return 0;
}