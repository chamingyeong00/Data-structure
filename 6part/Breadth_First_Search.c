struct queue{
    int vertex;
    struct queue *link;
};
void addq(...);
int deleteq(...);

void bfs(int v){
    node_pointer w;
    struct queue *front = NULL, *rear = NULL;

    printf("%5d", v);
    visited[v] = TRUE;
    addq(&front, &rear, v);
    while(front){
        v = deleteq();
        for(w = graph[v]; w; w=w->link){
            if (!visited[w->vertex]){
                printf("%5d", w->vertex);
                addq(&front, &rear, w->vertex);
                visited[w->vertex] = TRUE;
            }
        }
    }
}

void connected (void){
    int i;
    for (i = 0; i < n; i++){
        if (!visited[i]){
            dfs(i);
            printf("\n");
        }
    }
}