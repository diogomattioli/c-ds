#include <gtest/gtest.h>

extern "C"
{
#include "vector.h"
}

TEST(vector, length_push3)
{
    vector v = vector_new();
    vector_push(v, NULL);
    vector_push(v, NULL);
    vector_push(v, NULL);

    EXPECT_EQ(vector_len(v), 3);

    vector_destroy(v);
}

TEST(vector, length_push3_pop1)
{
    vector v = vector_new();
    vector_push(v, NULL);
    vector_push(v, NULL);
    vector_push(v, NULL);
    vector_pop(v);

    EXPECT_EQ(vector_len(v), 2);

    vector_destroy(v);
}

TEST(vector, length_push3_pop3)
{
    vector v = vector_new();

    vector_push(v, NULL);
    vector_push(v, NULL);
    vector_push(v, NULL);

    vector_pop(v);
    vector_pop(v);
    vector_pop(v);

    EXPECT_EQ(vector_len(v), 0);

    vector_destroy(v);
}

TEST(vector, length_pop)
{
    vector v = vector_new();
    vector_pop(v);

    EXPECT_EQ(vector_len(v), 0);

    vector_destroy(v);
}

TEST(vector, set_positive)
{
    vector v = vector_new();
    vector_push(v, NULL);
    vector_push(v, NULL);
    vector_push(v, NULL);

    vector_set(v, 0, (void *)1);
    vector_set(v, 1, (void *)2);
    vector_set(v, 2, (void *)3);

    EXPECT_TRUE(vector_get(v, 0) == (void *)1);
    EXPECT_TRUE(vector_get(v, 1) == (void *)2);
    EXPECT_TRUE(vector_get(v, 2) == (void *)3);

    vector_destroy(v);
}

TEST(vector, set_negative)
{
    vector v = vector_new();
    vector_push(v, NULL);
    vector_push(v, NULL);
    vector_push(v, NULL);

    vector_set(v, -3, (void *)1);
    vector_set(v, -2, (void *)2);
    vector_set(v, -1, (void *)3);

    EXPECT_TRUE(vector_get(v, 0) == (void *)1);
    EXPECT_TRUE(vector_get(v, 1) == (void *)2);
    EXPECT_TRUE(vector_get(v, 2) == (void *)3);

    vector_destroy(v);
}

TEST(vector, set_out_of_bounds)
{
    vector v = vector_new();
    vector_push(v, NULL);

    EXPECT_EQ(vector_set(v, 10, NULL), -1);
    EXPECT_EQ(vector_set(v, -10, NULL), -1);

    vector_destroy(v);
}

TEST(vector, get_positive)
{
    vector v = vector_new();
    vector_push(v, NULL);
    vector_push(v, NULL);
    vector_push(v, NULL);

    vector_set(v, 0, (void *)4);
    vector_set(v, 1, (void *)5);
    vector_set(v, 2, (void *)6);

    EXPECT_TRUE(vector_get(v, 0) == (void *)4);
    EXPECT_TRUE(vector_get(v, 1) == (void *)5);
    EXPECT_TRUE(vector_get(v, 2) == (void *)6);

    vector_destroy(v);
}

TEST(vector, get_negative)
{
    vector v = vector_new();
    vector_push(v, NULL);
    vector_push(v, NULL);
    vector_push(v, NULL);

    vector_set(v, 0, (void *)1);
    vector_set(v, 1, (void *)2);
    vector_set(v, 2, (void *)3);

    EXPECT_TRUE(vector_get(v, -3) == (void *)1);
    EXPECT_TRUE(vector_get(v, -2) == (void *)2);
    EXPECT_TRUE(vector_get(v, -1) == (void *)3);

    vector_destroy(v);
}

TEST(vector, get_out_of_bounds)
{
    vector v = vector_new();
    vector_push(v, NULL);

    EXPECT_TRUE(vector_get(v, 10) == (void *)-1);
    EXPECT_TRUE(vector_get(v, -10) == (void *)-1);

    vector_destroy(v);
}

TEST(vector, push)
{
    vector v = vector_new();
    vector_push(v, (void *)1);
    vector_push(v, (void *)2);
    vector_push(v, (void *)3);

    EXPECT_TRUE(vector_get(v, 0) == (void *)1);
    EXPECT_TRUE(vector_get(v, 1) == (void *)2);
    EXPECT_TRUE(vector_get(v, 2) == (void *)3);

    vector_destroy(v);
}

TEST(vector, push_with_capacity)
{
    vector v = vector_new_with_capacity(1, 1);
    vector_push(v, (void *)1);
    vector_push(v, (void *)2);
    vector_push(v, (void *)3);

    EXPECT_TRUE(vector_get(v, 0) == (void *)1);
    EXPECT_TRUE(vector_get(v, 1) == (void *)2);
    EXPECT_TRUE(vector_get(v, 2) == (void *)3);

    vector_destroy(v);
}

TEST(vector, push_zero_start)
{
    vector v = vector_new_with_capacity(0, 1);
    vector_push(v, (void *)1);
    vector_push(v, (void *)2);
    vector_push(v, (void *)3);

    EXPECT_TRUE(vector_get(v, 0) == (void *)1);
    EXPECT_TRUE(vector_get(v, 1) == (void *)2);
    EXPECT_TRUE(vector_get(v, 2) == (void *)3);

    vector_destroy(v);
}

TEST(vector, pop)
{
    vector v = vector_new();
    vector_push(v, (void *)1);
    vector_push(v, (void *)2);
    vector_push(v, (void *)3);

    EXPECT_TRUE(vector_pop(v) == (void *)3);
    EXPECT_TRUE(vector_pop(v) == (void *)2);
    EXPECT_TRUE(vector_pop(v) == (void *)1);
    EXPECT_TRUE(vector_pop(v) == (void *)-1);

    vector_destroy(v);
}

TEST(vector, pop_with_capacity)
{
    vector v = vector_new_with_capacity(1, 1);
    vector_push(v, (void *)1);
    vector_push(v, (void *)2);
    vector_push(v, (void *)3);

    EXPECT_TRUE(vector_pop(v) == (void *)3);
    EXPECT_TRUE(vector_pop(v) == (void *)2);
    EXPECT_TRUE(vector_pop(v) == (void *)1);
    EXPECT_TRUE(vector_pop(v) == (void *)-1);

    vector_destroy(v);
}

TEST(vector, pop_zero_start)
{
    vector v = vector_new_with_capacity(0, 1);
    vector_push(v, (void *)1);
    vector_push(v, (void *)2);
    vector_push(v, (void *)3);

    EXPECT_TRUE(vector_pop(v) == (void *)3);
    EXPECT_TRUE(vector_pop(v) == (void *)2);
    EXPECT_TRUE(vector_pop(v) == (void *)1);
    EXPECT_TRUE(vector_pop(v) == (void *)-1);

    vector_destroy(v);
}
