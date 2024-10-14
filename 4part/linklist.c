#include <stdio.h>
#include <stdlib.h>
#define NULL ((void *)0)

struct node{
    int data;
    struct node *link;
};
struct node *ptr = NULL, *A, *B;

int main(void)
{
    ptr = (struct node *)malloc(sizeof(struct node));
    A = (struct node *)malloc(sizeof(struct node));
    A->data = 10;
    B = (struct node *)malloc(sizeof(struct node));
    B->data = 20;
    A->link = B;
    B->link = NULL;

    //리스트 출력
    struct node *ptr;
    for (ptr = A; ptr != NULL; ptr = ptr->link) //ptr != NULL
    {
        printf("%d", ptr->data);
    }
}

void insert(struct node **start, struct node *before){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp==NULL)
    {
        fprintf(stderr, "The memory is full\n");
        exit(1);
    }
    temp->data = 50;
    if (*start != NULL)
    {
        temp->list = before->list;
        before->list = temp;
    }
    else
    {
        temp->list = NULL;
        *start = temp;
    }
}

void delete(struct node **start, struct node *before, struct node *A)
{
    if (before == NULL)
    {
        *start = *start->link; //
    }
    else
    {
        before->link = A->link;
    }
    free(A);//
}

//노드 추가 17 29 36 (45) 52
struct node *ptr, *temp; //*start

temp = (struct node*)malloc(sizeof(struct node));
temp->data = 50;
for (ptr = start; ptr->data != 36; ptr = ptr->link)
{
    temp->link = ptr->link;
    ptr->link = temp;
}

//노드 삭제 17 29 (36) 52
struct node *ptr, *target;
for (ptr = start; ptr->link->data != 36; ptr = ptr->link)
{
    target = ptr->link;
    ptr->link = target->link;
}