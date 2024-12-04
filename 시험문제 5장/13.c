struct node{
    int data;
    struct node *lchild;
    struct node *rchild;
};

int count(struct node *ptr){
    if(ptr == NULL)
        return 0;
    else    
        return 1 + count(ptr->lchild) + count(ptr->rchild);
}