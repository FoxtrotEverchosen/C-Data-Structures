#ifndef STACK_H
#define STACK_H

typedef struct{
    unsigned int size;
    unsigned int capacity;
    int* data;
}stack;

void init_stack(stack *s);
void init_stack_with_capacity(stack *s, int capacity);
void free_stack(stack *s);
void push(stack *s, int value);
int pop(stack *s);
int peek(stack *s);
int is_empty(stack *s);

#endif