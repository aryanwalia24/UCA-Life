#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "queue_LL.h"

void initQueue(Queue *q)
{
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

void enqueue(Queue *q, int x)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;
    if (q->rear == NULL)
    {
        q->front = q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

int dequeue(Queue *q)
{
    if (q->front == NULL)
    {
        return INT_MIN;
    }
    Node *temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL)
    {
        q->rear = NULL;
    }
    free(temp);
    q->size--;
    return data;
}

int peek(Queue *q)
{
    if (q->front == NULL)
    {
        return INT_MIN;
    }
    return q->front->data;
}

int size(Queue *q)
{
    return q->size;
}

bool isempty(Queue *q)
{
    return q->front == NULL;
}

void freeQueue(Queue *q)
{
    while (!isempty(q))
    {
        dequeue(q);
    }
}
