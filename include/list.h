#ifndef __LIST_H__
#define __LIST_H__

#include <stdlib.h>

typedef struct _list *list;

list list_new();
size_t list_len(list l);

int list_set(list l, int pos, void *data);
void *list_get(list l, int pos);
int list_push(list l, void *data);
void *list_pop(list l);

void list_destroy(list l);

#endif
