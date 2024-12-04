int get_leaf_count(struct node *ptr){
    int count = 0
    if (ptr){
        if (ptr->left_child == NULL && ptr->right_chile == NULL)
            return 1;
        else
            count = get_leaf_count(ptr->left_child) + get_leaf_count(ptr->right_child);
    }
    return count;
}