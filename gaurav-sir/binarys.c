#include <stdio.h>
int bs(int arr[], int n, int i, int ele)
{
    int low = 0;
    int high = n;
    int mid = low + (high - low) >> 1;
    while (low < high)
    {
        if (arr[mid] == ele)
        {
            return mid;
        }
        else if (arr[mid] > ele)
        {
            mid = low + 1;
        }
        else
        {
            mid = high - 1;
        }
    }
    return -1;
}
int main()
{
    // int arr[]= {1,2,3,4,5,6,7,8,9};
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        int ele;
        scanf("%d", &ele);
        arr[i] = ele;
    }
    int ans = bs(arr, n, 0, 4);
    printf("Index of : 4 -> %d", ans);
    return 0;
}
