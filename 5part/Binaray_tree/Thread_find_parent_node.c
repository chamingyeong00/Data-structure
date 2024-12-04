struct thread_tree *find_parent(struct thread_tree *ptr) {
    struct thread_tree *x = ptr->left_child;

    if (ptr->left_thread == 1) {
        if (x->right_child == ptr) {
            return x;
        } else {
            struct thread_tree *temp = x->right_child;
            while (temp->left_child != ptr) {
                temp = temp->left_child;
            }
            return temp;
        }
    }

    else {
        while (x->right_child != ptr) {
            x = x->right_child;
        }
        return x;
    }
}