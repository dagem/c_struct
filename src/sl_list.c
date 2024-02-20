#include "../include/sl_list.h"

sl_list* alloc_sl_list()
{
	sl_list* new_list = malloc(sizeof(sl_list));
	new_list->head = NULL;
	new_list->tail = NULL;
	new_list->size = 0;

	return new_list;
}
sl_node* alloc_sl_node()
{
	sl_node* new_node = malloc(sizeof(sl_node));

	return new_node;
}
void free_sl_list(sl_list* list)
{
	sl_node* free_node = NULL;

	while(list->head)
	{
		free_node = list->head->next;
		free(list->head);
		list->head = free_node;
	}
	free(list);
}
//sl_traverses the list in O(n) time
sl_node* sl_traverse(sl_list* list, unsigned int upos)
{
	sl_list accessor_list = *list;
	for(int i = 0; i < upos; i++)
	{
		accessor_list.head = accessor_list.head->next;
	}
	return accessor_list.head;
}
void sl_prepend(sl_list* list, void* udata)
{
	if(!list->head)
	{
		sl_node* new_sl_node = alloc_sl_node();
		new_sl_node->data = udata; //assign udata to head node.
		new_sl_node->next = NULL;  //make the final node empty
		list->head = new_sl_node;  //assign to head, 1 node.
		list->tail = new_sl_node;  //assign to tail, 1 node.
		list->size++;		//increment the size;
	}
	else if(list->size < 2)
	{
		sl_node* new_sl_node = alloc_sl_node();
		new_sl_node->data = udata;
		new_sl_node->next = list->head;

		list->head = new_sl_node;
		list->size++;
		list->tail = list->head->next;
		list->tail->next = NULL;
	}
	else
	{
		sl_node* new_sl_node = alloc_sl_node();
		new_sl_node->data = udata;
		new_sl_node->next = list->head;

		list->head = new_sl_node;
		list->size++;
	}
}
void sl_append(sl_list* list, void* udata)
{
	if(!list->head)
	{
		sl_prepend(list, udata);
	}
	else if(list->size < 2)
	{
		sl_node* new_sl_node = alloc_sl_node();
		new_sl_node->data = udata;
		new_sl_node->next = NULL;

		list->head->next = new_sl_node;
		list->tail = new_sl_node;
		list->size++;
	}
	else
	{
		sl_node* new_sl_node = alloc_sl_node();
		new_sl_node->data = udata;
		new_sl_node->next = NULL;

		list->tail->next = new_sl_node;
		list->tail = list->tail->next;
		list->size++;
	}
}
void sl_insert(sl_list* list, void* udata, unsigned int upos)
{
	if(upos < 0)
	{
		printf("Position out of bounds, request ignored.\n");
	}
	else if(upos > list->size)
	{
		//we add nodes till we hit the position
		for(int i = list->size; i < upos-1; i++)
		{
			sl_append(list, NULL);
		}
		sl_append(list, udata);
	}
	else if(!list->head)
	{
		sl_prepend(list, udata);
	}
	else if(list->size < 2)
	{
		sl_append(list, udata);
	}
	else
	{
		sl_node* new_sl_node = alloc_sl_node();
		new_sl_node->data = udata;

		new_sl_node->next = sl_traverse(list, upos);

		sl_traverse(list, upos-1)->next = new_sl_node; //updates the user position node to be our new one
		sl_traverse(list, upos)->next = sl_traverse(list, upos+1); //moves everything after the user position over

		list->size++;

	}
}
void* sl_pop(sl_list* list, unsigned int upos)
{

	sl_node old_sl_node = *sl_traverse(list,upos);
	sl_node* remove_sl_node = sl_traverse(list, upos);
	sl_node* next_sl_node = old_sl_node.next;

	free(remove_sl_node);

	sl_traverse(list, upos-1)->next = next_sl_node;

	list->size--;

	return old_sl_node.data;

}
void sl_update(sl_list* list, void* udata, unsigned int upos)
{
	sl_traverse(list, upos)->data = udata;
}
void* sl_peek(sl_list* list, unsigned int upos)
{
	return sl_traverse(list, upos)->data;
}
