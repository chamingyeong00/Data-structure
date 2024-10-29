stduct node *invert(struct node *head){
    struct node *p, *q, *r;
    p = head;
    q = NULL;
    while (p!= NULL){
        r = p->link;
        p->link = q;
        q = p;
        p = r;
    }
    return q
}

stduct node *invertR(struct node *head){
    struct node *new_head;
    if (head == NULL)   return NULL;
    else if (head->link == NULL)    return head;
    else{
        new_head = invertR(head->link)
        head->link->link = head;
        head->link = NULL:
    }
    return new_head;
}



