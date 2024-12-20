struct btnode{
    int data;
    struct btnode *lchild;
    struct btnode *rchild;
};

struct btnode *swap(struct btnode *original){
    struct btnode *temp;
    if (original){
        temp = (struct btnode *)malloc(sizeof(struct btnode));
        temp->lchild = swap(original->rchild);
        temp->rchild = swap(original->lchild);
        temp->data = original->data;
        return temp;
    }
    return NULL;
}