#include <stdio.h>

unsigned int do_something(unsigned int x, unsigned int y){
    while (y!=0){
        int temp;
        temp = x%y;
        printf("temp : %d\t", temp);
        printf("y : %d", y);
        x = y;
        y = temp;
        printf("\n");
    }
    return x;
}

int main(void){
    printf("%d", do_something(660, 735));
}