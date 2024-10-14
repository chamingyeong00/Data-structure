#define MAX_TERMS 100

typedf struct {
    int row;
    int col;
    int val;
} term;
term a[MAX_TERMS];
term b[MAX_TERMS];

void transpose(term a[], term b[])
{
    int cnt = a[0].val;
    b[0].col = a[0].row;
    b[0].row = a[0].col;
    b[0].val = cnt;

    if (cnt > 0){
        int currentb = 1;
        for (int i=0; i<a[0].col; i++)
        {
            for (int j=1; j<=cnt; j++)
            {
                if (a[j].col == i)
                {
                    b[currentb].row = a[j].col;
                    b[currentb].col = a[j].row;
                    b[currentb].val = a[j].val;
                    currentb++;
                }
            }
        }
    }
}