#include <stdlib.h>
#include <stdio.h>
#include "vector.h"

int init_vec(vec *v){
    unsigned int const DEFAULT_SIZE = 2;
    v->capacity = DEFAULT_SIZE;
    v->len = 0;
    v->data = malloc(DEFAULT_SIZE * sizeof(int));
    
    if(v->data == NULL){
        return 1;
    }

    return 0;
}

int init_vec_with_capacity(vec *v, size_t capacity){
    if(capacity <= 0){
        return 1;
    }

    v->capacity = capacity;
    v->len = 0;
    v->data = malloc(capacity * sizeof(int));
    
    if(v->data == NULL){
        return 1;
    }

    return 0;
}

int append_vec(vec *v, int value){
    if(v->len == v->capacity){
        int new_capacity = v->capacity == 0 ? 2 : v->capacity * 2;
        int *new_data = realloc(v->data, v->capacity * 2 * sizeof(int));
        if (new_data == NULL) {
            return 1;
        }
        v->data = new_data;
        v->capacity = new_capacity;
    }
    v->data[v->len++] = value;
    return 0;
}

int concat_vec(vec *dest, vec *src){
    size_t new_size = dest->len + src->len; 
    if(new_size > dest->capacity){
        int *new_data = realloc(dest->data, new_size * sizeof(int));
        
        if (new_data == NULL) {
                return 1;
        }

        dest->data = new_data;
        dest->capacity = new_size;
    }

    int* p_dest = dest->data + dest->len;
    int* p_src = src->data;
    
    for(size_t i=0; i<src->len; i++){
        *(p_dest + i) = *(p_src + i);
        dest->len++; 
    }
    
    return 0;
}

void drop_vec(vec *v){
    v->capacity = 0;
    v->len = 0;
    free(v->data);
    v->data = NULL;
}

size_t get_vec_len(vec *v){
    return v->len;
}

int get_vec_item(vec *v, size_t index, int *out){
    if(index > v->len - 1){
        return 1;
    }

    *out = v->data[index];
    return 0;
}