struct node *iterSearch(struct node *tree, int key){
    while (!tree){
        if (tree->data == key)
            return tree;
        if (tree->data > key)
            tree = tree->left_child;
        else
            tree = tree->right_child;
    }
    return NULL;
}