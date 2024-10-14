#define MAX_COL 50

tyedef struct{
    int row;
    int col;
    int val;
} term;
term a[MAX_COL];
term b[MAX_COL];

void fast_transpose(term a[], term b[]){
    int row_terms[MAX_COL];
    int cnt = a[0].val;
    b[0].col = a[0].row;
    int col = b[0].col;
    b[0].row = a[0].col;
    b[0].val = cnt;

    if (cnt > 0){
        for (int i=0; i<col; i++){
            row_terms[i] = 0;//starting_pos initialization??
        }

        for (int i=1; i<=cnt; i++){ //check
            row_terms[a[i].col]++;
        }

        int tmp1 = 1;
        int tmp2 = 0;
        for (int i=0; i<col; i++){
            tmp2 = row_terms[i];
            row_terms[i] = tmp1;
            tmp1 += tmp2;
        }

        for (int i=1; i<=cnt; i++){
            int start = row_terms[a[i].col]++;
            b[start].col = a[i].row;
            b[start].row = a[i].col;
            b[start].value = a[i].value;
        }
    }

}