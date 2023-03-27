#ifndef __PRIORITY_QUEUE_H__
#define __PRIORITY_QUEUE_H__

#include <stdlib.h>

typedef struct _priority_queue *priority_queue;

priority_queue priority_queue_new(int (*cmp)(void *a, void *b));
size_t priority_queue_len(priority_queue pq);

int priority_queue_push(priority_queue pq, void *data);
void *priority_queue_pop(priority_queue pq);
void *priority_queue_top(priority_queue pq);

void priority_queue_destroy(priority_queue pq);

#endif
