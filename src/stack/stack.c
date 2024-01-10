#include "stack.h"

stack* alloc_stack()
{
	stack* st = malloc(sizeof(stack));
	st->head = malloc(sizeof(node));
	st->tail = st->head;
	st->head->next = st->tail;
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
void* peek(stack* st)
{
	return st->head->data;
}

void* pop(stack* st)
{
	if(st->head->next == NULL)
	{
		void* tmp_data = st->head->data;
		st = malloc(sizeof(stack));
		return tmp_data;
	}
	else
	{
		void* tmp_data = st->head->data;
		st->head = st->head->next;
		return tmp_data;
	}
}
