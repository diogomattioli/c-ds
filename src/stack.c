#include "stack.h"
#include "vector.h"

struct _stack
{
    vector v;
};

stack stack_new()
{
    stack s = malloc(sizeof(struct _stack));

    if (s == NULL)
        return NULL;

    s->v = vector_new();

    return s;
}

size_t stack_len(stack s)
{
    return vector_len(s->v);
}

int stack_push(stack s, void *data)
{
    return vector_push(s->v, data);
}

void *stack_pop(stack s)
{
    return vector_pop(s->v);
}

void stack_destroy(stack s)
{
    vector_destroy(s->v);
    free(s);
}
