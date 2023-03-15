#include "vector.h"

#include <string.h>

struct _vector
{
    void **data;
    size_t size;
    size_t incremental_size;
    size_t len;
};

vector vector_new()
{
    return vector_new_with_capacity(VECTOR_DEFAULT_CAPACITY, VECTOR_DEFAULT_CAPACITY);
}

vector vector_new_with_capacity(size_t size, size_t incremental_size)
{
    vector v = malloc(sizeof(struct _vector));

    if (v == NULL)
        return NULL;

    v->data = malloc(sizeof(void *) * size);
    v->size = size;
    v->incremental_size = incremental_size;
    v->len = 0;

    if (v->data == NULL)
    {
        free(v);
        return NULL;
    }

    memset(v->data, 0, sizeof(void *) * size);

    return v;
}

size_t vector_len(vector v)
{
    return v->len;
}

int vector_set(vector v, int pos, void *data)
{
    if ((size_t)abs(pos) > v->len)
        return -1;

    if (pos < 0)
        pos += v->len;

    v->data[pos] = data;

    return 0;
}

void *vector_get(vector v, int pos)
{
    if ((size_t)abs(pos) >= v->len)
        return (void *)-1;

    if (pos < 0)
        pos += v->len;

    return v->data[pos];
}

int vector_push(vector v, void *data)
{
    if (v->len == v->size)
    {
        v->size += v->incremental_size;
        v->data = realloc(v->data, v->size);

        if (v->data == NULL)
            return -1;
    }

    v->data[++v->len] = data;

    return 0;
}

void *vector_pop(vector v)
{
    if (v->len == 0)
        return (void *)-1;

    void *ptr = v->data[v->len - 1];

    v->len--;

    if (v->len <= v->size - (2 * v->incremental_size))
    {
        v->size -= v->incremental_size;
        v->data = realloc(v->data, v->size);

        if (v->data == NULL)
            return (void *)-1;
    }

    return ptr;
}

void vector_destroy(vector v)
{
    free(v);
}
