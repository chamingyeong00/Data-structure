tree_pointer copy(struct node *original){
    struct node *temp;
    if (original){
        temp = (struct node *)malloc(sizeof(struct node));
        temp->left_child = copy(original->left_child);
        temp->right_child = copy(original->right_chile);
        temp->data = original->data;
        return temp;
    }
    return NULL;
}

void swap_tree(struct node *original){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    if (!temp)
        return;
    temp = original->left_child;
    original->left_child = original->right_child;
    original->right_child = temp;

}