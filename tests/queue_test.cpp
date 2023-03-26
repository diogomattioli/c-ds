#include <gtest/gtest.h>

extern "C"
{
#include "queue.h"
}

TEST(queue, length_push3)
{
    queue q = queue_new();
    queue_push(q, NULL);
    queue_push(q, NULL);
    queue_push(q, NULL);

    EXPECT_EQ(queue_len(q), 3);

    queue_destroy(q);
}

TEST(queue, length_push3_pop1)
{
    queue q = queue_new();
    queue_push(q, NULL);
    queue_push(q, NULL);
    queue_push(q, NULL);
    queue_pop(q);

    EXPECT_EQ(queue_len(q), 2);

    queue_destroy(q);
}

TEST(queue, length_push3_pop3)
{
    queue q = queue_new();

    queue_push(q, NULL);
    queue_push(q, NULL);
    queue_push(q, NULL);

    queue_pop(q);
    queue_pop(q);
    queue_pop(q);

    EXPECT_EQ(queue_len(q), 0);

    queue_destroy(q);
}

TEST(queue, length_pop)
{
    queue q = queue_new();
    queue_pop(q);

    EXPECT_EQ(queue_len(q), 0);

    queue_destroy(q);
}

TEST(queue, push_pop)
{
    queue q = queue_new();
    queue_push(q, (void *)3);
    queue_push(q, (void *)2);
    queue_push(q, (void *)1);

    EXPECT_TRUE(queue_pop(q) == (void *)3);
    EXPECT_TRUE(queue_pop(q) == (void *)2);
    EXPECT_TRUE(queue_pop(q) == (void *)1);
    EXPECT_TRUE(queue_pop(q) == (void *)-1);

    queue_destroy(q);
}
