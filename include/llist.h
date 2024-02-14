#ifndef __HEADERS_H__
#define __HEADERS_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	void* data;
	struct node* next;
}node;

typedef struct llist
{
	node* head;
	node* tail;
	int size;
}llist;

llist* alloc_llist();
node*  alloc_node();

node* traverse(llist* list, int upos);
void free_llist(llist* list);
void prepend(llist* list, void* data);
void append(llist* list, void* data);
void insert(llist* list, void* data, int upos);
void update(llist* list, void* data, int upos);

void* pop(llist* list, int upos);
void* peek(llist* list, int upos);

#endif /*__HEADERS_H__*/
