d = Zero();
while(!IsZero(a) && !IsZero(b)) do { //do
    switch (COMPARE(Lead_Exp(a), Lead_Exp(b))){
        case -1:
            d = Attach(d, Coef(b, Lead_Exp(b)), Lead_Exp(b));
            b = Remove(b, Lead_Exp(b)); //return 값 b로 받아야 함
            break;
        case 0;
            int sum = Coef(a, Lead_Exp(a)) + Coef(b, Lead_Exp(b));
            if (sum) //if sum is not 0
                d = Attach(d, sum, Lead_Exp(a));
            //remove
            a = Remove(a, Lead_Exp(a));
            b = Remove(b, Lead_Exp(b));
            break;
        case 1;
            d = Attach(d, Coef(a, Lead_Exp(a)), Lead_Exp(a))
            a = Remove(a, Lead_Exp(a));
    }
    나머지 항 추가
}