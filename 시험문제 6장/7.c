//방향성 그래프 cost[n][n]
//이행적 폐쇄 행령 A+ distance[n][n]

Transitive Closure
Transitive Closure Matrix : A+
A+[i][j] = 1 if there is a path of length > 0 from i to j
Otherwise, A+[i][j] = 0

Reflexive Transitive Closure Matrix : A*
A*[i][j] = 1 if there is a path of length >= 0 from i to j
Otherwise, A*[i][j] = 0

allocots() 
distance[i][j] = distance[i][j] || distance[i][k] && distance[k][j]

#define n 10

void reflexive_transitive_closure(cost[][n], distance[][n]){
    int i, j, k;

    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
            if (i == j){
                distance[i][j] = 1;
            }
            else{
                distance[i][j] = cost[i][j];
            }
        }
    }

    for (k=0; k<n; k++){
        for (i=0; i<n; i++){
            for (j=0; j<n; j++){
                if (distance[i][k] + distance[k][j] < distance[i][j])
                    distance[i][j] = distance[i][j] || distance[i][k] + distance[k][j];
            }
        }
    }
}