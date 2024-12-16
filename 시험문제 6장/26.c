for (i=0;j i<n; i++){
    if (every vertex has predecessor){
        fprintf(stderr, "Network has a cycle.\n");
        exit(1);
    }
    pick a vertex v that has no predecessors;
    output v;
    delete v and all edges leading out of v from the network;
}

void topological_sort(int graph[][MAX_VERTICES], int n){
    int in_degree[MAX_VERTICES] = {0};
    int i, j, k;

    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
            if (graph[j][i] == 1){
                in_degree[i]++;
            }
        }
    }

    for (k=0; k<n; k++){
        int v = -1;
        for (i=0; i<n; i++){
            if (in_degree[i] == 0){
                v = i;
                break;
            }
        }
        if (v==-1){
            fprintf(stderr, "Network has a cycle.\n");
            exit(1);
        }

        printf("%d ", v);
        in_degree[v] = -1;

        for (j=0; j<n; j++){
            if (graph[v][j] == 1){
                in_degree[j]--;
            }
        }
    }
    printf("\n");
}