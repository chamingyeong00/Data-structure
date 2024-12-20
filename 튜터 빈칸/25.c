struct btnode{
    int data;
    struct btnode *rchild;
    struct btnode *lchild;
};

int count_node2(struct btnode *ptr){
    if (ptr == NULL)
        return 0;
    if(ptr->rchild && ptr->lchild)
        return 1 + count_node2(ptr->lchild) + count_node2(ptr->rchild);
    else
        return count_node2(ptr->lchild) + count_node2(ptr->rchild);
}