#include <stdio.h>
#include <stdlib.h>
int main()
{
    int arr[] = {4, 4, 1, 1, 1, 1, 2, 2, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        int index = (abs(arr[i]) % n) - 1;
        arr[index] = -arr[index];
    }
    printf("Odd elements: ");
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            printf("%d ", i+1);
        }
    }
    printf("\n");
    return 0;
}
