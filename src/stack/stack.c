#include "stack.h"

stack* alloc_stack(stack* st)
{
	st = malloc(sizeof(stack));
	st->head->next = st->tail;
	st->head->data = malloc(sizeof(void));
	return st;
}
void free_stack(stack* st)
{
	node* tmp = st->head;
	while(st->head->next)
	{	
		tmp = st->head->next;
		free(st->head);
		st->head = tmp;
	}
}
void push(stack *st, void* data)
{
	if(!st->head)
	{
		st->head = malloc(sizeof(node*));
		st->head->data = data;
		st->head->next = NULL;
	}
	node* tmp = malloc(sizeof(node*));
	tmp->data = data;
	tmp->next = st->head;
	
	st->head = tmp;
}
