#ifndef VECTOR_H
#define VECTOR_H

typedef struct{
    unsigned int len;
    unsigned int capacity;
    int* data;
}vec;

int init_vec(vec *v);
int append_vec(vec *v, int data);
void drop_vec(vec *v);
unsigned int get_vec_len(vec *v);
int get_vec_item(vec *v, int index, int *out);
int concat_vec(vec *dest, vec *src);
int init_vec_with_capacity(vec *v, int capacity);

#endif