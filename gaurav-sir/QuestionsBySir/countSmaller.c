#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Ele {
    int val;
    int idx;
    int cnt;
} Ele;

void merge_all(Ele* nums, Ele* aux, int l, int mid, int r) {
    int i = l;
    int j = mid + 1;
    int inv = 0;

    for (int k = l; k <= r; k++) {
        aux[k] = nums[k];
    }

    for (int k = l; k <= r; k++) {
        if (i > mid) {
            nums[k] = aux[j++];
        } else if (j > r) {
            nums[k] = aux[i++];
            nums[k].cnt += inv;
        } else if (aux[i].val <= aux[j].val) {
            nums[k] = aux[i++];
            nums[k].cnt += inv;
        } else {
            nums[k] = aux[j++];
            inv++;
        }
    }
}

void merge_sort_variant(Ele* nums, Ele* aux, int l, int r) {
    if (l >= r)
        return;
    int mid = l + (r - l) / 2;
    merge_sort_variant(nums, aux, l, mid);
    merge_sort_variant(nums, aux, mid + 1, r);
    merge_all(nums, aux, l, mid, r);
}

int* countSmaller(int* nums, int numsSize, int* returnSize) {
    int n = numsSize;
    Ele* nums_2 = (Ele*)malloc(n * sizeof(Ele));
    Ele* aux = (Ele*)malloc(n * sizeof(Ele));
    int* count = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        nums_2[i].val = nums[i];
        nums_2[i].idx = i;
        nums_2[i].cnt = 0;
        aux[i] = nums_2[i];
    }

    merge_sort_variant(nums_2, aux, 0, n - 1);

    for (int i = 0; i < n; i++) {
        count[nums_2[i].idx] = nums_2[i].cnt;
    }

    free(nums_2);
    free(aux);

    *returnSize = n;
    return count;
}

void test_sample_case() {
    int nums[] = {5, 3, 1, 9, 7};
    int expected[] = {2, 1, 0, 1, 0};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int* result = countSmaller(nums, numsSize, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
        assert(result[i] == expected[i]);
    }
    printf("\n");
    free(result);
}

int main() {
    test_sample_case();
    printf("Test Passed!\n");
    return 0;
}

