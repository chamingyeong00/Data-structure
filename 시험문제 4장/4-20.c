void DeleteNode(struct node **head, int  x){
    struct node *current = *head;
    struct node *temp;

    while(current != NULL){
        if(current->data == x){
            temp = current;
            if (temp == (*head)){
                (*head) = temp->rlink;
                (*head)->llink = NULL;
            }
            else{
                if (current->rlink != NULL)
                    current->rlink->llink = current->llink;
                    current->llink->rlink = current->rlink;
                else{
                    current->llink->rlink = NULL;
                }
            }
            free(temp);
        }
        current = current->llink;
    }
}