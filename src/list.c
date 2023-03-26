#include "list.h"

typedef struct _node *node;

struct _node
{
    void *data;
    node prev;
    node next;
};

struct _list
{
    node head;
    node tail;
    size_t len;
};

list list_new()
{
    list l = malloc(sizeof(struct _list));

    if (l == NULL)
        return NULL;

    l->head = NULL;
    l->tail = NULL;
    l->len = 0;

    return l;
}

size_t list_len(list l)
{
    return l->len;
}

static node list_get_node(list l, int pos)
{
    if (pos >= (int)l->len || -pos > (int)l->len)
        return (void *)-1;

    if (pos < 0)
        pos += l->len;

    node n = NULL;

    if (pos < (int)l->len / 2) // forward
    {
        n = l->head;
        for (int i = 0; i < pos; i++)
            n = n->next;
    }
    else // backward
    {
        n = l->tail;
        for (int i = l->len - 1; i > pos; i--)
            n = n->prev;
    }

    return n;
}

int list_set(list l, int pos, void *data)
{
    node n = list_get_node(l, pos);
    if (n == (void *)-1)
        return -1;

    n->data = data;

    return 0;
}

void *list_get(list l, int pos)
{
    node n = list_get_node(l, pos);
    if (n == (void *)-1)
        return n;

    return n->data;
}

int list_push(list l, void *data)
{
    l->len++;

    node n = malloc(sizeof(struct _node));

    if (n == NULL)
        return -1;

    n->data = data;
    n->prev = NULL;
    n->next = NULL;

    if (l->tail == NULL)
    {
        l->head = n;
        l->tail = n;
    }
    else
    {
        n->prev = l->tail;
        l->tail = n;
    }

    return 0;
}

void *list_pop(list l)
{
    if (l->len == 0)
        return (void *)-1;

    l->len--;

    node n = l->tail;

    l->tail = n->prev;
    if (l->tail == NULL)
        l->head = NULL;
    else
        l->tail->next = NULL;

    void *ptr = n->data;

    free(n);

    return ptr;
}

void list_destroy(list l)
{
    free(l);
}
