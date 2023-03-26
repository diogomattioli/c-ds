#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <stdlib.h>

typedef struct _list *list;

list list_new();
size_t list_len(list v);

int list_set(list v, int pos, void *data);
void *list_get(list v, int pos);
int list_push_front(list v, void *data);
void *list_pop_front(list v);
int list_push_back(list v, void *data);
void *list_pop_back(list v);

void list_destroy(list v);

#endif
