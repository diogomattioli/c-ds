#include <gtest/gtest.h>

extern "C"
{
#include "stack.h"
}

TEST(stack, length_push3)
{
    stack s = stack_new();
    stack_push(s, NULL);
    stack_push(s, NULL);
    stack_push(s, NULL);

    EXPECT_EQ(stack_len(s), 3);

    stack_destroy(s);
}

TEST(stack, length_push3_pop1)
{
    stack s = stack_new();
    stack_push(s, NULL);
    stack_push(s, NULL);
    stack_push(s, NULL);
    stack_pop(s);

    EXPECT_EQ(stack_len(s), 2);

    stack_destroy(s);
}

TEST(stack, length_push3_pop3)
{
    stack s = stack_new();

    stack_push(s, NULL);
    stack_push(s, NULL);
    stack_push(s, NULL);

    stack_pop(s);
    stack_pop(s);
    stack_pop(s);

    EXPECT_EQ(stack_len(s), 0);

    stack_destroy(s);
}

TEST(stack, length_pop)
{
    stack s = stack_new();
    stack_pop(s);

    EXPECT_EQ(stack_len(s), 0);

    stack_destroy(s);
}

TEST(stack, push_pop)
{
    stack s = stack_new();
    stack_push(s, (void *)1);
    stack_push(s, (void *)2);
    stack_push(s, (void *)3);

    EXPECT_EQ((uintptr_t)stack_pop(s), 3);
    EXPECT_EQ((uintptr_t)stack_pop(s), 2);
    EXPECT_EQ((uintptr_t)stack_pop(s), 1);
    EXPECT_EQ((uintptr_t)stack_pop(s), -1);

    stack_destroy(s);
}
