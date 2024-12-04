int find (int i){
    for (; parent[i] >= 0; i = parent[i]);
    return i;
}

void union(int i, int j){
    pi = find(i);
    pj = find(j);
    parent[pi] = pj;
}

void weightedUnion(int i, int j){
    int temp = parent[i] + parent[j];

    if (parent[i] > parent[j]){
        parent[i] = j;
        parent[j] = temp;
    }
    else{
        parent[j] = i;
        parent[i] = temp;
    }
}

int collapsingFind(int i){
    int root, node, next;

    for (root = i; parent[root] >= 0 ;root = parent[root])

    for (node = i; node != root && parent[node] != root ; node = next){
        next = parent[node];
        parent[node]= root;
    }
    return root;
}