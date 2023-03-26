#include <gtest/gtest.h>

extern "C"
{
#include "list.h"
}

TEST(list, length_push3)
{
    list v = list_new();
    list_push_back(v, NULL);
    list_push_back(v, NULL);
    list_push_back(v, NULL);

    EXPECT_EQ(list_len(v), 3);

    list_destroy(v);
}

TEST(list, length_push3_pop1)
{
    list v = list_new();
    list_push_back(v, NULL);
    list_push_back(v, NULL);
    list_push_back(v, NULL);
    list_pop_back(v);

    EXPECT_EQ(list_len(v), 2);

    list_destroy(v);
}

TEST(list, length_push3_pop3)
{
    list v = list_new();

    list_push_back(v, NULL);
    list_push_back(v, NULL);
    list_push_back(v, NULL);

    list_pop_back(v);
    list_pop_back(v);
    list_pop_back(v);

    EXPECT_EQ(list_len(v), 0);

    list_destroy(v);
}

TEST(list, length_pop)
{
    list v = list_new();
    list_pop_back(v);

    EXPECT_EQ(list_len(v), 0);

    list_destroy(v);
}

TEST(list, set_positive)
{
    list v = list_new();
    list_push_back(v, NULL);
    list_push_back(v, NULL);
    list_push_back(v, NULL);

    list_set(v, 0, (void *)1);
    list_set(v, 1, (void *)2);
    list_set(v, 2, (void *)3);

    EXPECT_TRUE(list_get(v, 0) == (void *)1);
    EXPECT_TRUE(list_get(v, 1) == (void *)2);
    EXPECT_TRUE(list_get(v, 2) == (void *)3);

    list_destroy(v);
}

TEST(list, set_negative)
{
    list v = list_new();
    list_push_back(v, NULL);
    list_push_back(v, NULL);
    list_push_back(v, NULL);

    list_set(v, -3, (void *)1);
    list_set(v, -2, (void *)2);
    list_set(v, -1, (void *)3);

    EXPECT_TRUE(list_get(v, 0) == (void *)1);
    EXPECT_TRUE(list_get(v, 1) == (void *)2);
    EXPECT_TRUE(list_get(v, 2) == (void *)3);

    list_destroy(v);
}

TEST(list, set_out_of_bounds)
{
    list v = list_new();
    list_push_back(v, NULL);

    EXPECT_EQ(list_set(v, 10, NULL), -1);
    EXPECT_EQ(list_set(v, -10, NULL), -1);

    list_destroy(v);
}

TEST(list, get_positive)
{
    list v = list_new();
    list_push_back(v, NULL);
    list_push_back(v, NULL);
    list_push_back(v, NULL);

    list_set(v, 0, (void *)4);
    list_set(v, 1, (void *)5);
    list_set(v, 2, (void *)6);

    EXPECT_TRUE(list_get(v, 0) == (void *)4);
    EXPECT_TRUE(list_get(v, 1) == (void *)5);
    EXPECT_TRUE(list_get(v, 2) == (void *)6);

    list_destroy(v);
}

TEST(list, get_negative)
{
    list v = list_new();
    list_push_back(v, NULL);
    list_push_back(v, NULL);
    list_push_back(v, NULL);

    list_set(v, 0, (void *)1);
    list_set(v, 1, (void *)2);
    list_set(v, 2, (void *)3);

    EXPECT_TRUE(list_get(v, -3) == (void *)1);
    EXPECT_TRUE(list_get(v, -2) == (void *)2);
    EXPECT_TRUE(list_get(v, -1) == (void *)3);

    list_destroy(v);
}

TEST(list, get_out_of_bounds)
{
    list v = list_new();
    list_push_back(v, NULL);

    EXPECT_TRUE(list_get(v, 10) == (void *)-1);
    EXPECT_TRUE(list_get(v, -10) == (void *)-1);

    list_destroy(v);
}

TEST(list, push_front)
{
    list v = list_new();
    list_push_front(v, (void *)3);
    list_push_front(v, (void *)2);
    list_push_front(v, (void *)1);

    EXPECT_TRUE(list_get(v, 0) == (void *)1);
    EXPECT_TRUE(list_get(v, 1) == (void *)2);
    EXPECT_TRUE(list_get(v, 2) == (void *)3);

    list_destroy(v);
}

TEST(list, pop_front)
{
    list v = list_new();
    list_push_front(v, (void *)1);
    list_push_front(v, (void *)2);
    list_push_front(v, (void *)3);

    EXPECT_TRUE(list_pop_front(v) == (void *)3);
    EXPECT_TRUE(list_pop_front(v) == (void *)2);
    EXPECT_TRUE(list_pop_front(v) == (void *)1);
    EXPECT_TRUE(list_pop_front(v) == (void *)-1);

    list_destroy(v);
}

TEST(list, push_back)
{
    list v = list_new();
    list_push_back(v, (void *)1);
    list_push_back(v, (void *)2);
    list_push_back(v, (void *)3);

    EXPECT_TRUE(list_get(v, 0) == (void *)1);
    EXPECT_TRUE(list_get(v, 1) == (void *)2);
    EXPECT_TRUE(list_get(v, 2) == (void *)3);

    list_destroy(v);
}

TEST(list, pop_back)
{
    list v = list_new();
    list_push_back(v, (void *)1);
    list_push_back(v, (void *)2);
    list_push_back(v, (void *)3);

    EXPECT_TRUE(list_pop_back(v) == (void *)3);
    EXPECT_TRUE(list_pop_back(v) == (void *)2);
    EXPECT_TRUE(list_pop_back(v) == (void *)1);
    EXPECT_TRUE(list_pop_back(v) == (void *)-1);

    list_destroy(v);
}
