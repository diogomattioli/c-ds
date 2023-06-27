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

int list_insert(list l, int pos, void *data)
{
    if (pos < 0)
        pos += l->len;

    if (pos == 0)
        list_push_front(l, data);
    else if ((size_t)pos == l->len)
        list_push_back(l, data);
    else
    {
        node n = list_get_node(l, pos);
        if (n == (void *)-1)
            return -1;

        node new_n = malloc(sizeof(struct _node));
        if (new_n == NULL)
            return -1;

        new_n->data = data;
        new_n->prev = n->prev;
        new_n->next = n;

        new_n->prev->next = new_n;
        new_n->next->prev = new_n;

        l->len++;
    }

    return 0;
}

void *list_remove(list l, int pos)
{
    if (pos < 0)
        pos += l->len;

    if (pos == 0)
        return list_pop_front(l);
    else if ((size_t)pos == l->len)
        return list_pop_back(l);
    else
    {
        node n = list_get_node(l, pos);
        if (n == (void *)-1)
            return n;

        if (n->prev != NULL)
            n->prev->next = n->next;

        if (n->next != NULL)
            n->next->prev = n->prev;

        void *ptr = n->data;

        free(n);

        l->len--;

        return ptr;
    }
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

int list_push_front(list l, void *data)
{
    node n = malloc(sizeof(struct _node));

    if (n == NULL)
        return -1;

    n->data = data;
    n->prev = NULL;
    n->next = NULL;

    if (l->head == NULL)
    {
        l->head = l->tail = n;
    }
    else
    {
        n->next = l->head;
        l->head->prev = n;
        l->head = n;
    }

    l->len++;

    return 0;
}

void *list_pop_front(list l)
{
    if (l->len == 0)
        return (void *)-1;

    node n = l->head;

    l->head = n->next;
    if (l->head == NULL)
        l->tail = NULL;
    else
        l->head->prev = NULL;

    void *ptr = n->data;

    free(n);

    l->len--;

    return ptr;
}

int list_push_back(list l, void *data)
{
    node n = malloc(sizeof(struct _node));

    if (n == NULL)
        return -1;

    n->data = data;
    n->prev = NULL;
    n->next = NULL;

    if (l->tail == NULL)
    {
        l->head = l->tail = n;
    }
    else
    {
        n->prev = l->tail;
        l->tail->next = n;
        l->tail = n;
    }

    l->len++;

    return 0;
}

void *list_pop_back(list l)
{
    if (l->len == 0)
        return (void *)-1;

    node n = l->tail;

    l->tail = n->prev;
    if (l->tail == NULL)
        l->head = NULL;
    else
        l->tail->next = NULL;

    void *ptr = n->data;

    free(n);

    l->len--;

    return ptr;
}

void list_cleanup(list l)
{
    void *ptr = NULL;
    while ((ptr = list_pop_back(l)) != (void *)-1)
    {
        free(ptr);
    }
}

void list_destroy(list l)
{
    while (list_pop_back(l) != (void *)-1)
    {
    }

    free(l);
}
