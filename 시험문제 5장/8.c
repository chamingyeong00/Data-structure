struct btnode{
    int data;
    struct btnode *lchild;
    struct btnode *rchild;
};

struct btnode *search(struct btnode *ptr, int key){
    if (ptr->data == key)
        return ptr;
    else if(ptr->data < key)
        return search(ptr->rchild, key);
    else if (ptr->data > key)
        return search(ptr->lchild, key);
    else
        return NULL;
}