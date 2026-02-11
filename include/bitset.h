#ifndef BITSET_H
#define BITSET_H

#include <stdint.h>
#include <stddef.h>
#include <stdint.h>

typedef struct{
    uint64_t * data;
    size_t bit_size;
} bitset;

int init_bitset(bitset *b, size_t size);
int set_bit(bitset *b, size_t idx);
int unset_bit(bitset *b, size_t idx);
int toggle_bit(bitset *b, size_t idx);
int get_bit(const bitset *b, size_t idx);
void drop_bitset(bitset *b);

#endif