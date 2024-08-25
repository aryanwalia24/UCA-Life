#include <stdio.h>
#include <stdlib.h>
#include "stack_using_LL.h"

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->next = NULL;
    return stack;
}

int isEmpty(Stack* stack) {
    return stack->next == NULL;
}

void push(Stack* stack, int index) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->index = index;
    newNode->next = stack->next;
    stack->next = newNode;
}

StackNode pop(Stack* stack) {
    if (isEmpty(stack)) {
        return (StackNode){-1, NULL};
    }
    StackNode* temp = stack->next;
    StackNode poppedNode = *temp;
    stack->next = stack->next->next;
    free(temp);
    return poppedNode;
}

StackNode next(Stack* stack) {
    if (isEmpty(stack)) {
        return (StackNode){-1, NULL};
    }
    return *stack->next;
}

void freeStack(Stack* stack) {
    while (!isEmpty(stack)) {
        pop(stack);
    }
    free(stack);
}
