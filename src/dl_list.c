#include "../include/dl_list.h"

dl_list* alloc_dl_list()
{
	dl_list* list = malloc(sizeof(dl_list));
	list->tail = NULL;
	list->head = NULL;
	list->size = -1;
}
dl_node* alloc_dl_node()
{
	dl_node* new_node = malloc(sizeof(dl_node));
	new_node->next = NULL;
	new_node->prev = NULL;
}
dl_node* dl_traverse(dl_list* list, unsigned int pos)
{
	dl_list traverse_list = *list;
	if(pos < list->size/2)
	{
		for(unsigned int i = 0; i < pos-1; i++)
		{
			traverse_list.head = traverse_list.head->next;
		}
		return traverse_list.head->next;
	}
	else
	{
		for(unsigned int i = traverse_list.size; i > pos+1; i--)
		{
			traverse_list.tail = traverse_list.tail->prev;
		}
		return traverse_list.tail->prev;
	}
}
void free_dl_list(dl_list* list)
{
	dl_node* free_node = NULL;
	while(list->head)
	{
		free_node = list->head->next;
		free(list->head);
		list->head = free_node;
	}
	free(list);
}
void dl_prepend(dl_list* list, void* udata)
{
	if(!list->head)
	{
		dl_node* new_node = alloc_dl_node();
		new_node->data = udata;

		list->head = new_node;
		list->tail = list->head;
		list->size = 1;
	}
	else if(list->size < 1)
	{
		dl_node* new_node = alloc_dl_node();
		new_node->data = udata;
		new_node->next = list->head;

		list->head->prev = new_node;
		list->head= new_node;
		list->tail = new_node->next;
		list->size++;
	}
	else
	{
		dl_node* new_node = alloc_dl_node();
		new_node->data = udata;
		list->head->prev = new_node;
		new_node->next = list->head;

		list->head = new_node;
		list->size++;
	}
}
void dl_append(dl_list* list, void* udata)
{
	if(!list->head)
	{
		dl_prepend(list, udata);
	}
	else if(list->size < 2)
	{
		dl_node* new_node = alloc_dl_node();
		new_node->data = udata;
		new_node->prev = list->tail;
		list->head->next = new_node;
		list->tail = new_node;
		list->size++;
	}
	else
	{
		//dl_node* new_node = alloc_dl_node();
		//new_node->data = udata;
		//new_node-> prev = list->tail;
		//traverse
	}
}
