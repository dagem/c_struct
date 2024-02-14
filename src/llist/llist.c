#include "../../include/llist.h"

llist* alloc_llist()
{
	llist* new_list = malloc(sizeof(llist));
	new_list->head = NULL;
	new_list->tail = NULL;
	new_list->size = 0;

	return new_list;
}
node* alloc_node()
{
	node* new_node = malloc(sizeof(node));

	return new_node;
}
void free_llist(llist* list)
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
node* traverse(llist* list, int upos)
{
	llist accessor_list = *list;
	for(int i = 0; i < upos; i++)
	{
		accessor_list.head = accessor_list.head->next;
	}
	return accessor_list.head;
}
void prepend(llist* list, void* udata)
{
	if(!list->head)
	{
		node* new_node = alloc_node();
		new_node->data = udata; //assign udata to head node.
		new_node->next = NULL;  //make the final node empty
		list->head = new_node;  //assign to head, 1 node.
		list->tail = new_node;  //assign to tail, 1 node.
		list->size++;		//increment the size;
	}
	else if(list->size < 2)
	{
		node* new_node = alloc_node();
		new_node->data = udata;
		new_node->next = list->head;
		list->head = new_node;
		list->size++;
		list->tail = list->head->next;
		list->tail->next = NULL;
	}
	else
	{
		node* new_node = alloc_node();
		new_node->data = udata;

		llist accessor_list = *list; //creates a non-pointer list which allows us to update each node pointer's position value
		while(accessor_list.head)
		{
			accessor_list.head = accessor_list.head->next;
		}
		new_node->next = list->head;
		list->head = new_node;
		list->size++;
	}
}
void append(llist* list, void* udata)
{
	if(!list->head)
	{
		prepend(list, udata);
	}
	else if(list->size < 2)
	{
		node* new_node = alloc_node();
		new_node->data = udata;
		new_node->next = NULL;

		list->head->next = new_node;
		list->tail = new_node;
		list->size++;
	}
	else
	{
		node* new_node = alloc_node();
		new_node->data = udata;
		new_node->next = NULL;

		list->tail->next = new_node;
		list->tail = list->tail->next;
		list->size++;
	}
}
void insert(llist* list, void* udata,  int upos)
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
			append(list, NULL);
		}
		append(list, udata);
	}
	else if(!list->head)
	{
		prepend(list, udata);
	}
	else if(list->size < 2)
	{
		append(list, udata);
	}
	else
	{
		node* new_node = alloc_node();
		new_node->data = udata;

		new_node->next = traverse(list, upos);

		traverse(list, upos-1)->next = new_node; //updates the user position node to be our new one
		traverse(list, upos)->next = traverse(list, upos+1); //moves everything after the user position over

		list->size++;

	}
}
void* pop(llist* list, int upos)
{
}
void update(llist* list, void* udata,  int upos)
{
	traverse(list, upos)->data = udata;
}
void* peek(llist* list,  int upos)
{
	return traverse(list, upos)->data;
}
