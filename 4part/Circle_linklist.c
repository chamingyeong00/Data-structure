struct poly{
    int expon;
    float coef;
    struct poly *link;//
}
struct poly *avail, *ptr;

int compare(float a, float b){
    if (a > b)
        return 1;
    else if (a < b)
        return -1;
    return 0;
}


void crease(struct poly **ptr)
{
    struct poly *temp;
    if (*ptr)
    {
        temp = (*ptr)->link;
        (*ptr)->link = avail;
        avail = temp;
        *ptr = 0;
    }
    //temp = (struct poly*)malloc(sizeof(struct poly));
    // if (!temp)
    // {
    //     frpintf(stderr, "the memory is full\n");
    //     exit(1);
    // }
}

struct poly *cpadd(struct poly *a, struct poly *b) //원형리스트인지 잘 확인하기
{
    struct poly *starta, *d, *lastd;
    float sum;
    int sum, done = FALSE;
    starta = a;
    a = a->list;
    b = b->list;
    d = get_nod();
    d->expon = -1;//
    lastd = d;
    do{
        swtich (compare(a->expon, b->expon)){
            case -1:
                attach(b->coef, b->expon, &lastd);
                b = b->lisk;
                break;
            case 0:
                if (starta == a)
                    done = TRUE;
                else{
                    sum = a->ceof + b->coef;
                    attach(sum, a->coef, &lastd);
                    a = a->lisk;
                    b = b->lisk;
                }
                break;
            case 1:
                attach(a->coef, a->expon, &lastd);
                a = a->lisk;
                break;
        }
    }while(!done)
    lastd->list = d;//원형리스트
    return d;
}