//
// Created by antonio on 17-12-2.
//
#include <stdlib.h>
#include <stdio.h>
#include "AdjMGraph.h"

void AdjInitiate(AdjLGraph * G) {
    int i;
    G->numOfEdges=0;
    G->numOfVerts=0;

    for(i=0;i<MaxVertices;i++) {
        G->a[i].source = i;
        G->a[i].adj=NULL;
    }
}

//直接赋值，没有考虑到会覆盖掉原来改位置的点的信息
void InsertVertex(AdjLGraph * G, int i, DataType vertex) {
    if(i>=0&&i<MaxVertices) {
        G->a[i].data=vertex;
        G->numOfVerts++;
    }
    else
        printf("顶点越界!");
}

void InsertEdge(AdjLGraph* G, int v1, int v2, int weight) {
    Edge* p;
    if(v1<0||v1>G->numOfVerts||v2<0||v2>G->numOfVerts) {
        printf("参数v1或v2出错!");
        return ;
    }
    p=(Edge* )malloc(sizeof(Edge));
    p->ArcHead=v2;//弧头坐标
    //？
    p->next=G->a[v1].adj;
    //p->weight=weight;
    G->a[v1].adj=p;
    G->numOfEdges++;
}

void DeleteEdge(AdjLGraph *G, int v1, int v2) {
    Edge * curr;
    Edge * pre;

    if(v1 < 0 || v1 >= G->numOfVerts || v2 < 0 || v2 >= G->numOfVerts) {
        printf("参数v1或v2出错!");
        return ;
    }
    pre = NULL;
    curr = G->a[v1].adj;
    while(curr != NULL && curr->ArcHead != v2) {
        pre = curr;
        curr = curr->next;
    }

    if(curr!=NULL&&curr->ArcHead==v2&&pre==NULL) {
        G->a[v1].adj=curr->next;
        free(curr);
        G->numOfEdges--;
    }
    else if(curr!=NULL&&curr->ArcHead==v2&&pre!=NULL) {
        pre->next=curr->next;
        free(curr);
        G->numOfEdges--;
    }
    else
        printf("边<v1,v2>不存在!");
}

int GetFirstVex(AdjLGraph G, int v) {
    Edge * p;

    if(v<0||v>G.numOfVerts) {
        printf("顶点越界!");
        return -1;

    }
    p=G.a[v].adj;
    if(p!=NULL) return p->ArcHead;
    else return -1;
}

int GetNextVex(AdjLGraph G, int v1, int v2) {
    Edge * p;

    if(v1<0||v1>G.numOfVerts||v2<0||v2>G.numOfVerts) {
        printf("chaojie") ;
        return -1;
    }
    p=G.a[v1].adj;
    while(p!=NULL) {
        if(p->ArcHead!=v2) {
            p=p->next;
            continue;
        }
        else break;
    }
    p=p->next;
    if(p!=NULL) return p->ArcHead;
    else return -1;
}


void AdjDestroy(AdjLGraph* G) {
    int i;
    Edge *p, *q;

    for (i = 0; i < G->numOfVerts; i++) {
        p = G->a[i].adj;
        while (p != NULL) {
            q = p->next;
            free(p);
            p = q;
        }
    }
}


void CreateGraph(AdjLGraph *G, DataType v[], int n, RowColWeight d[], int e){
    AdjInitiate(G) ;
    for (int i = 0; i < n; ++i) {
        InsertVertex(G, i, v[i]) ;
    }
    for (int j = 0; j < n; ++j) {
        InsertEdge(G, d[j].row, d[j].col, 1) ;//
    }
}

