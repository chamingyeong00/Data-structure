struct poly{
    int expon;
    float coef;
    struct poly *link;//
}
struct poly *a, *b, *d;

int compare(float a, float b){
    if (a > b)
        return 1;
    else if (a < b)
        return -1;
    return 0;
}


struct poly *padd(struct poly *a, struct poly *b){
    struct poly *front, *rear, *temp;
    float sum;
    temp = (struct poly*)malloc(sizeof(struct poly));
    if (!temp)
    {
        frpintf(stderr, "the memory is full\n");
        exit(1);
    }
    front = rear;
    while(a != 0 && b != 0)/
    {
        swtich (compare(a->expon, b->expon)){
            case -1:
                attach(b->coef, b->expon, &rear);
                b = b->lisk;
                break;
            case 0:
                sum = a->ceof + b->coef;
                if (sum)//
                    attach(sum, a->coef, &rear);
                a = a->lisk;
                b = b->lisk;
                break;
            case 1:
                attach(a->coef, a->expon, &rear);
                a = a->lisk;
                break;
        }
    }
    for(; a != 0 ;a=a->list)
        attach(a->ceof, a->expon, &rear);
    for(; b != 0 ;b=b->list)
        attach(b->ceof, b->expon, &rear);
    rear->link = 0;
    temp = front; 
    front = front->list; 
    free(temp);
    return front;
}

void attach(float coefficient, int exponent, struct poly **rear){
    struct poly *temp;
    temp = (struct poly*)malloc(sizeof(struct poly));
    if (!temp)
    {
        frpintf(stderr, "the memory is full\n");
        exit(1);
    }
    temp->coef = coefficient;
    temp->expon = exponent;
    (*rear)->link = temp;//
    rear = temp;//
    //temp->link = 0;
}
