#ifndef __HEADERS_H__
#define __HEADERS_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sl_node
{
	void* data;
	struct sl_node* next;
}sl_node;

typedef struct sl_list
{
	sl_node* head;
	sl_node* tail;
	int size;
}sl_list;
sl_list* alloc_sl_list();
sl_node*  alloc_llnode();

sl_node* traverse(sl_list* list, unsigned int upos);
void free_sl_list(sl_list* list);
void sl_prepend(sl_list* list, void* data);
void sl_append(sl_list* list, void* data);
void sl_insert(sl_list* list, void* data, unsigned int upos);
void sl_update(sl_list* list, void* data, unsigned int upos);

void* sl_pop(sl_list* list, unsigned int upos);
void* sl_peek(sl_list* list, unsigned int upos);

#endif /*__HEADERS_H__*/
