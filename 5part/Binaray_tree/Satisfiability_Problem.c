typedef enum {not, and, or, true, false} logical;
struct node{
    struct node *left_child;
    struct node *right_child;
    logical data;
    short int value;
}

for (all 2^n possible combinations){
    generate the next combination;
    replace the variables by their vaules;
    evaluate root by traversing it in postorder;
    if (root->value){
        printf(<combiination>);
        return;
    }
}

void post_order_eval(struct node *node){
    if (node){
        post_order_eval(node->left_child);
        post_order_eval(node->right_child);
        switch(node->data){
            case not:
                node->value = !node->right_child->value;
                break;
            case and:
                node->value = node->right_child->value && node->left_child->value;
                break;
            case or:
                node->value = node->right_child->value || node->left_child->value;
                break;
            case true:
                node->value = TRUE;
                break;
            case false:
                node->value = FALSE;
                break;
        }
    }
}