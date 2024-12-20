struct node{
    int data;
    struct node *rchild;
    struct node *lchild;
};

struct node *FindMax(struct node *ptr){
    if (ptr == NULL)
        return NULL;
    else if (ptr->rchild == NULL)
        return ptr;
    else
        return FindMax(ptr->rchild);
}