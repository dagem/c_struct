#include "stack.h"

stack* alloc_stack()
{
	stack* st = malloc(sizeof(stack));
	st->top = malloc(sizeof(node));
	st->bottom = st->top;
	st->top->prev = st->bottom;
	st->size = 0;
	return st;
}
void free_stack(stack* st)
{
	node* tmp = st->top;
	while(st->top->prev)
	{
		tmp = st->top->prev;
		free(st->top);
		st->top = tmp;
	}
}
void push(stack *st, void* data)
{
	if(!st->top)
	{
		st->top = malloc(sizeof(node*));
		st->top->data = data;
		st->top->prev = NULL;
		st->size++;
	}
	node* tmp = malloc(sizeof(node*));
	tmp->data = data;
	tmp->prev = st->top;

	st->top = tmp;
	st->size++;
}
void* peek(stack* st)
{
	return st->top->data;
}

void* pop(stack* st)
{
	if(st->top->prev == NULL)
	{
		void* tmp_data = st->top->data;
		st = malloc(sizeof(stack));
		st->size = 0;
		return tmp_data;
	}
	else
	{
		void* tmp_data = st->top->data;
		st->top = st->top->prev;
		st->size--;
		return tmp_data;
	}
}


