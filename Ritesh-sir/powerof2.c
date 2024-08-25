#include <stdio.h>
int main()
{
    int n = 5;
    if (n & n - 1 == 0)
    {
        printf("yes");
    }

    //(n&-n) == n or -n;
    return 0;
}
