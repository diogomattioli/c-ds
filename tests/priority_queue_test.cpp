#include <gtest/gtest.h>

extern "C"
{
#include "priority_queue.h"
}

static int test_cmp_max(void *a, void *b)
{
    return a > b ? 1 : 0;
}

static int test_cmp_min(void *a, void *b)
{
    return a < b ? 1 : 0;
}

TEST(priority_queue, length_push3)
{
    priority_queue pq = priority_queue_new(test_cmp_max);
    priority_queue_push(pq, NULL);
    priority_queue_push(pq, NULL);
    priority_queue_push(pq, NULL);

    EXPECT_EQ(priority_queue_len(pq), 3);

    priority_queue_destroy(pq);
}

TEST(priority_queue, length_push3_pop1)
{
    priority_queue pq = priority_queue_new(test_cmp_max);
    priority_queue_push(pq, NULL);
    priority_queue_push(pq, NULL);
    priority_queue_push(pq, NULL);
    priority_queue_pop(pq);

    EXPECT_EQ(priority_queue_len(pq), 2);

    priority_queue_destroy(pq);
}

TEST(priority_queue, length_push3_pop3)
{
    priority_queue pq = priority_queue_new(test_cmp_max);

    priority_queue_push(pq, NULL);
    priority_queue_push(pq, NULL);
    priority_queue_push(pq, NULL);

    priority_queue_pop(pq);
    priority_queue_pop(pq);
    priority_queue_pop(pq);

    EXPECT_EQ(priority_queue_len(pq), 0);

    priority_queue_destroy(pq);
}

TEST(priority_queue, length_pop)
{
    priority_queue pq = priority_queue_new(test_cmp_max);
    priority_queue_pop(pq);

    EXPECT_EQ(priority_queue_len(pq), 0);

    priority_queue_destroy(pq);
}

TEST(priority_queue, pop_max)
{
    priority_queue pq = priority_queue_new(test_cmp_max);
    priority_queue_push(pq, (void *)3);
    priority_queue_push(pq, (void *)2);
    priority_queue_push(pq, (void *)1);

    EXPECT_EQ((uintptr_t)priority_queue_pop(pq), 3);
    EXPECT_EQ((uintptr_t)priority_queue_pop(pq), 2);
    EXPECT_EQ((uintptr_t)priority_queue_pop(pq), 1);
    EXPECT_EQ((uintptr_t)priority_queue_pop(pq), -1);

    priority_queue_destroy(pq);
}

TEST(priority_queue, pop_max_random)
{
    priority_queue pq = priority_queue_new(test_cmp_max);
    priority_queue_push(pq, (void *)5);
    priority_queue_push(pq, (void *)9);
    priority_queue_push(pq, (void *)3);
    priority_queue_push(pq, (void *)5);
    priority_queue_push(pq, (void *)7);

    EXPECT_EQ((uintptr_t)priority_queue_pop(pq), 9);
    EXPECT_EQ((uintptr_t)priority_queue_pop(pq), 7);
    EXPECT_EQ((uintptr_t)priority_queue_pop(pq), 5);
    EXPECT_EQ((uintptr_t)priority_queue_pop(pq), 5);
    EXPECT_EQ((uintptr_t)priority_queue_pop(pq), 3);
    EXPECT_EQ((uintptr_t)priority_queue_pop(pq), -1);

    priority_queue_destroy(pq);
}

TEST(priority_queue, pop_max_loop)
{
    priority_queue pq = priority_queue_new(test_cmp_max);

    for (int i = 0; i < 100; i++)
        priority_queue_push(pq, (void *)(size_t)rand());

    uintptr_t last = -1;
    for (int i = 0; i < 100; i++)
    {
        uintptr_t value = (uintptr_t)priority_queue_pop(pq);
        EXPECT_LT(value, last);
        last = value;
    }

    EXPECT_EQ((uintptr_t)priority_queue_pop(pq), -1);

    priority_queue_destroy(pq);
}

TEST(priority_queue, pop_min)
{
    priority_queue pq = priority_queue_new(test_cmp_min);
    priority_queue_push(pq, (void *)3);
    priority_queue_push(pq, (void *)2);
    priority_queue_push(pq, (void *)1);

    EXPECT_EQ((uintptr_t)priority_queue_pop(pq), 1);
    EXPECT_EQ((uintptr_t)priority_queue_pop(pq), 2);
    EXPECT_EQ((uintptr_t)priority_queue_pop(pq), 3);
    EXPECT_EQ((uintptr_t)priority_queue_pop(pq), -1);

    priority_queue_destroy(pq);
}

TEST(priority_queue, pop_min_random)
{
    priority_queue pq = priority_queue_new(test_cmp_min);
    priority_queue_push(pq, (void *)5);
    priority_queue_push(pq, (void *)9);
    priority_queue_push(pq, (void *)3);
    priority_queue_push(pq, (void *)5);
    priority_queue_push(pq, (void *)7);

    EXPECT_EQ((uintptr_t)priority_queue_pop(pq), 3);
    EXPECT_EQ((uintptr_t)priority_queue_pop(pq), 5);
    EXPECT_EQ((uintptr_t)priority_queue_pop(pq), 5);
    EXPECT_EQ((uintptr_t)priority_queue_pop(pq), 7);
    EXPECT_EQ((uintptr_t)priority_queue_pop(pq), 9);
    EXPECT_EQ((uintptr_t)priority_queue_pop(pq), -1);

    priority_queue_destroy(pq);
}

TEST(priority_queue, pop_min_loop)
{
    priority_queue pq = priority_queue_new(test_cmp_min);

    for (int i = 0; i < 100; i++)
        priority_queue_push(pq, (void *)(size_t)rand());

    uintptr_t last = 0;
    for (int i = 0; i < 100; i++)
    {
        uintptr_t value = (uintptr_t)priority_queue_pop(pq);
        EXPECT_GT(value, last);
        last = value;
    }

    EXPECT_EQ((uintptr_t)priority_queue_pop(pq), -1);

    priority_queue_destroy(pq);
}

TEST(priority_queue, top_max)
{
    priority_queue pq = priority_queue_new(test_cmp_max);
    priority_queue_push(pq, (void *)1);
    priority_queue_push(pq, (void *)3);
    priority_queue_push(pq, (void *)2);

    EXPECT_EQ((uintptr_t)priority_queue_top(pq), 3);

    priority_queue_destroy(pq);
}

TEST(priority_queue, top_min)
{
    priority_queue pq = priority_queue_new(test_cmp_min);
    priority_queue_push(pq, (void *)3);
    priority_queue_push(pq, (void *)2);
    priority_queue_push(pq, (void *)1);

    EXPECT_EQ((uintptr_t)priority_queue_top(pq), 1);

    priority_queue_destroy(pq);
}
