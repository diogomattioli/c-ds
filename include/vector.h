#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <stdlib.h>

#define VECTOR_DEFAULT_CAPACITY 25

typedef struct _vector *vector;

vector vector_new();
vector vector_new_with_capacity(size_t size, size_t incremental_size);
size_t vector_len(vector v);

int vector_set(vector v, int pos, void *data);
void *vector_get(vector v, int pos);
int vector_push(vector v, void *data);
void *vector_pop(vector v);

void vector_destroy(vector v);

#endif
