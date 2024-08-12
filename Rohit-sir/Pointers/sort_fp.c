#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int arr[], int size, int (*compare)(int, int)) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (compare(arr[j], arr[j + 1]) > 0) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int compareAsc(int a, int b) {
    return a - b;
}

int compareDesc(int a, int b) {
    return b - a;
}

void display(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    display(arr, size);

    sort(arr, size, compareAsc);
    printf("Sorted in increasing order: ");
    display(arr, size);

    sort(arr, size, compareDesc);
    printf("Sorted in decreasing order: ");
    display(arr, size);

    return 0;
}
