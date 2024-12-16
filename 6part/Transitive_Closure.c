void allcosts(int cost[][MAX_V], int distance[][MAX_V], int n){
    int i, j, k;

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++)
            distance[i][j] = cost[i][j];
    }
    for (k = 0; k < n; k++){
        for (i = 0; i < n; i++){
            for (j = 0; j < n; j++){
                if (distance[i][k] + distance[k][j] < distance[i][j])
                    distance[i][j] = distance[i][k] + distance[k][j];
            }
        }
    }
}

//Transitive Closure
Transitive Closure Matrix : A+
A+[i][j] = 1 if there is a path of length > 0 from i to j
Otherwise, A+[i][j] = 0

Reflexive Transitive Closure Matrix : A*
A*[i][j] = 1 if there is a path of length >= 0 from i to j
Otherwise, A*[i][j] = 0;

modified allcosts
distance[i][j] = distance[i][j] || distance[i][k] && distance[k][j]

