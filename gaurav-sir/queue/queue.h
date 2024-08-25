#ifndef QUEUE_H
#define QUEUE_H
#include <stdbool.h>

typedef struct
{
    int *arr;
    int front;
    int rear;
    int N;
    int max_size;
} Queue;

void initQueue(Queue *q);
void enqueue(Queue *q, int x);
int dequeue(Queue *q);
int peek(Queue *q);
int size(Queue *q);
bool isempty(Queue *q);
void freeQueue(Queue *q);

#endif