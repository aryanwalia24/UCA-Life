#include "stack.h"

void push(int *arr, int *idx, int val)
{
    arr[*idx + 10] = val;
    (*idx)++;
}

int pop(int *arr, int *idx)
{
    if (*idx == 0)
    {
        return -1;
    }

    (*idx)--;
    arr[*idx + 10] = 0;
    return arr[*idx + 10];
}
