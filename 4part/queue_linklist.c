typedef struct{
    int key;//
} element;

struct Queue{//
    element data;//
    struct Queue *link;
};

struct Queue *front, *rear; //

void add(element item)
{
    struct Queue temp = (struct Queue *)malloc(sizeof(struct Queue));
    if (temp == NULL)
    {
        fprintf(stderr, "The memory is full\n");
        exit(1);
    }
    temp->data = item;
    temp->link = NULL;
    if (front)
        rear->link = temp;
    else
        front = temp; 
    rear = temp;
}

element deleteq(){

    struct Queue temp = (struct Queue *)malloc(sizeof(struct Queue));
    element item;
    if (temp == NULL)
    {
        fprintf(stderr, "The memory is full\n");
        exit(1);
    }
    temp = front;
    item = temp->data;
    front = temp->link; //front
    free(temp);
    return item;
}