struct node{
    int vertex;
    struct node *link;
};

typedef struct{
    int count;
    struct node *link;
} hdnode;
hdnode graph[MAX_VERTICES];

for (i=0; i<n; i++){
    if (every vertex has a predecessor){
        fprintf(stderr, "Network has a cycle.\n");
        exit(1);
    }
    pick a vertex v that has no predecessors;
    output v;
    delete v and all edges leading out of v from the newwork;
}

void topSort(hdnode graph[], int n){
    int i, j, k, top;
    struct node *ptr;

    top = -1;
    for (i=0; i<n; i++){
        if (!graph[i].count){
            graph[i].count = top;
            top = i;
        }
    }

    for (i=0; i<n; i++){
        if (top == -1){
            fprintf(stderr, "Network has a cycle.\n");
            exit(1);
        }else{
            j = top;
            top = graph[top].count;
            printf("v%d", j);
            for (ptr = graph[j].link; ptr != NULL; ptr = ptr->link){
                k = ptr->vertex;
                graph[k].count--;
                if (!graph[k].count){
                    graph[k].count = top;
                    top = k;
                }
            }
        }
    }

}