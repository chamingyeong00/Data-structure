#define MAX_ELEMENTS 200 //maximum heap size+1
#define HEAP_FULL(n)    (n == MAX_ELEMENTS-1)
#define HEAP_EMPTY(n)   (!n)
typedef struct{
    int key;
    /*other fields*/
} element;
element heap[MAX_ELEMENTS];
int n=0;

element delete_max_heap (int *n){
    int parent, child;
    element item, temp;

    if (HEAP_EMPTY (*n)){
        fprintf(stderr, "The heap is empty\n");
        exit(1);
    }

    item = heap[1];
    temp = heap[(*n)--];
    parent = 1, child = 2;
    while(child < (*n)){
        if ((child < *n) && (heap[child].key < heap[child+1].key))
            child++;
        if (temp.key <= heap[child].key)
            break;
        heap[parent] = heap[child];
        parent = child;
        child *= 2;
    }
    heap[parent] = temp;
    return item;
}