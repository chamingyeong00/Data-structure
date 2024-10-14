#include <stdio.h>
#include <stdlib.h> //exit
#define MAXSIZE 101
#define swap(a, b, temp) ((temp = a), (a = b), (b = temp)) //macro에 선언X

/*void swap(int *a, int *b)
{
    int temp; //temp int pointX
    temp = *a;
    *a = *b;
    *b = temp;
}*/

void sort (int n, int *list)
{
    int temp;
    for (int i=0; i<n-1; i++)
    {
        int min = i;
        for (int j=i+1; j<n; j++)
        {
            if(list[j] < list[min])
                min = j;
        }
        if (list[i] != list[min])
            swap(list[i], list[min], temp);
        //printf("%d %d", list[i], list[min]);
    }
}

int main(void)
{
    int i, n, list[MAXSIZE];
    printf("Enter the number of numbers to generate : ");
    scanf("%d", &n);
    if (n < 0 || n > MAXSIZE)
    {
        fprintf(stderr, "Improper value of n\n");
        exit(1); // exit(1) 강제 종료
    }
    for (i=0; i<n; i++)
    {
        list[i] = rand()%1000;
        printf("%d ", list[i]);
        //scanf("%d ", &list[i]); //buffer떄문에 입력값 하나가 더 생김
    }
    sort(n, list);
    printf("\nSorted array:\n");
    for (i=0; i<n; i++)
    {
        printf("%d ", list[i]);
    }
    printf("\n");
    return 0;
}