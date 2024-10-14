#define MAX_COL 50

tyedef struct{
    int row;
    int col;
    int val;
} term;
term a[MAX_COL];
term b[MAX_COL];
term d[MAX_COL];
fast_transpose()

void mmult(term a[], term b[], term d[]){

    if (a[0].col != b[0].row){
      fprintf(stderr, "Incompatible matricses\n");
      exit(1);
    }
    term trans_b;
    fast_transpose(b, trans_b);

    int row = a[1].row; //a[1]
    int totala = a[0].value;
    int totalb = b[0].value;
    int totald = 0;
    int sum = 0;
    term a[totala+1].row = a[0].row;
    term trans_b[totalb+1].row = trans_b[0].col;
    int row_begin = 1;

    //for문에서 증가 안해줌
    for (int i=1; i<=totala;){ //1~totala
      int col = trans_b[1].row; //for문 안에다가
      for (int j=1; j<=totalb+1;){ //1~totalb
        if (a[i].row != row){
          storesum(d, &totald, row, col, &sum); //&totald(주소), row, col, &sum(주소)
          i = row_begin;
          for (;trans_b[j].row==col; j++);
          col = trans_b[j].row;
        }
        else if (tarns_b[j].row != col){
          storesum(d, totald, i, j, sum);
          i = row_begin;
          col = trans_b[j].row;
        }
        else switch(COMPARE(a[i].col, trans_b[j].col)){
          case -1:
            i++;
            break;
          case 0:
            sum += (a[i++].value * trnas_b[j++].value);
            break;
          case 1:
            j++;
        }
      }
      for (; a[i].row==row; i++)
      row_begin = i;
      row = a[i].row;
    }
    d[0].row = a[0].row;
    d[0].col = a[0].col;
    d[0].val = totald; //totald
}

void storesum(term d[], int *totald, int row, int col, int *sum){
  if(*sum){
    if (*totald < MAX_TERMS){//MAX_TERMS range check
    d[++*totald].row = row;
    d[*totald].col = col;
    d[*totald].val = *sum; //val, *(pointer)sum
    *sum=0;
    }
  }
  else{
    fprintf(stderr, "Numbers of terms in product exceeds %d\n", MAX_TERMS);
    exit(1);
  }  
}