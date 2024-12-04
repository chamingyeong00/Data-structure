struct node {
    struct node *llink;
    int data;
    struct node *rlink;
};

void delete_left(struct node **head, struct node *ptr){
    struct node *del_node = ptr->llink; 
    if (del_node == *head) {
        *head = ptr;
        ptr->llink = NULL;
    }
    else{
        del_node->llink->rlink = ptr;
        ptr->llink = del_node->llink;
    }
    free(del_node);
}
