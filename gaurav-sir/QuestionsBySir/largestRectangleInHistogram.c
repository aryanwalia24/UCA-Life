#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../stack/stack_using_LL.h"

int largestRectangleArea(int *heights, int n)
{
    int area = 0;
    Stack *stack = createStack();
    push(stack, -1);
    heights[n] = -1; 

    for (int i = 0; i <= n; i++)
    {
        while (next(stack).index != -1 && heights[next(stack).index] > heights[i])
        {
            int l = heights[next(stack).index];
            pop(stack);
            int b = i - next(stack).index - 1;
            area = (area > l * b) ? area : l * b;
        }
        push(stack, i);
    }
    freeStack(stack);
    return area;
}

void testLargestRectangleArea()
{
    int heights1[] = {2, 1, 5, 6, 2, 3};
    int n = sizeof(heights1) / sizeof(heights1[0]);
    assert(largestRectangleArea(heights1, n) == 10);
    for (int i = 0; i < n; i++)
    {
        printf("%d ",heights1[i]);
    }
    printf("\nArea : %d \n\n",largestRectangleArea(heights1,n));

    int heights2[] = {2, 4};
    int m = sizeof(heights2) / sizeof(heights2[0]);
    assert(largestRectangleArea(heights2, m) == 4);
    for (int i = 0; i < m; i++)
    {
        printf("%d ",heights2[i]);
    }
    printf("\nArea : %d \n",largestRectangleArea(heights2,m));

    printf("All tests passed!\n");
}

int main()
{
    testLargestRectangleArea();
    return 0;
}
