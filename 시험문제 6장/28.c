early(i) = earliest[k]
late(i) = latest[l] - duration of ai

earliest[j]
earliest[0] = 0
earliest[j] = max{earliest[i] + duration of <i, j>}
    for (모든) i (포함) {immediate predecessors of j}

    if(earliest[k] < earliest[j] + ptr->duration)
        ealiest[k] = earliest[j] + ptr->duration


struct node{
    int vertex;
    int dur; //엣지의 소요 시간 저장
    struct node *link;
};

struct hdnode{
    int count;
    struct node *link;
};
hdnode graph[MAX_VERTICES];

void calculateEarliestTime(hdnode graph[], int n, int earliest[])
{
    int i, j, k;
    struct node *ptr;

    for (i=0; i<n; i++){
        if (graph[i].count == 0)
            push(i);
        earliest[i] = 0;
    }

    for (i=0; i<n; i++){
        if (StackEmpty() == true)
            return;
        else{
            j = pop();
            for (ptr = graph[j].link; ptr != NULL; ptr = ptr->link){
                k = ptr->vertex;
                graph[k].count--;
                if (graph[k].count == 0)
                    push(k);
            }

            if (earliest[k] < earliest[j] + ptr->dur){
                earliest[k] = earliest[j] + ptr->dur;
            }

        }
    }
}