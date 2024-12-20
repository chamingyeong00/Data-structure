struct tnode{
    int data;
    short int lthread;
    short int rthread;
    struct tnode *lchild;
    struct tnode *rchild;
};

struct tnode *inpred(struct tnode *ptr){
    struct tnode *temp = ptr->lchild;
    if (ptr->lthread == 0){
        while (temp->rthread == 0)
            temp = temp->rchild;
    }
    return temp;
}

void insert_left(sturct tnode *parent, sturct tnode *child){
    struct tnode *temp;

    child->lchild = parent->lchild;
    child->lthread = parnet->lthread;

    child->rchild = parent;
    child->rthread = 1;
    
    parent->lchild = child;
    parent->lthread = 0;
    if (child->lthread == 0){
        temp = inpred(child);
        tmep->rchild = child;
    }
}

