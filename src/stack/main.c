#include "stack.h"
int main(void)
{
	stack* stk = alloc_stack(stk);

	push(stk, "Hello");
	char* data = stk->head->data;
	printf("%s\n", data);

}
