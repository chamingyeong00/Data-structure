struct tbt{
    int data;
    short int left_thread;
    short int right_thread;
    struct tbt *lchild;
    struct tbt *rchild;
};

struct tbt *inpred(struct tbt *ptr){
    struct tbt *temp = ptr->lchild;

    if (!ptr->left_thread){
        while(!temp->right_thread)
            temp = temp->rchild;
    }
    return temp;
}

void insert_left(struct tbt *parent, struct tbt *child){
    struct tnode *temp;

    child->lchild = parent->lchild;
    child->left_thread = parent->left_thread;

    child->rchild = parent;
    child->right_thread = 1;

    parent->lchild = child;
    parent->left_thread = 0;

    if(child->left_thread == 0){
        temp = inpred(child);
        temp->rchild = child;
    }
}