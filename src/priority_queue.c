#include "priority_queue.h"
#include "vector.h"

struct _priority_queue
{
    vector v;
    int (*cmp)(void *a, void *b);
};

priority_queue priority_queue_new(int (*cmp)(void *a, void *b))
{
    priority_queue pq = malloc(sizeof(struct _priority_queue));

    if (pq == NULL)
        return NULL;

    pq->v = vector_new();
    pq->cmp = cmp;

    return pq;
}

size_t priority_queue_len(priority_queue pq)
{
    return vector_len(pq->v);
}

static void priority_queue_reorder(priority_queue pq, size_t pos)
{
    size_t len = priority_queue_len(pq);
    if (pos >= len)
        return;

    size_t parent = (pos - 1) / 2;
    size_t left = (2 * pos) + 1;
    size_t right = (2 * pos) + 2;

    void *ptr_pos = vector_get(pq->v, pos);

    if (parent < len && pos > 0)
    {
        void *ptr_parent = vector_get(pq->v, parent);

        if (pq->cmp(ptr_pos, ptr_parent) > 0)
        {
            vector_set(pq->v, parent, ptr_pos);
            vector_set(pq->v, pos, ptr_parent);

            priority_queue_reorder(pq, parent);

            return;
        }
    }

    void *ptr_left = left < len ? vector_get(pq->v, left) : NULL;
    void *ptr_right = right < len ? vector_get(pq->v, right) : NULL;

    if (ptr_left != NULL && (ptr_right == NULL || pq->cmp(ptr_left, ptr_right) > 0) && pq->cmp(ptr_pos, ptr_left) <= 0)
    {
        vector_set(pq->v, left, ptr_pos);
        vector_set(pq->v, pos, ptr_left);

        priority_queue_reorder(pq, left);

        return;
    }

    if (ptr_right != NULL && pq->cmp(ptr_pos, ptr_right) <= 0)
    {
        vector_set(pq->v, right, ptr_pos);
        vector_set(pq->v, pos, ptr_right);

        priority_queue_reorder(pq, right);

        return;
    }
}

int priority_queue_push(priority_queue pq, void *data)
{
    if (vector_push(pq->v, data) == -1)
        return -1;

    priority_queue_reorder(pq, priority_queue_len(pq) - 1);

    return 0;
}

void *priority_queue_pop(priority_queue pq)
{
    void *ptr = vector_get(pq->v, 0);

    void *last = vector_pop(pq->v);
    if (last == (void *)-1)
        return (void *)-1;

    if (priority_queue_len(pq) > 0)
    {
        if (vector_set(pq->v, 0, last) == -1)
            return (void *)-1;

        priority_queue_reorder(pq, 0);
    }

    return ptr;
}

void *priority_queue_top(priority_queue pq)
{
    if (priority_queue_len(pq) == 0)
        return (void *)-1;

    return vector_get(pq->v, 0);
}

void priority_queue_destroy(priority_queue pq)
{
    vector_destroy(pq->v);
    free(pq);
}
