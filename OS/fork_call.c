#include <stdio.h>
#include <unistd.h>
int main()
{
    fork();
    printf("H1\n");
    fork();
    printf("H1\n");
    return 0;
}
