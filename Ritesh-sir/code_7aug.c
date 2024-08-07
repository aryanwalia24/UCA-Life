#include <stdio.h>
int invert(int x)
{
    return x^-1;
}

int sign(int x)
{
    // int sign = x>>31;
    // int mask = ((x|~x+1)>>31) & 1;
    // return sign | mask;
    return x >> 31 | !!x;
}

int bitAnd(int x, int y)
{
    return ~(~x | ~y);
}

int conditional(int x, int y, int z)
{
    return (((!(!x)) << 31) >> 31 & y) + ((!x << 31) >> 31 & z);
}

int bang(int x)
{
    return ((x | ~x) >> 31) + 1;
}
int main()
{
    int x = 5, y = 6, z = 7;
    int ans = invert(x);
    printf("%d\n", ans);

    int ans1 = sign(-x);
    printf("%d\n", ans1);

    int ans2 = bitAnd(x, y);
    printf("%d\n", ans2);

    int ans3 = conditional(x, y, z);
    printf("%d\n", ans3);

    int ans4 = bang(x);
    printf("%d\n", ans4);

    return 0;
}
