리스트 삭제

struct poly{
    int expon;
    float coef;
    struct poly *link;//
}
struct poly **avail;

void erase(struct poly **ptr)
{
    struct poly *temp;
    if (!temp)
    {
        frpintf(stderr, "the memory is full\n");
        exit(1);
    }
    if (!*ptr)
    {
        temp = *ptr;
        (*ptr) = (*ptr)->list;
        free(temp);
    }
}

int IS_FULL(node)
{
    struct poly *temp;
    temp = (struct poly*)malloc(sizeof(struct poly));
    if (!temp)
        return 1;
    return 0;
}

struct poly *get_node(void)
{
    struct poly* node;
    if (!node)
    {
        frpintf(stderr, "the memory is full\n");
        exit(1);
    }
    if (!avail)
    {
        node = (struct poly*)malloc(sizeof(struct poly));
        if (IS_FULL(node))
        {
            frpintf(stderr, "the memory is full\n");
            exit(1);
        }
    }
    else{
        node = avail;
        avail = avail->list;//
    }
    return (node);
}

void ret_node(struct poly *ptr)
{
    ptr->list = avail;
    avail = ptr;
}