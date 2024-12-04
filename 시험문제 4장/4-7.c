void swap(struct node *s, struct node *t){
    for(;s->next != t; s = s->next){}
    s->next = t->next;
    t->next = t->next->next;
    s->next->next = t;
}
