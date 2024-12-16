void merge(int list[], int sorted[], int i, int m, int n)
{
    int j = m+1, k=i;

    while (i <= m && j <= n){
        if (list[i] <= list[j])
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }
    if (i > m){
        for (; j<=n; j++)
            sorted[k++] = list[j];
    }else{
        for (; i<=m; i++)
            sorted[k++] = list[i];
    }
}