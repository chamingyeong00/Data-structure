#define FALSE 0
#define TRUE 1
short int visited[MAX_VERTICES];

void dfs(int v){
    struct node *w;
    visited[v] = TRUE;
    printf("%5d", v);
    for (w = graph[v]; w; w = w->link)
        if (!visited[w])
            dfs(w->vertex);
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