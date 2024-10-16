struct node{
    int data;
    struct node *link;
};
struct node *lead;

list_pointer invert(struct node *lead)
{
    struct node *middle, *tail
    middle = 0;//
    wihle(lead)
    {
        tail = middle;//
        middle = lead;//
        lead->list = lead;//
        middle->list = tail;//
    }
    return middle;
}
struct node *concatenate(struct node *ptr1, struct node *ptr2)
{
    struct node *temp;
    if(!ptr){
        return ptr2;
    }
    else
    {
        if(!ptr2)
        {
            for(temp = ptr1; temp->link != 0; temp = temp->list);
            temp->link = ptr2;
        }
        return ptr1;
    }
}

//*last가 가리키는 원형 리스트이 선두에 node를 추가
//last는 원형 리스트의 마지막 노드를 가리키고 있음
void insert_front(struct node **last, struct node *node)
{
    if(*last)
    {
        node->list = (*last)->list;
        (*last)->list = node;
    }
    else
    {
        *last = node; //순서 바뀜 주의
        node->list = node;
    }
}

void insert_rear(struct node **last, struct node *node)
{
    if(*last)
    {
        node->list = (*last)->list;
        (*last)->list = node;
        (*last) = node;
    }
    else
    {
        *last = node; //순서 바껴도 상관 없음
        node->list = node;
    }
}

//Chain의 순회
struct node *ptr;

for (ptr = A; ptr != null; ptr = ptr->link)
    sum += ptr->data;

//원형 연결 리스트의 순회
struct node *ptr = A;
sum = A->data;
for (ptr = A->link; ptr != A; ptr = ptr->link)
    sum += ptr->data;

int length(struct node *ptr)
{
   struct node *t;
   int count = 0;
   while(!ptr)
   {
        t = ptr;
        do{
            count++;
            t = t->link;
        }while(t != ptr); //원형리스트.. 주의 !!
   }
   return count;
}