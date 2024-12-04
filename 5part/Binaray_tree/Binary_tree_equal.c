int equal(struct node *first, struct node *second){
    return ((!first && !second) && 
    (first && second && (first->data == second->data) && 
    equal(first->left_child, second->left_child) && 
    equal(first->right_child, second->right child)));
}