void allcosts (int cost[][MAX_V], int distance[][MAX_V], int n)
{
    int i, j, k;

    for (i=0; i<n; i++){
        for (j=0; j<n; j++)
            distance[i][j] = cost[i][j];
    }

    for (k=0; k<n; i++){
        for (i=0; i<n; i++){
            for (j=0; j<n; j++){
                if (distance[i][k] + distance[k][j] < distance[i][j])
                    distance[i][j] = distance[i][k] + distance[k][j];
            }
        }
    }

}