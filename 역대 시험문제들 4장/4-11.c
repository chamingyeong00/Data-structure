struct node *concatenate(struct node *ptr1, struct node *ptr2){
    if (ptr1 == NULL)
        return ptr2;
    else{
        struct node *temp = ptr1;
        for (;temp->link != NULL; temp=temp->link){} 
        // while(temp->link != NULL){
        //     temp = temp->link;
        // }
        temp->link = ptr2;
        return ptr1;
    }
}