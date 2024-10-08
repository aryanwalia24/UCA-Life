#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *a, int *b)
{
   int temp = *a;
   *a = *b;
   *b = temp;
}
int partition(int nums[], int left, int right)
{
   int pivotIndex = left + rand() % (right - left + 1);
   swap(&nums[left], &nums[pivotIndex]);
   int pivot = nums[left], l = left + 1, r = right;
   while (l <= r)
   {
      if (nums[l] < pivot && nums[r] > pivot)
      {
         swap(&nums[l], &nums[r]);
         l++;
         r--;
      }
      if (nums[l] >= pivot)
         l++;
      if (nums[r] <= pivot)
         r--;
   }
   swap(&nums[left], &nums[r]);
   return r;
}
int findKthLargest(int nums[], int numsSize, int k)
{
   int left = 0, right = numsSize - 1, kth;
   while (1)
   {
      int idx = partition(nums, left, right);
      if (idx == k - 1)
      {
         kth = nums[idx];
         break;
      }
      if (idx < k - 1)
         left = idx + 1;
      else
         right = idx - 1;
   }
   return kth;
}
int main()
{
   int nums[] = {3, 2, 1, 5, 6, 4};
   int numsSize = sizeof(nums) / sizeof(nums[0]);
   int k = 2;
   srand(time(NULL));
   int kthLargest = findKthLargest(nums, numsSize, k);
   printf("The %d-th largest element is: %d\n", k, kthLargest);
   return 0;
}
