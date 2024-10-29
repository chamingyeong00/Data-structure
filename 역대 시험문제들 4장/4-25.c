void add_Q(struct node **ptr, int x){
    struct node *new_node;
    new_node->data = x;
    if (*ptr == NULL){
        new_node->link = new_node;
        (*ptr) = new_node;
    }
    else{
        new_node->link = (*ptr)->link;
        (*ptr)->link = new_node;
        (*ptr) = new_node;
    }
}

int delete_Q(struct node **ptr){
    struct node *front = (*ptr)->link;
    int data = front->data;

    if(*ptr == NULL)
        return -1;
    else{
        (*ptr)->link = front->link;
        free(front);
    }
    return data;
}