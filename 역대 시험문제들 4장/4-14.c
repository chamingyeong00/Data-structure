struct node{
    struct node *llink;
    int data;
    struct node *rlink;
};

void insert_right(struct node *A, int data){
    struct node *temp;
    temp->data = data;
    
    if (A->rlink == NULL){
        A->rlink = temp;    
        temp->llink = A;
        temp->rlink = NULL;
    }
    else{
        temp->rlink = A->rlink;
        A->rlink->llink = temp;
        temp->llink = A;
        A->rlink = temp;
    }
}