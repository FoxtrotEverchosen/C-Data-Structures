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
        int *new_data = realloc(v->data, v->capacity * 2 * sizeof(int));
        if (new_data == NULL) {
            printf("Failed to reallocate memory\n");
            exit(1);
        }
        v->data = new_data;
        v->capacity *= 2;
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

int get_vec_item(vec *v, int index){
    if(index < 0 || index > v->len - 1){
        printf("Requested index out of bounds of vec");
        exit(1);
    }

    return v->data[index];
}