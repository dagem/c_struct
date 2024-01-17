#include "stack.h"

stack* alloc_stack()					//responsible for allocating memory for the stack.
{
	stack* st = malloc(sizeof(stack));		//allocating the memory for the stack.
	st->top = create_node();			//allocates memory for the stack's top node.
	st->size = 0;					//sets the size of the stack to 0.
	return st;					//returns our stack node.
}
node* create_node()
{
	node* new_node = malloc(sizeof(node));		//allocates memory for a node.
	new_node->prev = NULL;				//we set prev to NULL in case that it is the first node of our stack.
	return new_node;				//returns our new node.
}
void free_stack(stack* st)
{
	node* tmp = NULL;				//we create a node with no memory.
	while(st->top)					//checks to see if the top node is not null.
	{
		tmp = st->top->prev;			//we assign the "empty" node with the address of the current top node's previous node.

		free(st->top);				//we then free the current top node.
		st->top = tmp;				//then reassign the current top node to be the previous one.
	}
	free(st);					//when all the nodes are free'd, we then free our stack.
}
void push(stack *st, void* udata)
{
	if(!st->top)			        //checks if our stack is populated.
	{
		st = alloc_stack();             //allocates a new stack in the event it isn't.
		st->top->data = udata;          //sets the top of the stack's data to be our given data.
		st->size++;                     //increments the size.
	}
	node* new_node = create_node();         //since we have a stack node, we add nodes "on top" of it.
	new_node->data = udata;			//sets the data for our node.
	new_node->prev = st->top;		//assigns the new node's previous node to be the current top node.

	st->top = new_node;			//reassigns the top node to be our new node.
	st->size++;				//increments the size.
}
void* peek(stack* st)
{
	return st->top->data;			//returns the data of the current top node.
}

void* pop(stack* st)
{
	if(st->size == 1)
	{
		void* vdata = st->top->data;	//holds the data of the current top node.
		node* tmp = NULL;		//a temporary node used to "clear" the stack.

		free(st->top);			//we free the stack's top value so that there's no memory allocated to our stack other than the stack's memory.

		st->top = tmp;			//re-assigns our stack's top to be a NULL node.
		st->size--;			//sets the size to 0.
		return vdata;			//returns the data which was at the top of the stack
	}
	void* vdata = st->top->data;
	node* tmp = st->top->prev;
	free(st->top);
	st->top = tmp;
	st->size--;

	return vdata;
}


