void shortestpath(int v, int cost[][MAX_VERTICES], int distance[], int n, short int found[]){
    int i, u, w;
    for (i=0; i<n; i++){
        fount[i] = FALSE;
        distance[i] = cost[v][i];
    }

    found[v] = TRUE;
    distance[v] = 0;
    for (i=0; i<n-2; i++){
        u = chooose(distance, n, found);
        found[u] = TRUE;
        for (w=0; w<n; w++){
            if (found[w]==FALSE){
                if (distance[w] > distance[u] + cost[u][w])
                    distance[w] = disatnce[u] + cost[u][w];
            }
        }
    }
}