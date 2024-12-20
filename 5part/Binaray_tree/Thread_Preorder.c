struct thread_tree{
    short int   left_thread;        //true or false
    struct thread_tree *left_child; //left_thread = true: thread
                                    //left_thread = false: left child
    char    data;
    struct thread_tree *right_child;//right_thread에 따라 결정
    short int   right_thread;
};

struct thread_tree* presucc(struct thread_tree* ptr) {
    if (ptr->left_thread == 0){
        return ptr->left_child;
    }
    else if(ptr->right_thread == 1){
        return ptr->right_child;
    }
    else{
        struct thread_tree *temp = ptr->right_child;
        while(!temp && temp->right_thread == 1){
            temp = temp->right_child;
        }
        return temp;
    }
}