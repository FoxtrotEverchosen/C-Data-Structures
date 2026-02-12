#ifndef TEST_FRAMEWORK_H
#define TEST_FRAMEWORK_H

#include <stdio.h>

static int tests_run = 0;
static int tests_failed = 0;

#define TEST(name) void name(void)

#define RUN_TEST(name) do {                     \
    printf("Running %s...\n", #name);           \
    tests_run++;                                \
    name();                                     \
} while (0)

#define ASSERT_TRUE(condition) do {                         \
    if (!(condition)) {                                     \
        printf("  Assertion failed: %s\n", #condition);     \
        tests_failed++;                                     \
        return;                                             \
    }                                                       \
} while (0)

#define ASSERT_EQ_INT(expected, actual) do {                \
    if ((expected) != (actual)) {                           \
        printf("  Expected %d, got %d\n",                   \
               (expected), (actual));                       \
        tests_failed++;                                     \
        return;                                             \
    }                                                       \
} while (0)

#define ASSERT_EQ_SIZE_T(expected, actual) do {             \
    if ((expected) != (actual)) {                           \
        printf("  Expected %zu, got %zu\n",                 \
               (expected), (actual));                       \
        tests_failed++;                                     \
        return;                                             \
    }                                                       \
} while (0)

static inline int TEST_SUMMARY(void) {
    printf("\n=================================\n");
    printf("Tests run: %d\n", tests_run);
    printf("Failures : %d\n", tests_failed);

    if (tests_failed == 0) {
        printf("ALL TESTS PASSED\n");
        return 0;
    } else {
        printf("SOME TESTS FAILED\n");
        return 1;
    }
}

#endif
