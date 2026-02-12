#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

#include "bitset.h"

int init_bitset(bitset *b, size_t size){
    if(size == 0) return 1;
    b->bit_size = size;
    
    size_t long_count = (size + 63) / 64;
    b->capacity = long_count;
    uint64_t *new_data = calloc(b->capacity, sizeof(uint64_t));
    
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
    /*
        This function returns -1 as an error value. Queried bit is returned as 0/1
    */
    if (idx >= b->bit_size) return -1;

    return (b->data[idx >> 6] & (1ULL << (idx & 63))) != 0;
}

size_t popcount(bitset *b){
    uint64_t sum = 0;

    for(size_t i=0; i < b->capacity; i++){
        sum += __builtin_popcountll(b->data[i]);
    }
    
    return sum;
}

bitset bitset_union(const bitset *b1, const bitset *b2){
    bitset new_bitset;
    size_t size = max(b1->bit_size, b2->bit_size);

    if (init_bitset(&new_bitset, size) != 0) {
        new_bitset.data = NULL;
        new_bitset.bit_size = 0;
        new_bitset.capacity = 0;
        return new_bitset;
    }

    if (b1->capacity == b2->capacity){    
        for(size_t i = 0; i < b1->capacity; i++){
            new_bitset.data[i] = b1->data[i] | b2->data[i];
        }
    }else{
        size_t min_cap = min(b1->capacity, b2->capacity);

        for(size_t i = 0; i < min_cap; i++){
            new_bitset.data[i] = b1->data[i] | b2->data[i];
        }

        for (size_t i = min_cap; i < new_bitset.capacity; i++){
            new_bitset.data[i] = b1->capacity > b2->capacity ? 
                                    b1->data[i] : 
                                    b2->data[i];
        }
    }

    return new_bitset;
}

void drop_bitset(bitset *b){
    free(b->data);
}