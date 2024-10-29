struct node{
    struct node *llink;
    int data;
    struct node *rlink;
};

void rinsert(struct node *node, struct node *newnode){
    newnode->llink = node;
    newnode->rlink = node->rlink;
    node->rlink->llink = newnode;
    node->rlink = newnode;
}

void linsert(struct node *node, struct node *newnode){
    newnode->rlink = node;
    newnode->llink = node->llink;
    node->llink->rlink = newnode;
    node->llink = newnode;
}

void chain(struct node *node, struct node *new_left, struct node *new_right) {
    if (node == NULL) {
    return;
    }

    if (node->llink == NULL){
        new_left->rlink = node;
        node->llink = new_left;
        new_left->llink = NULL;
    }else{
        node->llink->rlink = new_left;
        new_left->llink = node->llink;
        new_left->rlink = node;
        node->llink = new_left;
    }

   if (node->rlink == NULL){      
        node->rlink = new_right;
        new_right->llink = node;
        new_right->rlink = NULL;
    }
    else{
        node->rlink->llink = new_right;
        new_right->rlink = node->rlink;
        new_right->llink = node;
        node->rlink = new_right;
    }
}

void ddelete(struct node *deleted){
    deleted->rlink->llink = deleted->llink;
    deleted->llink->rlink = deleted->rlink;
    free(deleted);
}

void delete_neighbors(struct node *delete_node) {
    if (delete_node == NULL) {
        return;
    }

    struct node *left_node = delete_node->llink;
    struct node *right_node = delete_node->rlink;

    if (left_node != NULL && left_node != delete_node) {
        left_node->llink->rlink = delete_node; 
        delete_node->llink = left_node->llink; 
        free(left_node);
    }

    if (right_node != NULL && right_node != delete_node) {
        right_node->rlink->llink = delete_node;
        delete_node->rlink = right_node->rlink;
        free(right_node);
    }
}

void chain(struct node *node, struct node *delete_left, struct node *delete_right) {
    if (node == NULL) {
    return;
    }

    if (delete_left->llink == NULL){
        delete_left->rlink->llink = NULL;
    }else{
        delete_left->llink->rlink = delete_left->rlink;
        delete_left->rlink->llink = delete_left->llink;
    }
    free(delete_left);
   if (delete_right->rlink == NULL){  
        delete_right->llink->rlink = NULL;
    }
    else{
        delete_right->llink->rlink = delete_right->rlink;
        delete_right->rlink->llink = delete_right->llink;
    }
    free(delete_right);
}