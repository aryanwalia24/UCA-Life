#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "queue.h"

#define INITIAL_CAP 1

void initQueue(Queue *q)
{
    q->arr = (int *)malloc(INITIAL_CAP * sizeof(int));
    q->front = 0;
    q->rear = 0;
    q->N = 0;
    q->max_size = INITIAL_CAP;
}

void resize_arr(Queue *q, int new_cap)
{
    int *aux = (int *)malloc(new_cap * sizeof(int));
    for (int i = 0; i < q->N; i++)
    {
        aux[i] = q->arr[(q->front + i) % q->max_size];
    }
    free(q->arr);
    q->arr = aux;
    q->front = 0;
    q->rear = q->N;
}
void enqueue(Queue *q, int x)
{
    if (q->N == q->max_size)
    {
        q->max_size *= 2;
        resize_arr(q, q->max_size);
    }
    q->arr[q->rear] = x;
    q->rear = (q->rear + 1) % q->max_size;
    q->N++;
}
int dequeue(Queue *q)
{
    if (q->N == 0)
        return INT_MIN;
    int val = q->arr[q->front];
    q->front = (q->front + 1) % q->max_size;
    q->N--;
    if (q->N <= q->max_size / 4)
    {
        q->max_size /= 2;
        resize_arr(q, q->max_size);
    }
    return val;
}

int peek(Queue *q)
{
    if (q->N == 0)
        return INT_MIN;
    return q->arr[q->front];
}

int size(Queue *q)
{
    return q->N;
}

bool isempty(Queue *q)
{
    return q->N == 0;
}

void freeQueue(Queue *q)
{
    while (!isempty(q))
    {
        dequeue(q);
    }
}