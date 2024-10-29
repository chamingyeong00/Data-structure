
void insert_left(struct node **head, struct node *A, struct node *ptr){
    if (A == (*head)){
        ptr->rlink = A;
        A->llink = ptr;
        (*head) = ptr;
    }else{
        ptr->llink = A->llink;
        A->llink->rlink = ptr;
        ptr->rlink = A;
        A->llink = ptr;
    }
}
