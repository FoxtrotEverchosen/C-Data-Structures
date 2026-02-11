#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

#include "bitset.h"

int init_bitset(bitset *b, size_t size){
    if(size == 0) return 1;
    b->bit_size = size;
    
    size_t long_count = (size + 63) / 64;
    uint64_t *new_data = calloc(long_count, sizeof(uint64_t));
    
    if(new_data == NULL){
        return 1;
    }
    
    b->data = new_data;
    return 0;
}

int set_bit(bitset *b, size_t idx){
    if (idx >= b->bit_size) return 1;
    // idx >> 6 <-> idx / 64
    // idx & 63 <-> idx % 64 

    b->data[idx >> 6] |= (1ULL << (idx & 63));
    return 0;
}

int unset_bit(bitset *b, size_t idx){
    if (idx >= b->bit_size) return 1;
    
    b->data[idx >> 6] &= ~(1ULL << (idx & 63));
    return 0;
}

int toggle_bit(bitset *b, size_t idx){
    if (idx >= b->bit_size) return 1;

    b->data[idx >> 6] ^= (1ULL << (idx & 63));
    return 0;
}

int get_bit(const bitset *b, size_t idx){
    if (idx >= b->bit_size) return -1;

    return (b->data[idx >> 6] & (1ULL << (idx & 63))) != 0;
}

void drop_bitset(bitset *b){
    free(b->data);
}