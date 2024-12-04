struct node{
    int data;
    struct node *next;
};
struct node *top = NULL;

void add(int value){
    struct node *temp;
    temp->data = value;
    temp->next = NULL:
    if (top == NULL)
        top = temp;
    else{
        temp->next = top;//
        top = temp;//
    }
}