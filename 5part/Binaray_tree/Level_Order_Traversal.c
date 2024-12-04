void level_order(struct node *ptr){
    int front = 0, rear = 0;
    struct node *queue[MAX_QUEUE_SIZE];
    if (!ptr)
        return;
    addq(ptr);
    for(; ;){
        ptr = deleteq();
        if(!ptr)
            break;
        printf("%d", ptr->data);
        if(ptr->left_child)
            addq(ptr->left_child);
        if(ptr->right_child)
            addq(ptr->right_child);
    }
}