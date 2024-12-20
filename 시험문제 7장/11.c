void merge(int A[], int B[], int x, int y, int z){
    int j = y+1, k = x;

    while( x<=y && j<=z){
        if (A[x] <= A[j])
            B[k++] = A[x++];
        else
            B[k++] = A[j++];
    }
    if (x > y){
        for (;j <= z; j++)
            B[k++] = A[j];
    }else{
        for (;x <= y; x++)
            B[k++] = A[x];
    }
}

void merge_pass(int list[], int sorted[], int n, int length){
    int i, j;
    for(i=0; i+2*length-1 < n; i+= 2*length)
        merge(list, sorted, i, i+length-1, i+2*length-1);

    if (i+length < n)
        merge(list, sorted, i, i+length-1, n-1);
    else{
        for (j=i; j<n; j++)
            sorted[j] = list[j];
    }
}

void merge_sort(int list[], int n){
    int length = 1;
    int extra[MAX_SIZE];

    while(length<n){
        merge_pass(list, extra, n, length);
        length *= 2;
        merge_pass(extra, list, n, length);
        length *= 2;
    }
}