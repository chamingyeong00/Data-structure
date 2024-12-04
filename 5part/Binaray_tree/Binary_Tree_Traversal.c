typedef struct node *tree_pointer;
struct node{
    int data;
    struct node *left_child;
    struct nod *right_child;
};

void inorder(struct node *ptr){
    if (ptr){
        inorder(ptr->left_child);
        printf("%d", ptr->data);
        inorder(ptr->right_child);
    }
}

void preorder(struct nod *ptr){
    if (ptr){
        printf("%d", ptr->data);
        preorder(ptr->left_child);
        preorder(ptr->right_chile);
    }
}

void postorder(struct node *ptr){
    if (ptr){
        postorder(ptr->left_child);
        postorder(ptr->right_child);
        printf("%d", ptr->data);
    }
}