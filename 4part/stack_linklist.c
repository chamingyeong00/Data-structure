typedef struct{
    int key
} element;

struct stack{
    element data;
    struct stack *link;
};

struct stack *top;
top = NULL;

void push(element item)
{
    struct stack *temp= (struct stack*)malloc(sizeof(struct stack));
    if(temp == NULL)
    {
        fprintf(stderr, "The memory is full\n");
        exit(1);
    }
    temp->data = item;
    temp->link = top; //stack이기때문에
    top = temp;
}

element pop()
{
    struct stack *temp= top;
    element item;//
    if(temp == NULL)
    {
        fprintf(stderr, "The memory is full\n");
        exit(1);
    }
    item = temp->data
    top = temp->link;//temp->link
    free(temp);
    return item;
}

if (!(*head))
	return;
else{
	for(struct node *temp = *head; temp->rlink->rlink != ptr; temp=temp->rlink){
        struct node delete = temp->llink;
        temp-llink = per:
        ptr-orlink = temp:
        free)delete)
    }
}
