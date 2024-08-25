#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int solve(int num)
{
    long long ans = 0;
    bool sign = false;
    if (num < 0)
    {
        sign = true;
        num *= -1;
    }
    while (num != 0)
    {
        int dig = num % 10;
        if (ans > (INT_MAX - dig) / 10)
            return 0;
        ans = ans * 10 + dig;
        num /= 10;
    }
    if (!sign)
    {
        return ans;
    }
    return ans * -1;
}

void test()
{
    int a = 123;
    int b = -123;
    int c = 120;

    assert(solve(INT_MAX) == 0);
    assert(solve(INT_MIN) == 0);
    assert(solve(c) == 21);
    printf("%d \n", solve(a));
    printf("%d \n", solve(b));
    printf("%d \n", solve(c));
}
int main()
{
    test();
    return 0;
}