#define MAX_STACK_SIZE 100
#define MAX_EXPR_SIZE 100
typedef enum{
    lparen, rparen, plus, minus, times, 
    divide, mod, eos, operand
} precedence;

int stack[MAX_STACK_SIZE];
int expr[MAX_EXPR_SIZE];

int eval(void){
    precedence token;
    char symbol;//문자
    int n = 0;
    int top = -1;//
    token = get_token(&symbol, &n); //주소값 전달
    
    while (token != eos){
        if (token == operand)
            push(token - '0');
        else{
            int op2 = pop();
            int op1 = pop();
            switch (token){
                case plus :
                    push(op1 + op2);
                    break;
                case minus:
                    push(op1 - op2);
                    break;
                case times:
                    push(op1 * op2);
                    break;
                case divide:
                    push(op1 / op2);
                    break;
                case mod:
                    push(op1 % op2);
                    break;
            }
        }
        token = get_token(symbol, n); //
    }
    return pop(); // result
}

precedence get_token (char *symbol, int *n){

    *symbol = expr[(*n)++]; //주소 포인트 잘 확인하기
    switch (*symbol){
        case '(':
            return lparen;
        case ')':
            return rparen;
        case '+':
            return plus;
        case '-':
            return minus;
        case '*':
            return times;
        case '/':
            return divide;
        case '%':
            return mod;
        case '\0':
            return eos;
        default :
            return operand;
    }
}
