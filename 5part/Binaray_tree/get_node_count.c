int get_node_count(struct node *ptr){
    int count = 0;
    if(ptr){
        count = 1 + get_node_count(ptr->left_child) + get_node_count(ptr->right_child);
    }
    return count;
}