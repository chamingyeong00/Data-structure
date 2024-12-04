struct btnode{
    int data;
    struct btnode *lchild;
    struct btnode *rchild;
};

int count_node2(struct btnode *ptr){
    if (ptr == NULL)
        return 0;
    if (ptr->lchild != NULL && ptr->rchild != NULL)
        return 1 + count_node2(ptr->lchild) + count_node2(ptr->rchild);
    else
        return count_node2(ptr->lchild) + count_node2(ptr->rchild);
}