#include "test_framework.h"
#include "bitset.h"

// To run all the tests
// gcc -Wall -Wextra -Iinclude -Itests tests/test_bitset.c src/bitset.c -o test_bitset && ./test_bitset

TEST(test_set_bit) {
    bitset b;
    init_bitset(&b, 128);
    
    set_bit(&b, 64);
    ASSERT_EQ_INT(1, get_bit(&b, 64));
    
    drop_bitset(&b);
}

TEST(test_unset_bit){
    bitset b;
    init_bitset(&b, 128);
    
    set_bit(&b, 64);
    ASSERT_EQ_INT(1, get_bit(&b, 64));
    
    unset_bit(&b, 64);
    ASSERT_EQ_INT(0, get_bit(&b, 64));
    
    drop_bitset(&b);
}

TEST(test_toggle_bit){
    bitset b;
    init_bitset(&b, 128);
    
    toggle_bit(&b, 64);
    ASSERT_EQ_INT(1, get_bit(&b, 64));
    
    toggle_bit(&b, 64);
    ASSERT_EQ_INT(0, get_bit(&b, 64));
    
    toggle_bit(&b, 64);
    ASSERT_EQ_INT(1, get_bit(&b, 64));

    drop_bitset(&b);
}

TEST(test_popcount) {
    bitset b;
    init_bitset(&b, 128);

    ASSERT_EQ_SIZE_T( (size_t) 0, popcount(&b));
    
    for(int i = 0; i < 10; i++){
        set_bit(&b, i*2);
    }
    
    ASSERT_EQ_SIZE_T( (size_t) 10, popcount(&b));
    
    drop_bitset(&b);
}

TEST(test_union) {
    bitset b1;
    init_bitset(&b1, 128);

    bitset b2;
    init_bitset(&b2, 256);

    for(int i = 0; i < 10; i++){
        set_bit(&b1, i*2);
    }

    for(int i = 0; i < 10; i++){
        set_bit(&b2, 255 - i);
    }

    bitset u_bistet = bitset_union(&b1, &b2);
    ASSERT_EQ_SIZE_T( (size_t) 20, popcount(&u_bistet));

    bitset b4;
    init_bitset(&b4, 128);

    bitset b5;
    init_bitset(&b5, 256);

    bitset u_bistet2 = bitset_union(&b4, &b5);
    ASSERT_EQ_SIZE_T( (size_t) 0, popcount(&u_bistet2));

    for(int i = 0; i < 10; i++){
        set_bit(&b4, i*2);
        set_bit(&b5, i*2);
    }
    
    bitset u_bistet3 = bitset_union(&b4, &b5);
    ASSERT_EQ_SIZE_T( (size_t) 10, popcount(&u_bistet3));

    drop_bitset(&b1);
    drop_bitset(&b2);
    drop_bitset(&u_bistet);
    drop_bitset(&b4);
    drop_bitset(&b5);
    drop_bitset(&u_bistet2);
    drop_bitset(&u_bistet3);
}



int main(void) {
    RUN_TEST(test_set_bit);
    RUN_TEST(test_unset_bit);
    RUN_TEST(test_toggle_bit);
    RUN_TEST(test_popcount);
    RUN_TEST(test_union);

    return TEST_SUMMARY();
}