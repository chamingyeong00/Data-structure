#include <stdio.h>
#include <stdlib.h> //exit
#define MAXSIZE 101
#define swap(a, b, temp) ((temp = a), (a = b), (b = temp)) //macro에 선언X
#define cmp(a, b) ((a>b)? 1: ((a < b)? -1 : 0))

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
    }
}

/*int cmp(int a, int b)
{
    if (a > b)
        return 1;
    else if (a < b)
        return -1;
    else
        return 0;
}*/

int iteration_binaray_sort(int *list, int key, int left, int right)
{
    while (left <= right)
    {
        int mid = (left + right)/2; //mid..
        //printf("%d\t", mid);
        switch(cmp(list[mid], key))
        {
            case -1:
                left = mid + 1;
                break;
            case 0:
                return mid;
            case 1:
                right = mid - 1;
      }
    }
    return -1;
}

int recursive_binaray_sort(int *list, int key, int left, int right)
{
    while (left <= right)
    {
        int mid = (left + right)/2; //mid..
        //printf("%d\t", mid);
        switch(cmp(list[mid], key))
        {
            case -1:
                return recursive_binaray_sort(list, key, mid + 1, right); //return으로 해야 함
                //break; //할 경우 return이 돌아오면 error
            case 0:
                return mid;
            case 1:
                return recursive_binaray_sort(list, key, left, mid - 1);
      }
    }
    printf("\n");
    return -1;
}

int main(void)
{
    int i, n, list[MAXSIZE], key,res;
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
    printf("\nEnter the key : ");
    scanf("%d", &key);
    //res = iteration_binaray_sort(&list, key, 0, n-1);
    res = recursive_binaray_sort(list, key, 0, n-1); //left, right에 index value 
    printf("find the key:\n");
    printf("%d ", res);
    printf("\n");
    return 0;
}