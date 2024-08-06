#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <assert.h>


void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int n, int low, int high){
    int pivot = arr[low];
    int cnt = 0;
    for(int i = low+1; i <= high; i++){
        if(arr[i] <= pivot){
            cnt++;
        }
    }

    int pivotIndex = low + cnt;
    swap(&arr[pivotIndex], &arr[low]);

    int i = low, j = high;
    while(i < pivotIndex && j > pivotIndex){
        while(arr[i] <= pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if(i < j){
            swap(&arr[i++], &arr[j--]);
        }
    }

    return pivotIndex;
}

void quick_sort(int arr[], int n, int low, int high){
    if(low >= high) return;

    int p = partition(arr, n, low, high);
    quick_sort(arr, n, low, p - 1);
    quick_sort(arr, n, p + 1, high);
}


void helper() {
    int n = 1280000;
    int *arr = (int *)malloc(n * sizeof(int));

    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        arr[i] = rand();
    }

    struct timeval before;
    gettimeofday(&before, NULL);
    long long before_millis = before.tv_sec * 1000LL + before.tv_usec / 1000;

    // mergeSort(arr, n, 0, n - 1);
    // selection_sort(arr, n);
    quick_sort(arr, n, 0, n-1);
    struct timeval after;
    gettimeofday(&after, NULL);
    long long after_millis = after.tv_sec * 1000LL + after.tv_usec / 1000;

    printf("Time taken to sort the array: %lld ms\n", after_millis - before_millis);

    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
}



int main(){
    helper();
    return 0;
}