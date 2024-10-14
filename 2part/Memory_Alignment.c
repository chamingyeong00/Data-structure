#include <stdio.h>

struct {
    int a;
    int b;
    char c;
} A;

struct b{
    char d;
    int e;
    char f;
} B;

struct c{
    char g;
    short h;
    int i;
} C;

int main(void)
{
    printf("struct : %lu\n", sizeof(A));
    printf("struct : %lu\n", sizeof(B));
    printf("struct : %lu\n", sizeof(C));

}
