#include <stdio.h>

void swap(char *a, char *b)
{
    char temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void perm(char *list, int i, int n)
{
    int j, temp;
    if (i == n)
    {
        for (int k = i; k <= n; k++) //j로 해도 됨
        {
            printf("%c\t", list[k]);
        }
        printf("\n");
    }
    else{
        for (int j = i; j <= n; j++)
        {
            swap(&list[i], &list[j]);
            //printf("swap : %c %c\n", list[i], list[j]);
            perm(list, i+1, n); //list 모두 줘야 함
            swap(&list[i], &list[j]);
        }
    }
}

int main(void)
{
    char list[3] = {'a', 'b', 'c'};
    for (int k = 0; k<= 2; k++)
    {
        printf("%c\t", list[k]);
    }
    printf("\n\n\n");
    perm(list, 1, 2);
}