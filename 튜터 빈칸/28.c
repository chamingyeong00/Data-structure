struct node{
    int vertex;
    int dur;
    struct node *link;
};
struct hdnode{
    int count;
    struct node *link;
};

void calculateEarliestTime(hdnode graph[], int n, int earliest[]){
    int i, j, k;
    struct node *ptr;

    for (i=0; i<n; i++){
        if (graph[i].count == 0)
            push(i);
        earlist[i] = 0;
    }

    for (i=0; i<n; i++){
        if (StackEmpty() == true)
            return;
        else{
            j = pop();
            for(ptr = graph[j].link; ptr != NULL; ptr = ptr->link){
                k = ptr->vertex;
                graph[k].count--;
                if (graph[k].count == 0)
                    push(k);

                if (earliest[k] < earliest[j] + ptr->dur)
                    earliest[k] = earliest[j] + ptr->dur;
            }
        }
    }

}