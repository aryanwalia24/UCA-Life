#include <stdio.h>
int main()
{
    int arr[6];
    int *aptr = arr;
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    for (int i = 0; i <= n; i++)
    {
        printf("%d ", *(aptr + i));
    }
    printf("\n");
    return 0;
}
