#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
    int n = 10;
    int *arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }

    push(arr, &n, 50);
    push(arr, &n, 60);
    push(arr, &n, 70);

    printf("Size of arr now: %d\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    pop(arr, &n);
    pop(arr, &n);
    pop(arr, &n);
    pop(arr, &n);

    printf("Size of arr now: %d\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
