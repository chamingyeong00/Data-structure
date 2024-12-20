struct btnode{
    int data;
    struct btnode *lchild;
    struct btnode *rchild;
};

struct btnode *search(struct btnode *ptr, int key){
    if (!root)
        return NULL;
    if (key == root->data)
        return root;
    if (key < root->data)
        return search(root->lchild, key);
    return search(root->rchild, key);
}