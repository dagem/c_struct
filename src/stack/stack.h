#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct node{
	void *data;
	struct node* next;
}node;

typedef struct stack{
	node* head;
	node* tail;
}stack;

stack* alloc_stack();
void create_node();

void* pop(stack* st);
void* peek(stack* st);
void push(stack* st, void* data);

void free_stack(stack *st);
#endif /*__STACK_H__*/
