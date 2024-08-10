#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
void merge(int arr[], int aux[], int left, int mid, int right)
{
	for (int k = left; k <= right; k++)
	{
		aux[k] = arr[k];
	}
	int i = left;
	int j = mid + 1;
	for (int k = left; k <= right; k++)
	{
		if (i > mid)
		{
			arr[k] = aux[j++];
		}
		else if (j > right)
		{
			arr[k] = aux[i++];
		}
		else if (aux[i] <= aux[j])
		{
			arr[k] = aux[i++];
		}
		else
		{
			arr[k] = arr[j++];
		}
	}
}
void merge_sort_recursive(int arr[], int aux[], int left, int right)
{
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	merge_sort_recursive(arr, aux, left, mid);
	merge_sort_recursive(arr, aux, mid + 1, right);
	merge(arr, aux, left, mid, right);
}
void merge_sort(int *arr, int n)
{
	int *aux = (int *)malloc(n * sizeof(int));
	merge_sort_recursive(arr, aux, 0, n - 1);
	free(aux);
}

long long calc_time(int *arr, int n)
{
	struct timeval before;
	gettimeofday(&before, NULL);
	long long before_millis = before.tv_sec * 1000LL + before.tv_usec / 1000;
	merge_sort(arr, n);
	struct timeval after;
	gettimeofday(&after, NULL);
	long long after_millis = after.tv_sec * 1000LL + after.tv_usec / 1000;
	return after_millis - before_millis;
}

void test_simple_input()
{
	int arr[] = {3, 1, 7, 9, 5};
	int expected[] = {1, 3, 5, 7, 9};
	merge_sort(arr, 5);
	for (int i = 0; i < 5; i++)
	{
		assert(arr[i] == expected[i]);
	}
}

int main()
{
	test_simple_input();
	srand(time(NULL));

	int k = 32000;
	int *arr1 = (int *)malloc(k * sizeof(int));
	for (int i = 0; i < k; i++)
	{
		arr1[i] = rand();
	}

	long long t1 = calc_time(arr1, k);

	k = 64000;
	int *arr2 = (int *)malloc(k * sizeof(int));
	for (int i = 0; i < k; i++)
	{
		arr2[i] = rand();
	}

	long long t2 = calc_time(arr2, k);

	printf("Time Elpased for Array 1 :- %llu ms\n", t1);
	printf("Time Elapsed for Array 2 :- %llu ms\n", t2);

	printf("Ratio :- %lf\n", (t2 * 1.0 / t1));
	return 0;
}
