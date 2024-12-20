struct node{
    int data;
    struct node *rchild;
    struct node *lchild;
};

struct node *modified_search(struct node *A, int key){
    for (struct node *ptr = A; ptr != NULL;){
        if (ptr->data == key)
            return NULL;
        if (key < ptr->data){
            if (ptr->lchild == NULL)
                return ptr;
            else
                ptr = ptr->lchild;
        }
        else{
            if (ptr->rchild == NULL)
                return ptr;
            else
                ptr = ptr->rchild;
        }
    }
    return NULL;
}