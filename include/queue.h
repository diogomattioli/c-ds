#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdlib.h>

typedef struct _queue *queue;

queue queue_new();
size_t queue_len(queue q);

int queue_push(queue q, void *data);
void *queue_pop(queue q);

void queue_destroy(queue q);

#endif
