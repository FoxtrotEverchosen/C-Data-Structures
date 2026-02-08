#include <stdlib.h>
#include <stdio.h>
#include "vector.h"

void new_vec(vec *v){
    unsigned int const DEFAULT_SIZE = 2;
    v->capacity = DEFAULT_SIZE;
    v->len = 0;
    v->data = (int *) malloc(DEFAULT_SIZE * sizeof(int));
    
    if(v->data == NULL){
        printf("Failed to allocate memory\n");
        exit(1);
    }
}

void new_vec_with_capacity(vec *v, int capacity){
    v->capacity = capacity;
    v->len = 0;
    v->data = (int *) malloc(capacity * sizeof(int));
    
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

void concat_vec(vec *dest, vec *src){
    int new_size = dest->len + src->len; 
    if(new_size > dest->capacity){
        int *new_data = realloc(dest->data, new_size * sizeof(int));
        
        if (new_data == NULL) {
                printf("Failed to reallocate memory\n");
                exit(1);
        }

        dest->data = new_data;
    }

    int* p_dest = dest->data + dest->len;
    int* p_src = src->data;
    
    for(int i=0; i<src->len; i++){
        *(p_dest + i) = *(p_src + i);
        dest->len++; 
    }
    dest->capacity = new_size;
    
    drop_vec(src);
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