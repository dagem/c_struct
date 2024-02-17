#include "../include/dllist.h"

dllist* alloc_dllist()
{
	dllist* list = malloc(sizeof(dllist));
	list->tail = NULL;
	list->head = NULL;
	list->size = -1;
}
node* alloc_dlnode()
{
	node* new_node = malloc(sizeof(node));
	new_node->next = NULL;
	new_node->prev = NULL;
}
void free_dllist(dllist* list)
{
	node* free_node = NULL;
	while(list->head)
	{
		free_node = list->head->next;
		free(list->head);
		list->head = free_node;
	}
	free(list);
}
void prepend(dllist* list, void* udata)
{
	if(!list->head)
	{
		node* new_node = alloc_dlnode();
		new_node->data = udata;

		list->head = new_node;
		list->tail = list->head;
		list->size = 1;
	}
	else if(list->size < 1)
	{
		node* new_node = alloc_dlnode();
		new_node->data = udata;
		new_node->next = list->head;

		list->head->prev = new_node;
		list->head= new_node;
		list->tail = new_node->next;
		list->size++;
	}
	else
	{
		node* new_node = alloc_dlnode();
		new_node->data = udata;
		list->head->prev = new_node;
		new_node->next = list->head;

		list->head = new_node;
		list->size++;
	}
}
void append(dllist* list, void* udata)
{
	if(!list->head)
	{
		prepend(list, udata);
	}
	else if(list->size < 2)
	{
		node* new_node = alloc_dllnode();
		new_node->data = udata;
		new_node->prev = list->tail;
		//write traverse method
	}
}
