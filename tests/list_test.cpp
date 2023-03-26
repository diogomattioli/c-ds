#include <gtest/gtest.h>

extern "C"
{
#include "list.h"
}

TEST(list, length_push3)
{
    list l = list_new();
    list_push_back(l, NULL);
    list_push_back(l, NULL);
    list_push_back(l, NULL);

    EXPECT_EQ(list_len(l), 3);

    list_destroy(l);
}

TEST(list, length_push3_pop1)
{
    list l = list_new();
    list_push_back(l, NULL);
    list_push_back(l, NULL);
    list_push_back(l, NULL);
    list_pop_back(l);

    EXPECT_EQ(list_len(l), 2);

    list_destroy(l);
}

TEST(list, length_push3_pop3)
{
    list l = list_new();

    list_push_back(l, NULL);
    list_push_back(l, NULL);
    list_push_back(l, NULL);

    list_pop_back(l);
    list_pop_back(l);
    list_pop_back(l);

    EXPECT_EQ(list_len(l), 0);

    list_destroy(l);
}

TEST(list, length_pop)
{
    list l = list_new();
    list_pop_back(l);

    EXPECT_EQ(list_len(l), 0);

    list_destroy(l);
}

TEST(list, insert_first)
{
    list l = list_new();
    list_push_back(l, (void *)1);
    list_push_back(l, (void *)2);
    list_push_back(l, (void *)3);

    list_insert(l, 0, (void *)0);

    EXPECT_TRUE(list_get(l, 0) == (void *)0);
    EXPECT_TRUE(list_get(l, 1) == (void *)1);
    EXPECT_TRUE(list_get(l, 2) == (void *)2);
    EXPECT_TRUE(list_get(l, 3) == (void *)3);

    list_destroy(l);
}

TEST(list, insert_first_negative)
{
    list l = list_new();
    list_push_back(l, (void *)1);
    list_push_back(l, (void *)2);
    list_push_back(l, (void *)3);

    list_insert(l, -3, (void *)0);

    EXPECT_TRUE(list_get(l, 0) == (void *)0);
    EXPECT_TRUE(list_get(l, 1) == (void *)1);
    EXPECT_TRUE(list_get(l, 2) == (void *)2);
    EXPECT_TRUE(list_get(l, 3) == (void *)3);

    list_destroy(l);
}

TEST(list, insert_last)
{
    list l = list_new();
    list_push_back(l, (void *)1);
    list_push_back(l, (void *)2);
    list_push_back(l, (void *)3);

    list_insert(l, 3, (void *)0);

    EXPECT_TRUE(list_get(l, 0) == (void *)1);
    EXPECT_TRUE(list_get(l, 1) == (void *)2);
    EXPECT_TRUE(list_get(l, 2) == (void *)3);
    EXPECT_TRUE(list_get(l, 3) == (void *)0);

    list_destroy(l);
}

TEST(list, insert_middle)
{
    list l = list_new();
    list_push_back(l, (void *)1);
    list_push_back(l, (void *)2);
    list_push_back(l, (void *)3);
    list_push_back(l, (void *)4);

    list_insert(l, 2, (void *)0);

    EXPECT_TRUE(list_get(l, 0) == (void *)1);
    EXPECT_TRUE(list_get(l, 1) == (void *)2);
    EXPECT_TRUE(list_get(l, 2) == (void *)0);
    EXPECT_TRUE(list_get(l, 3) == (void *)3);
    EXPECT_TRUE(list_get(l, 4) == (void *)4);

    list_destroy(l);
}

TEST(list, insert_middle_negative)
{
    list l = list_new();
    list_push_back(l, (void *)1);
    list_push_back(l, (void *)2);
    list_push_back(l, (void *)3);
    list_push_back(l, (void *)4);

    list_insert(l, -2, (void *)0);

    EXPECT_TRUE(list_get(l, 0) == (void *)1);
    EXPECT_TRUE(list_get(l, 1) == (void *)2);
    EXPECT_TRUE(list_get(l, 2) == (void *)0);
    EXPECT_TRUE(list_get(l, 3) == (void *)3);
    EXPECT_TRUE(list_get(l, 4) == (void *)4);

    list_destroy(l);
}

TEST(list, remove_first)
{
    list l = list_new();
    list_push_back(l, (void *)1);
    list_push_back(l, (void *)2);
    list_push_back(l, (void *)3);

    list_remove(l, 0);

    EXPECT_TRUE(list_get(l, 0) == (void *)2);
    EXPECT_TRUE(list_get(l, 1) == (void *)3);

    list_destroy(l);
}

TEST(list, remove_first_negative)
{
    list l = list_new();
    list_push_back(l, (void *)1);
    list_push_back(l, (void *)2);
    list_push_back(l, (void *)3);

    list_remove(l, -3);

    EXPECT_TRUE(list_get(l, 0) == (void *)2);
    EXPECT_TRUE(list_get(l, 1) == (void *)3);

    list_destroy(l);
}

TEST(list, remove_last)
{
    list l = list_new();
    list_push_back(l, (void *)1);
    list_push_back(l, (void *)2);
    list_push_back(l, (void *)3);

    list_remove(l, 3);

    EXPECT_TRUE(list_get(l, 0) == (void *)1);
    EXPECT_TRUE(list_get(l, 1) == (void *)2);
    EXPECT_TRUE(list_get(l, 2) == (void *)-1);

    list_destroy(l);
}

TEST(list, remove_middle)
{
    list l = list_new();
    list_push_back(l, (void *)1);
    list_push_back(l, (void *)2);
    list_push_back(l, (void *)3);

    list_remove(l, 1);

    EXPECT_TRUE(list_get(l, 0) == (void *)1);
    EXPECT_TRUE(list_get(l, 1) == (void *)3);

    list_destroy(l);
}

TEST(list, remove_middle_negative)
{
    list l = list_new();
    list_push_back(l, (void *)1);
    list_push_back(l, (void *)2);
    list_push_back(l, (void *)3);

    list_remove(l, -2);

    EXPECT_TRUE(list_get(l, 0) == (void *)1);
    EXPECT_TRUE(list_get(l, 1) == (void *)3);

    list_destroy(l);
}

TEST(list, set_positive)
{
    list l = list_new();
    list_push_back(l, NULL);
    list_push_back(l, NULL);
    list_push_back(l, NULL);

    list_set(l, 0, (void *)1);
    list_set(l, 1, (void *)2);
    list_set(l, 2, (void *)3);

    EXPECT_TRUE(list_get(l, 0) == (void *)1);
    EXPECT_TRUE(list_get(l, 1) == (void *)2);
    EXPECT_TRUE(list_get(l, 2) == (void *)3);

    list_destroy(l);
}

TEST(list, set_negative)
{
    list l = list_new();
    list_push_back(l, NULL);
    list_push_back(l, NULL);
    list_push_back(l, NULL);

    list_set(l, -3, (void *)1);
    list_set(l, -2, (void *)2);
    list_set(l, -1, (void *)3);

    EXPECT_TRUE(list_get(l, 0) == (void *)1);
    EXPECT_TRUE(list_get(l, 1) == (void *)2);
    EXPECT_TRUE(list_get(l, 2) == (void *)3);

    list_destroy(l);
}

TEST(list, set_out_of_bounds)
{
    list l = list_new();
    list_push_back(l, NULL);

    EXPECT_EQ(list_set(l, 10, NULL), -1);
    EXPECT_EQ(list_set(l, -10, NULL), -1);

    list_destroy(l);
}

TEST(list, get_positive)
{
    list l = list_new();
    list_push_back(l, NULL);
    list_push_back(l, NULL);
    list_push_back(l, NULL);

    list_set(l, 0, (void *)4);
    list_set(l, 1, (void *)5);
    list_set(l, 2, (void *)6);

    EXPECT_TRUE(list_get(l, 0) == (void *)4);
    EXPECT_TRUE(list_get(l, 1) == (void *)5);
    EXPECT_TRUE(list_get(l, 2) == (void *)6);

    list_destroy(l);
}

TEST(list, get_negative)
{
    list l = list_new();
    list_push_back(l, NULL);
    list_push_back(l, NULL);
    list_push_back(l, NULL);

    list_set(l, 0, (void *)1);
    list_set(l, 1, (void *)2);
    list_set(l, 2, (void *)3);

    EXPECT_TRUE(list_get(l, -3) == (void *)1);
    EXPECT_TRUE(list_get(l, -2) == (void *)2);
    EXPECT_TRUE(list_get(l, -1) == (void *)3);

    list_destroy(l);
}

TEST(list, get_out_of_bounds)
{
    list l = list_new();
    list_push_back(l, NULL);

    EXPECT_TRUE(list_get(l, 10) == (void *)-1);
    EXPECT_TRUE(list_get(l, -10) == (void *)-1);

    list_destroy(l);
}

TEST(list, push_front)
{
    list l = list_new();
    list_push_front(l, (void *)3);
    list_push_front(l, (void *)2);
    list_push_front(l, (void *)1);

    EXPECT_TRUE(list_get(l, 0) == (void *)1);
    EXPECT_TRUE(list_get(l, 1) == (void *)2);
    EXPECT_TRUE(list_get(l, 2) == (void *)3);

    list_destroy(l);
}

TEST(list, pop_front)
{
    list l = list_new();
    list_push_front(l, (void *)1);
    list_push_front(l, (void *)2);
    list_push_front(l, (void *)3);

    EXPECT_TRUE(list_pop_front(l) == (void *)3);
    EXPECT_TRUE(list_pop_front(l) == (void *)2);
    EXPECT_TRUE(list_pop_front(l) == (void *)1);
    EXPECT_TRUE(list_pop_front(l) == (void *)-1);

    list_destroy(l);
}

TEST(list, push_back)
{
    list l = list_new();
    list_push_back(l, (void *)1);
    list_push_back(l, (void *)2);
    list_push_back(l, (void *)3);

    EXPECT_TRUE(list_get(l, 0) == (void *)1);
    EXPECT_TRUE(list_get(l, 1) == (void *)2);
    EXPECT_TRUE(list_get(l, 2) == (void *)3);

    list_destroy(l);
}

TEST(list, pop_back)
{
    list l = list_new();
    list_push_back(l, (void *)1);
    list_push_back(l, (void *)2);
    list_push_back(l, (void *)3);

    EXPECT_TRUE(list_pop_back(l) == (void *)3);
    EXPECT_TRUE(list_pop_back(l) == (void *)2);
    EXPECT_TRUE(list_pop_back(l) == (void *)1);
    EXPECT_TRUE(list_pop_back(l) == (void *)-1);

    list_destroy(l);
}
