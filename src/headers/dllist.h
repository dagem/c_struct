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

int prepend(dllist list, void* data);
int append(dllist list, void* data);

#endif /*__DLLIST_H__*/
