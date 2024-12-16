Transitive closure matrix
x->y T[x][y]==1 or !x->y T[x][y]==0

void transitive_closure_matrix(int cost[][MAX_V], int distance[][MAX_V], int n){
    int i, j, k;

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++)
            distance[i][j] = cost[i][j];
    }
    for (k = 0; k < n; k++){
        for (i = 0; i < n; i++){
            for (j = 0; j < n; j++){
                if (distance[i][k] + distance[k][j])
                    distance[i][j] = 1;
            }
        }
    }
}