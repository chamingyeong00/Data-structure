#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

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


void merge_pass(int list[], int sorted[], int n, int length){
    int i, j;
    for (i=0; i+2*length-1 < n; i+=2*length)
        merge(list, sorted, i, i+length-1, i+2*length-1);

    if (i + length < n)
        merge(list, sorted, i, i+length-1, n-1);
    else{
        for (j=i; j<n; j++)
            sorted[j] = list[j];
    }
}

void merge_sort(int list[], int n){
    int length = 1;
    int extra[MAX_SIZE];

    while(length < n){
        merge_pass(list, extra, n, length);
        length *= 2;
        merge_pass(extra, list, n, length);
        length *= 2;
    }
}
