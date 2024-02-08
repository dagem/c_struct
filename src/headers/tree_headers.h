#ifndef __TREE_HEADERS_H__
#define __TREE_HEADERS_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	void* data;
	struct node* prev;
	struct node* next;

}node;

void alloc_node();

#endif /*__TREE_HEADERS_H__

