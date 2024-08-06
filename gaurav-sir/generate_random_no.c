#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // if not null -> no randomness
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", rand());
    }

    return 0;
}