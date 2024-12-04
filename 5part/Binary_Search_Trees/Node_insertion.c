struct node *modified_search(struct node *root, int key){

    for (struct node *ptr = root; ptr != NULL; ){
        if (ptr->data == key)
            return NULL:
        if (ptr->data > key){
            if (ptr->left_child == NULL)
                return ptr;
            else
                ptr = ptr->left_child;
        }
        else{
            if (ptr->right_child == NULL)
                return ptr;
            else
                ptr = ptr->right_child;
        }
    }
    return NULL
}

void insert_node(struct node **root, int num){
    struct node *ptr, parent = modified_search(*root, num);

    if (parent || !(*root)){
        ptr = (struct node *)malloc(sizeof(struct node));
        ptr->data = num;
        ptr->left_child = ptr->right_child = NULL;

        if (*root){
            if (parent->data > num){
                parent->left_child = ptr;
            }
            else{
                parent->right_child = ptr;
            }
        }
        else{
            (*root) = ptr;
        }
    }
    return NULL;
}