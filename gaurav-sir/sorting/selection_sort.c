#include <stdio.h>
#include <assert.h>
#include <sys/time.h>
#include <time.h>
#include <stdlib.h>

void exch(int arr[], int i, int j)
{
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[min_idx] > arr[j])
            {
                min_idx = j;
            }
        }
        exch(arr, i, min_idx);
    }
}

void test_simple_input(int arr[], int n)
{
    // int arr[] = {3, 1, 7, 9, 5};
    // int expected_out[] = {1, 3, 5, 7, 9};
    selection_sort(arr, n);
    // for (int i = 0; i < n; i++)
    //{
    //  assert(arr[i] == expected_out[i]);
    //  printf("%d ", arr[i]);
    //}
}

long long calculate_runtime(int arr[], int n)
{
    struct timeval before;
    gettimeofday(&before, NULL);
    long long before_millis = before.tv_sec * 1000LL + before.tv_usec / 1000;

    test_simple_input(arr, n);

    struct timeval after;
    gettimeofday(&after, NULL);
    long long after_millis = after.tv_sec * 1000LL + after.tv_usec / 1000;

    return after_millis - before_millis;
    // Time spent between last two epocs
    // printf("\n%llu \n", after_millis - before_millis);
}
int main()
{
    srand(time(NULL));
    int *arr1 = (int *)malloc(sizeof(int) * 32000);
    for (int i = 0; i < 32000; i++)
        arr1[i] = rand();
    long long t1 = calculate_runtime(arr1, 32000);

    int *arr2 = (int *)malloc(sizeof(int) * 64000);
    for (int i = 0; i < 64000; i++)
        arr2[i] = rand();
    long long t2 = calculate_runtime(arr2, 64000);

    printf("%lf ", t2 * 1.0 / t1);
    return 0;
}
