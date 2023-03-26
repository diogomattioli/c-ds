#include "queue.h"
#include "list.h"

struct _queue
{
    list l;
};

queue queue_new()
{
    queue q = malloc(sizeof(struct _queue));

    if (q == NULL)
        return NULL;

    q->l = list_new();

    return q;
}

size_t queue_len(queue q)
{
    return list_len(q->l);
}

int queue_push(queue q, void *data)
{
    return list_push_front(q->l, data);
}

void *queue_pop(queue q)
{
    return list_pop_back(q->l);
}

void queue_destroy(queue q)
{
    list_destroy(q->l);
    free(q);
}
