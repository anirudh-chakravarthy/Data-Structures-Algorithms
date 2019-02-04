#include "stack.h"

void push(struct linkedList* head, int ele) {
	insertFirst(head, ele);
}

struct node* pop(struct linkedList* head) {
	struct node* firstnode = deleteFirst(head);
	return firstnode;
}
