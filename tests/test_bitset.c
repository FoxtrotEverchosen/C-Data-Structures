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

int main(void) {
    RUN_TEST(test_set_bit);
    RUN_TEST(test_unset_bit);
    RUN_TEST(test_toggle_bit);

    return TEST_SUMMARY();
}