#include "test_framework.h"
#include "stack.h"

// To run all the tests
// gcc -Wall -Wextra -Iinclude -Itests tests/test_stack.c src/stack.c -o test_stack && ./test_stack

TEST(test_push_pop) {
    stack s;
    init_stack(&s);

    push(&s, 42);

    int out;
    pop(&s, &out);

    ASSERT_EQ_INT(42, out);

    free_stack(&s);
}

TEST(test_lifo_behavior) {
    stack s;
    init_stack(&s);

    push(&s, 1);
    push(&s, 2);
    push(&s, 3);

    int out;

    pop(&s, &out);
    ASSERT_EQ_INT(3, out);
    
    pop(&s, &out);
    ASSERT_EQ_INT(2, out);
    
    pop(&s, &out);
    ASSERT_EQ_INT(1, out);

    free_stack(&s);
}

TEST(test_empty_stack) {
    stack s;
    init_stack(&s);

    ASSERT_TRUE(is_empty(&s));

    free_stack(&s);
}

int main(void) {
    RUN_TEST(test_push_pop);
    RUN_TEST(test_lifo_behavior);
    RUN_TEST(test_empty_stack);

    return TEST_SUMMARY();
}
