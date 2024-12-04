struct btnode{
    int data;
    struct btnode *lchild;
    struct btnode *rchild;
};

int count_node1(struct btnode *ptr){
    if (ptr == NULL)
        return 0;
    if ((ptr->lchild != NULL && ptr->rchild == NULL) || (ptr->lchild == NULL && ptr->rchild != NULL))
        return 1 + count_node1(ptr->lchild) + count_node1(ptr->rchild);
    else
        return count_node1(ptr->lchild) + count_node1(ptr->rchild);
}