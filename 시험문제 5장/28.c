struct thread_tree{
    short int left_thread;
    struct thread_tree *left_child;

    char data;
    short int right_thread;
    struct thread_tree *right_child;
}
//	1.	주어진 정수 데이터를 이용해 이진 검색 트리(Binary Search Tree, BST)를 생성하기




//	2.	생성한 BST에 스레드(Thread)를 추가해 스레드 이진 검색 트리(Threaded Binary Search Tree, TBT)로 변환하기

struct thread_tree *insucc(struct thread_tree *ptr){
    struct thread_tree *temp = ptr->right_child;

    if (!ptr->right_thread)
        while(!temp->left_thread)
            temp = temp->left_child;
    return temp;
}

void tinorder (struct thread_tree *tree){
    struct thread_tree *temp = tree;
    for (;;){
        temp = insucc(temp);
        if (temp == tree)
            break;
        printf("%3c", temp->data);
    }
}