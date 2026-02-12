#ifndef VECTOR_H
#define VECTOR_H

typedef struct{
    size_t len;
    size_t capacity;
    int* data;
}vec;

int init_vec(vec *v);
int append_vec(vec *v, int data);
void drop_vec(vec *v);
size_t get_vec_len(vec *v);
int get_vec_item(vec *v, size_t index, int *out);
int concat_vec(vec *dest, vec *src);
int init_vec_with_capacity(vec *v, size_t capacity);

#endif