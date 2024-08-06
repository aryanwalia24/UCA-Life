#include <stdio.h>
void exch(int arr[], int i, int j)
{
    int t = arr[j];
    arr[j] = arr[i];
    arr[i] = t;
}
void bs(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                exch(arr, i, j);
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        int ele;
        scanf("%d", &ele);
        arr[i] = ele;
    }
    bs(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
