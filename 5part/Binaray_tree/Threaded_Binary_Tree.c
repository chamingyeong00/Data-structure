struct thread_tree{
    short int   left_thread;        //true or false
    struct thread_tree *left_child; //left_thread = true: thread
                                    //left_thread = false: left child
    char    data;
    struct thread_tree *right_child;//right_thread에 따라 결정
    short int   right_thread;
};

//한 노드에의 inorder succesoor 발견
struct thread_tree *insucc(struct thread_tree *ptr){
    struct thread_tree *temp = ptr->right_child;
    
    if(!ptr->right_thread){
        while(!temp->left_thread){
            temp = temp->left_child;
        }
    }
    return temp;
}

//Threaded Binary Tree를 Inorder Traversal
void tinorder (struct thread_tree *tree){
    struct thread_tree *temp = tree;

    for(; ;){
        temp = insucc(temp);
        if (temp == tree)
            break;
        printf("%3c", temp->data);
    }
}

//Threaded Binary Tree에서 parent의 오른쪽에 노드 추가
void insert_right(struct thread_tree *parent, struct thread_tree *child){
    struct thread_tree *temp;

    child->right_child = parent->right_child;
    child->right_thread = parent->right_thread;

    child->left_child = parent;
    child->left_child = TRUE;

    parent->right_child = child;
    parent->right_thread = FALSE;

    if(!child->right_thread){
        temp = insucc(child);
        temp->left_child = child;
    }
}

struct tnode{
    int data;
    struct tnode *lchild, *rchild;
    short lthread, rthread;
};

struct tnode *inpred(struct tnode *ptr){
    struct tnode *temp = ptr->lchild;
    if(ptr->lthread == 0){
        while(!temp->rthread)
            temp = temp->rchild;
    }
    return temp;
}

void insert_left(struct tnode *parent, struct tnode *child){
    struct tnode *temp;

    child->lchild = parent->lchild;
    child->lthread = parent->lthread;

    child->rchild = parent;
    child->rthread = 1;

    parent->lchild = child;
    parent->lthread = 0;

    if(child->lthread == 0)
    {
        temp = inpred(child);
        temp->rchild = parent;
    }
}
