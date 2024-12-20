void quicksort(int list[], int left, int right){
    int pivot, i, j;
    int temp;
    if (left < right){
        i = left;
        j = right+1;
        pivot = list[left];
        do{
            i++
        }while(list[i] < pivot);

        do{
            j--;
        }while(list[j] > pivot);
        if (i < j)
            SWAP(list[i], list[j], temp);
    }while(i < j);
    SWAP(list[left], list[j], temp);
    quicksort(list, left, j-1);
    quicksort(list, j+1, right);
}