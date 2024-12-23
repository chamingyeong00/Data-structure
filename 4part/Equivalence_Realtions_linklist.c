#include <stdio.h>
#include <alloc.h>
#define MAX_SIZE 24
#define IS_FULL(ptr) (!(ptr))
#define FALSE 0
#define TRUE 1

struct node{
    int data;
    struct node *link;
};

void main(void){
    short int out[MAX_SIZE];
    struct node *seq[MAX_SIZE], *x, *y, *top;
    int i, j, n;
    printf("Enter the size (<= %d) ", MAX_SIZE);
    scanf("%d", &n);

    for (int i=0; i<n; i++){
        out[i] = TRUE;
        seq[i] = NULL:
    }

    printf("Enter a pair of numbers(-1 -1 to quit): ");
    scanf("%d%d", &i, &j);
    while(i>=0){
        x = (struct node *)malloc(sizeof(struct node));
        x->data = j; x->link=seq[i]; seq[i] = x;

        x = (struct node *)malloc(sizeof(struct node));
        x->data = i; x->link=seq[j]; seq[j] = x;
        printf("Enter a pair of numbers(-1 -1 to quit): ");
        scanf("%d%d", &i, &j);
    }

    for (i=0; i<n; i++){
        if (!out[i])
            continue;
        printf("\n New class: %5d", i);
        out[i] = FALSE;
        x = seq[i], top = NULL;
        for (;;){
            while(x){
                j = x->data;
                if (out[j]){
                    printf("%5d", j);
                    out[j] = FALSE;
                    y = x->link; x->link = top; top = x; x = y;;
                }
                else
                    x = x->link;
            }
            if (!top)
                break;
            x = seq[top->data]; top = top->link;
        }
    }


}

