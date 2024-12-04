struct tbt{
    int data;
    short int left_thread; //true = thread  //false = child
    short int right_thread;
    struct tbt *lchild;
    struct tbt *rchild;
};

struct tbt *inpred(struct tbt *ptr){
    if (ptr->left_thread == 1)
        return ptr->lchild;
    struct tbt *temp = ptr->lchild;
    while (temp->right_thread == 0 && !temp){
        temp = temp->rchild;
    }
    return temp;
}