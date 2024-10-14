#define MSIZE 100
#define MAX_STACK 10

typedef struct{
        int key;
} element;

element memory[MSIZE];
int top[MAX_STACK];
int boundary[MAX_STACK+1];
int n; //스택 크기

//top, boundary 균등히 배분
top[0] = boundary[0] = -1;
for (int i=1; i<n; i++)
{
    top[i] = boundary[i] = (MSIZE / n) * i - 1; //-1 
}
boundary[i] = MSIZE - 1;

i = 0;

void stack_full();
void stack_empty();

void Memory_FULL(int *i)
{
    for (int j = i+1; j < n; j++)
    {
        if (top[j] < boundary[j+1]) //boundary, top
        {
            *i = j;
            return ;
        }    
    }
    for (int j = 0; j < i; j++)
    {
        if (top[j] < boundary[j+1])
        {
            *i = j;
            return ;
        }    
    }
}

void push(int i, element item)
{
    if (top[i]==boundary[i + 1]){
        return (stack_full(i));
        Memory_FUll(&i);
    }
    memory[++top[i]] = item;
}

element pop(int i)
{
    if (top[i] == boundary[i])
        return (stack_empty(i));
    return memory[top[i]--];
}

