#ifndef STACK_H
#define STACK_H

typedef struct{
    unsigned int size;
    unsigned int capacity;
    int* data;
}stack;

int init_stack(stack *s);
int init_stack_with_capacity(stack *s, int capacity);
void free_stack(stack *s);
int push(stack *s, int value);
int pop(stack *s, int *out);
int peek(stack *s, int *out);
int is_empty(const stack *s);

#endif