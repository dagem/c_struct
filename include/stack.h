#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct node{
	void *data;
	struct node* prev;
}node;

typedef struct stack{
	node* top;
	int size;
}stack;

stack* alloc_stack();
node*  alloc_node();

void* pop(stack* st);
void* peek(stack* st);
void push(stack* st, void* udata);

void free_stack(stack *st);
#endif /*__STACK_H__*/
