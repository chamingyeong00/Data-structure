#define MAX_TERMS 100

typedef struct{ //구조제 typedef
    float coef;
    int expon;
} polynomial; 
polynomial terms[MAX_TERMS];//polynomial형으로 MAX_TERMS개의 terms생성
int avail=0; //initialization

void padd(int starta, int finisha, int startb, int finishb, int *startd, int *finishd) //finsh가 있는 이유
{
    *startd = avail;
    while(starta <= finisha && startb <= finishb){//check finisha, finishb 
        swtich(COMPARE(terms[starta].expon, terms[startb].expon)){
            case -1:
                attach(terms[startb].coef, terms[startb].expon);
                startb++;   
                break;
            case 0;
                float coefficient = terms[startb].coef + terms[starta].coef;//float
                if (coefficient)//coefficient is not 0
                    attach(coefficient, terms[starta].expon);
                starta++;
                startb++;
                break;
            case 1;
                attach(terms[starta].coef, terms[starta].expon);
                starta++;
        }
    }
    for(;starta<=finisha; starta++){ 
        attach(terms[starta].coef, terms[starta].expon);
        //terms[avail].coef = terms[starta].coef;
        //terms[avail++].expon = terms[starta].expon;
    }
    for(;startb<=finishb; startb++){
        attach(terms[startb].coef, terms[startb].expon);
        //terms[avail].coef = terms[startb].coef;
        //terms[avail++].expon = terms[startb].expon;
    }
    *finishd = avail-1; //finishd's value
}

void attach(float coefficient, int exponent){
    if(avail >= MAX_TERMS){
        fprintf(stderr, "Too many terms in the polynomial.\n");
        exit(1);
    }
    terms[avail].coef = coefficient;
    terms[avail++].expon = exponent;
}