struct node *merge(struct node *list1, struct node *list2) {
    struct node *head = NULL;
    struct node *tail = NULL;

    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    if (list1 != NULL) {
        head = list1;
        list1 = list1->next;
    }
    tail = head;

    while (list1 != NULL && list2 != NULL) {
        tail->next = list2;
        tail = list2;
        list2 = list2->next;

        if (list1 != NULL) {
            tail->next = list1;
            tail = list1;
            list1 = list1->next;
        }
    }

    if (list1 != NULL) {
        tail->next = list1;
    } else if (list2 != NULL) {
        tail->next = list2;
    }

    return head;
}
