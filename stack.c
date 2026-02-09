#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

void init_stack(stack *s){
    s->capacity = 32;
    s->size = 0;
    s->data = malloc(s->capacity * sizeof(int));

    if(s->data == NULL){
        printf("Failed to allocate memory\n");
        exit(1);
    }
}

void init_stack_with_capacity(stack *s, int capacity){
    if(capacity < 0){
        printf("Initialized stack cannot have capacity smaller than 0 \n");
        exit(1);
    }

    s->capacity = capacity;
    s->size = 0;
    s->data = malloc(s->capacity * sizeof(int));

    if(s->data == NULL){
        printf("Failed to allocate memory\n");
        exit(1);
    }
}

void push(stack *s, int value){
    if(s->size == s->capacity){
        printf("Failed to push to stack due to no free space");
        return;
    }

    s->data[s->size++] = value;
}

int pop(stack *s){
    if(is_empty(s)){
        printf("Cannot pop value from empty stack");
        return;
    }

    return s->data[--s->size];
}

int peek(stack *s){
    if(is_empty(s)){
        printf("Cannot peek into empty stack");
        return;
    }

    return s->data[s->size - 1];
}

int is_empty(stack *s){
    return s->size == 0;
}

void free_stack(stack *s){
    free(s->data);
    s->data = NULL;
    s->capacity = 0;
    s->size = 0;
}
