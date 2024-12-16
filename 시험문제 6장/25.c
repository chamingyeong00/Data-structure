#include <stdio.h>
#include <stdlib.h>

sturct Node{
    int vertex;
    struct Node* next;
};

struct Graph{
    int numVertices;
    struct Node** adjLists;
    int isDirected; //0:무방향 1:방향
}

struct Node* createNode(int v){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices, int isDirecte){
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Grpah));
    graph->numVertices = vertices;
    graph->isDirected = isDirecte;

    graph->adjLists = (struct Node*)malloc(vertices * sizeof(struct Node*));

    for (int i=0; i<vertices; i++){
        graph->adjListsp[i] = NULL;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest){
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    if (!graph->isDirected){
        newNode = createNode(src);
        newNode->next = graph->adjLists[dest];
        graph->adjLists[dest] = newNode;
    }
}

void printGraph(struct Graph* graph){
    printf("Vertex : Adjacency List\n");
    for (int v =0; v < graph->numVertices; v++){
        struct Node* temp = graph->adjLists[v];
        printf("%d ---> ", v);
        while(temp){
            printf("  %d ->", temp->vertex);
            temp = temp->next;
        }
        printf(" NULL\n");
    }
}