#ifndef __HEADERS_H__
#define __HEADERS_H__

#include <stdio.h>

typedef struct llist
{
	node* head;
	node* tail;
	int size;
}llist;
typedef struct node
{
	void* data;
	struct node* next;
}node;

llist* alloc_list();
node*  alloc_node();

void prepend(llist* list, void* data);
void append(llist* list, void* data);
void insert(llist* list, void* data, int pos);
void* remove(llist* list, void* data, int pos);
void update(llist* list, void* data, int pos);

void free_llist(llist* list);
#endif /*__HEADERS_H__*/
