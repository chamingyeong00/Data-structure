struct node *search (struct node *root, int key){
    if (!root)
        return NULL;
    if (key == root->data)
        return key;
    if (root->data > key)
        return search(root->left_child, key);
    return search(root->right_child, key);
}