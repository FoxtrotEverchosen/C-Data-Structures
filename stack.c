#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

int init_stack(stack *s){
    s->capacity = 32;
    s->size = 0;
    s->data = malloc(s->capacity * sizeof(int));

    if(s->data == NULL){
        return 1;
    }

    return 0;
}

int init_stack_with_capacity(stack *s, int capacity){
    if(capacity <= 0){
        return 1;
    }

    s->capacity = capacity;
    s->size = 0;
    s->data = malloc(s->capacity * sizeof(int));

    if(s->data == NULL){
        return 1;
    }

    return 0;
}

int push(stack *s, int value){
    if(s->size == s->capacity){
        int new_capacity = s->capacity == 0 ? 2 : s->capacity * 2;
        int* new_data = realloc(s->data, new_capacity * sizeof(int));
        
        if(new_data == NULL){
            return 1;
        }
        
        s->capacity = new_capacity;
        s->data = new_data;
    }

    s->data[s->size++] = value;
    return 0;
}

int pop(stack *s, int *out){
    if(is_empty(s)){
        return 1;
    }

    *out = s->data[--s->size];

    if(s->size > 0 && s->size * 4 < s->capacity){
        int new_capacity = s->capacity / 2;

        int* new_data = realloc(s->data, new_capacity * sizeof(int));

        if(new_data != NULL){
            s->data = new_data;
            s->capacity = new_capacity;
        }
    }

    return 0;
}

int peek(stack *s, int *out){
    if(is_empty(s)){
        return 1;
    }

    *out = s->data[s->size - 1];
    return 0;
}

int is_empty(const stack *s){
    return s->size == 0;
}

void free_stack(stack *s){
    free(s->data);
    s->data = NULL;
    s->capacity = 0;
    s->size = 0;
}
