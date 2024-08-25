#ifndef STACK_USING_LL_H
#define STACK_USING_LL_H

typedef struct StackNode {
    int index;
    struct StackNode* next;
} StackNode;

typedef struct {
    StackNode* next;
} Stack;

Stack* createStack();
int isEmpty(Stack* stack);
void push(Stack* stack, int index);
StackNode pop(Stack* stack);
StackNode next(Stack* stack);
void freeStack(Stack* stack);

#endif
