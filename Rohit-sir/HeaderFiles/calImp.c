#include "cal.h"
#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}
int sub(int a, int b)
{
    return a - b;
}
int mul(int a, int b)
{
    return a * b;
}
float div(int a, int b)
{
    if (b == 0)
    {
        printf("Zero Div Error");
        return -1;
    }

    return a / b;
}