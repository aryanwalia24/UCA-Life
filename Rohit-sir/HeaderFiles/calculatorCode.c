#include "cal.h"
#include <stdio.h>

int main()
{
    int a = 4, b = 3;
    printf("Add : %d\n", add(a, b));
    printf("Subt : %d\n", sub(a, b));
    printf("Multi : %d\n", mul(a, b));
    printf("Div : %0.2f\n", divi(a, b));
    return 0;
}