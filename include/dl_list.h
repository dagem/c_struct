#ifndef __DLLIST_H__
#define __DLLIST_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct dl_node
{
	void* data;
	struct dl_node* next;
	struct dl_node* prev;
}dl_node;

typedef struct dl_list
{
	int size;
	dl_node* head;
	dl_node* tail;
}dl_list;

dl_list* alloc_dl_list();
dl_node* alloc_dl_node();

void dl_prepend(dl_list* list, void* udata);
void dl_append(dl_list* list, void* udata);
void dl_insert(dl_list* list, void* udata);
void* dl_pop(dl_list* list, unsigned int pos);
void dl_update(dl_list* list, void* udata, unsigned int pos);
dl_node* dl_forward(dl_list* list, unsigned int pos);
dl_node* dl_backward(dl_list* list, unsigned int pos);

void free_dl_list(dl_list* list);

#endif /*__DLLIST_H__*/
