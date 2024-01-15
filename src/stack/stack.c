#include "stack.h"

stack* alloc_stack()
{
	stack* st = malloc(sizeof(stack));
	st->top = NULL;
	st->size = 0;
	return st;
}
node* create_node()
{
	node* new_node = malloc(sizeof(node));
	new_node->prev = NULL;
	return new_node;
}
void free_stack(stack* st)
{
	node* tmp = NULL;
	while(st->top)
	{
		tmp = st->top->prev;
		free(st->top);
		st->top = tmp;
	}
	free(st);
}
void push(stack *st, void* data)
{
	if(st->size == 0)
	{
		node* tmp = create_node();
		
		tmp->data = data;
		tmp->prev = NULL;
	
		st->top = tmp;
		st->size++;

	}
	node* tmp = create_node();
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
	if(st->size == 1)
	{
		void* vdata = st->top->data;
		node* tmp = NULL;
		
		free(st->top);
		
		st->top = tmp;
		st->size--;
		return vdata;
	}
	void* vdata = st->top->data;
	node* tmp = st->top->prev;
	free(st->top);
	st->top = tmp;
	st->size--;

	return vdata;
}


