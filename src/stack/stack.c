#include "stack.h"

stack* alloc_stack()
{
	stack* st = malloc(sizeof(stack));
	st->head->next = st->tail;
	st->head->data = malloc(sizeof(void))	
}
