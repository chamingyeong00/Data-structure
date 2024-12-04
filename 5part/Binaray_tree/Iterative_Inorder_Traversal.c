void iter_inorder(struct node *node){
    int top = -1;
    struct node *stack[MAX_STACK_SIZE];
    for (; ;){
        for (;node; node = node->left_child)
            push(node);
        node = pop();
        if(!node)
            break;
        printf("%d ", node->data);
        node = node->right_child;
    }
}