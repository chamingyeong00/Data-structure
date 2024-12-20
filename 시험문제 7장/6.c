void merge(int list[], int sorted[], int i, int m, int n)
{
    int j = m+1; k=i, t;

    while(i<=m && j<=n){
        if (list[i] <= list[j])
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }
    if (i > m){
        for (t=j; t<=n; t++)
            sorted[k++] = list[t];
    }else{
        for (t=i; t<=n; t++)
            sorted[k++] = list[t];
    }
}