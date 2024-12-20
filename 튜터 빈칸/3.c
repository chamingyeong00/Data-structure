typedef struct node *tree_ptr;
struct node{
    int data;
    tree_ptr left_child;
    tree_ptr right_child;
};

int equal(tree_ptr first, tree_ptr second){
    return ((!first && !second) || (first && second && (first->data == second->data) &&
    (equal(first->left_child, second->left_child)) && 
    (equal(first->right_child, second->right_child))))
}