struct node{
    int data;
    struct node *rchild;
    struct node *lchild;
};

int tree_depth(struct node *ptr){
    int n1, n2;
    if (ptr == NULL)
        return 0;
    n1 = tree_depth(ptr->lchild);
    n2 = tree_depth(ptr->rchild);
    return (n1>n2) ? n1+1 : n2+1;
}