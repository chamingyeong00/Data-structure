#include <stdio.h>
#define SWAP(x, y, temp) {temp = x; x= y; y = temp;}

void adjust(int list[], int root, int n){
    int rootkey = list[root], child = 2*root;

    while (child <= n){
        if ((child < n) && (list[child] < list[child+1]))
            child++;
        if (rootkey > list[child])
            break;
        else{
            list[child/2] = list[child];
            child*=2;
        }
    }
    list[child/2] = rootkey;
}

void heapsort(int list[], int n){
    int i, j;
    int temp;

    for (i = n/2; i>0; i--)
        adjust(list, i, n);
    for (i = n-1; i>0; i--){
        SWAP(list[1], list[i+1], temp);
        adjust(list, 1, i);
    }
}