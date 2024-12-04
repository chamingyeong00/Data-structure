struct btnode{
    int data;
    struct btnode *lchild;
    struct btnode *rchild;
};

void ancestor(struct btnode *root, int data){
    if (root == NULL)
        return ;
    if (root->data == data)
        return data;
    else if (root->data < data){
        printf("%d", root->data);
        ancestor(root->lchild, data);
    }
    else{
        printf("%d", root->data);
        ancestor(root->rchild, data);
    }
}