#ifndef STACK_H
#define STACK_H

#include <stdint.h>
#include <stddef.h>

typedef struct{
    size_t size;
    size_t capacity;
    int* data;
}stack;

int init_stack(stack *s);
int init_stack_with_capacity(stack *s, size_t capacity);
void free_stack(stack *s);
int push(stack *s, int value);
int pop(stack *s, int *out);
int peek(stack *s, int *out);
int is_empty(const stack *s);

#endif