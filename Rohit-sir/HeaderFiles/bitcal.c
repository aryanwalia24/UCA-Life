#include <stdlib.h>
#include "cal.h"

int add(int a, int b)
{
    while (b != 0)
    {
        int carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}
int sub(int a, int b)
{
    int sign = ((a < 0) ^ (b < 0)) ? -1 : 1;
    int ans = add(a, add(~b, 1));
    return ans * sign;
}
int mul(int a, int b)
{
    int ans = 0;
    while (b != 0)
    {
        if (b & 1)
        {
            ans = add(ans, a);
        }
        a <<= 1;
        b >>= 1;
    }
    return ans;
}
float divi(int a, int b)
{
    int quotient = 0;
    int sign = ((a < 0) ^ (b < 0)) ? -1 : 1;

    a = abs(a);
    b = abs(b);

    while (a >= b)
    {
        a = sub(a, b);
        quotient = add(quotient, 1);
    }

    return sign * quotient;
}
