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
    int starting_pos[MAX_COL];
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

        starting_pos[0] = 1;
        for (int i=1; i<col; i++){
            starting_pos[i] = starting_pos[i-1]+row_terms[i-1]; //row_terms[i-1]
        }

        for (int i=1; i<=cnt; i++){
            int start = starting_pos[a[i].col]++;
            b[start].col = a[i].row;
            b[start].row = a[i].col;
            b[start].value = a[i].value;
        }
    }

}