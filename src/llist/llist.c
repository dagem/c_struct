#include "llist.h"

llist* alloc_llist()
{
	llist* new_list = malloc(sizeof(llist));
	new_list->head = alloc_node(); // maybe not null
	new_list->tail = alloc_node();
	new_list->size = 0;

	return new_list;
}
node* alloc_node()
{
	node* new_node = malloc(sizeof(node));
	new_node->next = NULL;

	return new_node;
}

void prepend(llist* list, void* udata)
{
	if(!list->head)
	{
		list = alloc_llist(); //list doesn't exist make one.
		list->head = alloc_node(); //allocate mem for head.
		list->head->data = udata; //assign udata to head node.
		list->tail = list->head; //assign tail to head, 1 node.
		list->size++;
	}
	node* new_node = alloc_node();
	new_node->data = udata;
	new_node->next = list->head;

	list->head = new_node;
	list->size++;
}
void append(llist* list, void* udata)
{
	if(!list->head)
	{
		prepend(list, udata);
	}
	node* new_node = alloc_node();
	new_node->data = udata;
	new_node->next = NULL;
	list->tail = new_node;
}
