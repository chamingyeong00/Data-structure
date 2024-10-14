#define MAX_STACK_SIZE 100

typedef struct{
    int x;
    int y;
    int dir;
} offset;

offset move[8];

typedef struct{
    short int row;
    short int col;
    short int dir;
} element;
element stack[MAX_STACK_SIZE];

void path(void){
    int maze[50][50]; //미로
    int mark[50][50]; //기존에 갔다왔던 길    
    stack[0].row = 1;
    stack[0].col = 1;
    stack[0].dir = 2;
    int top = 0, found = FALSE, dir, row, col, x, y;

    while (top > -1 && !found){ //stack is not empty
        element position;
        position = pop(); //pop이 감소되기전 position에 들어간 후 top이 감소 됨
        row = position.row;
        col = position.col;
        dir = position.dir;
        while (dir < 8 && !found){
            int next_row = row + move[dir].x; //stack[top].row (X)
            int next_col = col + move[dir].y; //stack[top].col (X)
            if ((next_row == x)&&(next_col == y)){//
                found = TRUE;
            }
            else if (!maze[next_row][next_col] && !mark[next_row][next_col]){
                //maze[next_row][next_col] == 0 && mark[next_row][next_col] == 0
                mark[next_row][next_col] = 1;
                position.row = row; //
                position.col = col; //
                position.dir = ++dir; //
                push(position); //
                row = next_row; 
                col = next_col;
                dir = 0;
            }
            else
                ++dir;//dir++
        }
    }
    if (found){
        printf("The path is: \n");
        printf("row col\n");
        for (int i=0; i<= top; i++)
            printf("%2d %5d", stack[i].row, stack[i].col);
        printf("%2d %5d \n", row, col);
        printf("%2d %5d \n", x, y);
    }
    else 
        printf("The maze dose not have a path \n");
}
/*
move[0].x = -1;
move[0].y = 0;
move[0].dir = 0;
move[1].x = -1;
move[1].y = 1;
move[1].dir = 1;
move[2].x = 0;
move[2].y = 1;
move[2].dir = 2;
move[3].x = 1;
move[3].y = 1;
move[3].dir = 3;
move[4].x = 1;
move[4].y = 0;
move[4].dir = 4;
move[5].x = 1;
move[5].y = -1;
move[5].dir = 5;
move[6].x = 0;
move[6].y = -1;
move[6].dir = 6;
move[7].x = -1;
move[7].y = -1;
move[7].dir = 7;
*/