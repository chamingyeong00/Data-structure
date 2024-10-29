void crease(struct node **ptr){
    struct node *temp;
    temp = (*ptr)->next;
    (*ptr->next) = avail;
    avail = temp;
    *ptr = NULL;
} 