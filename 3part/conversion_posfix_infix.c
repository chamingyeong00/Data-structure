#define MAX_STACK_SIZE 100
#define MAX_EXPR_SIZE 100

typedef enum{
    lparen, rparen, plus, minus, times, 
    divide, mod, eos, operand
} precedence;

precedence stack[MAX_STACK_SIZE];
int isp[] = {0, 19, 12, 12, 13, 13, 13, 0};
int icp[] = {20, 19, 12, 12, 13, 13, 13, 0};

typedef struct{
        int key;
} element;
int top = -1;

expr[] //infix저장
void postifix(void){
    char symbol;
    precedence token;
    int n=0;

    push(eos);
    for (token = get_token(&symbol, &n); token != eos; token = get_token(&symbol, &n));//주소 위치 보내기
    {
        if (token == operand)
        {
            printf("%c", symbol); //피연산자는 printf
        }
        else if (token == rparen){
            while (stack[top] != lparen){ //token (x)
                print_token(pop());
            }
            pop();
        }
        else{
            while (isp[stack[top]] >= icp[token])
                print_token(pop());
            push(token);    
        }
        /*else if (isp[stack[top]] >= icp[token]){
            print_token(pop());
            push(token);
        }
        else{
            push(token);
        }*/
    }
    while ((token = pop()) != eos){
        print_token(token);
    }
    printf("\n");
    //for (token = get_token(&symbol, &n); token != eos; token = get_token(&symbol, &n))
    //    print_token(token);
}

precedence get_token(char *symbol, int *n){
    *symbol = expr[(*n)++];
}

print_token(int num)

int pop();

void push(int item);