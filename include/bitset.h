#ifndef BITSET_H
#define BITSET_H

#include <stdint.h>
#include <stddef.h>

typedef struct{
    uint64_t * data;
    size_t capacity;
    size_t bit_size;
} bitset;

int init_bitset(bitset *b, size_t size);
int set_bit(bitset *b, size_t idx);
int unset_bit(bitset *b, size_t idx);
int toggle_bit(bitset *b, size_t idx);
int get_bit(const bitset *b, size_t idx);
size_t popcount(bitset *b);
bitset bitset_union(const bitset *b1, const bitset *b2);
void drop_bitset(bitset *b);

#endif