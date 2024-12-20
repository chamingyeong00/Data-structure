struct tbt{
    int data;
    short int left_thread;
    short int right_thread;
    struct tbt *lchild;
    struct tbt *rchild;
};

struct tbt *inpred(struct tbt *ptr){
    struct *temp = ptr->lchild;
    if (ptr->left_thread == 0){
        while(!temp->right_thread)
            temp = temp->rchild;
    }
    return temp;
}