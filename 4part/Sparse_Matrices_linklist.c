#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 50
typedef enum {head, entry}tagfield;
typedef struct matrix_node *matrix_pointer;
struct entry_node{
    int row;
    int col;
    int value;
};
matrix_pointer new_node(void);
void mwrite(matrix_pointer node);

struct matrix_node{
    matrix_pointer down;
    matrix_pointer right;
    tagfield tag;
    union{
        matrix_pointer next;
        struct entry_node entry;
    }u;
};
matrix_pointer hdnode[MAX_SIZE];

matrix_pointer mread(void){
    int num_rows, num_cols, num_terms, num_heads, i;
    int row, col, value, current_row;
    matrix_pointer temp, last, node;

    printf("Enter # of rows, columns, and number of nonzero terms: ");
    scanf("%d%d%d", &num_rows, &num_cols, &num_terms);
    num_heads = (num_cols > num_rows)? num_cols : num_rows;

    node = new_node(); node->tag = entry;
    node->u.entry.row = num_rows;
    node->u.entry.col = num_cols;
    node->u.entry.value = num_terms;

    if (!num_heads)
        node->right = node;
    else{
        hdnode[i] = new_node();
        hdnode[i]->tag = head;
        hdnode[i]->right = hdnode[i];
        hdnode[i]->u.next = hdnode[i];
    }
    current_row = 0;
    last = hdnode[0];
    for(i = 0; i<num_terms; i++){
        printf("Enter row, column and value: ");
        scanf("%d%d%d", &row, &col, &value);
        if(row > current_row){
            last->right = hdnode[current_row];
            current_row = row; last = hdnode[row];
        }
        temp = new_node();
        temp->tag = entry;
        temp->u.entry.row = row;
        temp->u.entry.col = col;
        temp->u.entry.value = value;
        last->right = temp; //행에 추가
        last=temp; 
        hdnode[col]->u.next->down = temp; //열에 추가
        hdnode[col]->u.next = temp;
        last->right = hdnode[current_row]; //행 헤드 리스트 추가
        for (i=0; i<num_cols; i++)
            hdnode[i]->u.next->down = hdnode[i]; //열 헤드 리스트 연결
        for (i=0; i<num_rows; i++)
            hdnode[i]->u.next = hdnode[i+1]; //옆 행과 연결
        hdnode[num_heads-1]->u.next = node; //행 헤드 연결
        node->right = node->down = hdnode[0]; //헤드와 hdnode[0]연결
    }
    return node;
}

matrix_pointer new_node(void)
{
    matrix_pointer temp;
    temp = (matrix_pointer)malloc(sizeof(matrix_pointer));
    if(temp == NULL)
    {
        fprintf(stderr, "The memory is full\n");
        exit(1);
    }
    return temp;
}

void mwrite(matrix_pointer node){
    int i;
    matrix_pointer temp, head = node->right;
    printf("num_rows = %d, num_cols = %d\n", node->u.entry.row, node->u.entry.col);
    printf("The matrix by row, column, and value: \n\n");
    for(int i=0; i < node->u.entry.row; i++){
        for (temp = head->right; temp != head; temp = temp->right){
            printf("%5d%5d%5d\n", temp->u.entry.row, temp->u.entry.col, temp->u.entry.value);
        }
        head = head->u.next;
    }
}
int main(void){
    mread();
}