#ifndef __DLLIST_H__
#define __DLLIST_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	void* data;
	struct node* next;
	struct node* prev;
}node;

typedef struct dllist
{
	int size;
	node* head;
	node* tail;
}dllist;

dllist* alloc_list();
node* alloc_node();

void prepend(dllist* list, void* udata);
void append(dllist* list, void* udata);
void insert(dllist* list, void* udata);
void* pop(dllist* list, unsigned int pos);
void update(dllist* list, void* udata, unsigned int pos);
node* forward(dllist* list, unsigned int pos);
node* backward(dllist* list, unsigned int pos);

void free_dllist(dllist* list);

#endif /*__DLLIST_H__*/
