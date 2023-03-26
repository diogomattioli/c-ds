#ifndef __STACK_H__
#define __STACK_H__

#include <stdlib.h>

typedef struct _stack *stack;

stack stack_new();
size_t stack_len(stack s);

int stack_push(stack s, void *data);
void *stack_pop(stack s);

void stack_destroy(stack s);

#endif
