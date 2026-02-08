#include <stdlib.h>
#include <stdio.h>
#include "vector.h"

void new_vec(vec *v){
    unsigned int DEFAULT_SIZE = 2;
    v->capacity = DEFAULT_SIZE;
    v->len = 0;
    v->data = (int *) malloc(DEFAULT_SIZE * sizeof(int));
    
    if(v->data == NULL){
        printf("Failed to allocate memory\n");
        exit(1);
    }
}

void append_vec(vec *v, int value){
    if(v->len == v->capacity){
        realloc(v->data, v->capacity * 2 * sizeof(int));
    }

    v->data[v->len++] = value;
}

void drop_vec(vec *v){
    v->capacity = 0;
    v->len = 0;
    free(v->data);
    v->data = NULL;
}

unsigned int get_vec_len(vec *v){
    return v->len;
}