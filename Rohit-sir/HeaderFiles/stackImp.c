#include "stack.h"

void push(int *arr, int *idx, int val)
{
    arr[*idx] = val;
    (*idx)++;
}

int pop(int *arr, int *idx)
{
    if (*idx == 0)
    {
        return -1;
    }

    (*idx)--;
    arr[*idx] = 0;
    return arr[*idx];
}
