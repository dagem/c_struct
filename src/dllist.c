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
		//new_node->next = list->head;
		//new_node->next->prev = new_node;
		list->head->prev = new_node;
		new_node->next = list->head;

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
