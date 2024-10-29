x->next->next = y->next->next;
y->next->next = tmp;

x->next = y->next;
y->next = tmp;