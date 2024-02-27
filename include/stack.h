#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct st_node{
	void *data;
	struct st_node* prev;
}st_node;

typedef struct stack{
	st_node* top;
	int size;
}stack;

stack* alloc_stack();
st_node*  alloc_st_node();

void* pop(stack* st);
void* peek(stack* st);
void push(stack* st, void* udata);

void free_stack(stack *st);
#endif /*__STACK_H__*/
