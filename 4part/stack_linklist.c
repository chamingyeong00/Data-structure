typedef struct{
    int key
} element;

struct stack{
    element data;
    struct stack *link;
};

struct stack *top;
top = NULL;

void push(element item)
{
    
}