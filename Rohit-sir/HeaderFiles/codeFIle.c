#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
    int n = 10;
    int *arr = (int *)malloc(n * sizeof(int));
    int idx = 0;

    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }

    push(arr, &idx, 50);
    push(arr, &idx, 60);
    push(arr, &idx, 70);

    printf("Size of arr now: %d\n", n + idx);
    for (int i = 0; i < n + idx; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    pop(arr, &idx);
    pop(arr, &idx);
    pop(arr, &idx);
    pop(arr, &idx);

    printf("Size of arr now: %d\n", n + idx);
    for (int i = 0; i < n + idx; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
