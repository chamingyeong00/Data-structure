struct thread_tree{
    short int   left_thread;        //true or false
    struct thread_tree *left_child; //left_thread = true: thread
                                    //left_thread = false: left child
    char    data;
    struct thread_tree *right_child;//right_thread에 따라 결정
    short int   right_thread;
};

struct thread_tree *postsucc(struct thread_tree *ptr){
    struct thread_tree *parent;

    parent = find_parent(ptr);

    if (parent->right_child == ptr){
        return parent;
    }
    else if (parent->right_thread == 1){
        return parent;
    }
    else{
        struct thread_tree *temp = ptr->right_child;
        while (temp->left_thread == 0){
            temp = temp->left_child;
        }
        return temp;
    }

}