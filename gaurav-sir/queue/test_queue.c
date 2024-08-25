#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include "queue.h"

// to run Queue using arr         -> gcc -o test1 queue.c test_queue.c -> ./test1
// to run Queue using Linked list -> gcc -o test2 queue_LL.c test_queue.c -> ./test2

int main()
{
    Queue q;
    initQueue(&q);

    enqueue(&q, 3);
    enqueue(&q, 5);
    enqueue(&q, 7);

    assert(size(&q) == 3);
    assert(isempty(&q) == false);

    assert(peek(&q) == 3);
    assert(size(&q) == 3);
    assert(isempty(&q) == false);

    assert(dequeue(&q) == 3);
    assert(size(&q) == 2);
    assert(isempty(&q) == false);
    printf("Success!");
    freeQueue(&q);
    return 0;
}