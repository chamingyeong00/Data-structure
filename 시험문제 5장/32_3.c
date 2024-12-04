struct tnode{
    int data;
    struct tnode *lchild, rchild;
    short ltrhead, rcthread;
};

struct tnode *inpred(struct tnode *ptr){
    struct tnode *temp = ptr->lchild;
    if (ptr->lthread == 0){
        while (!temp->rthead)
            temp = temp->rchild;
    }
    return temp;
}

void insert_left(struct tnode *parent, struct tnode *child){
    struct tnode *temp;
    child->lchild = parent->lchild;
    child->lthread = parent->lthread;
    child->rchild = parent;
    child->rthead = 1;
    parent->lchild = child;
    parent->lthread = 0;
    if (child->ltrhead == 0){
        temp = inpred(child);
        child->rchild = temp;
    }
}