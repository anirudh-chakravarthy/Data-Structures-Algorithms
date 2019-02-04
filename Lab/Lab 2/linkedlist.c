#include "linkedlist.h"

void insertFirst(struct linkedList* head, int ele) {
	// create a node
	struct node* link = (struct node*) malloc(sizeof(struct node));
	/* by this you are creating a node whose address is being stored in the link pointer. */

	link->element = ele;

	// point it to old first node
	link->next = head->first;
	head->first = link;
	head->count++;
}

struct node* deleteFirst(struct linkedList* head) {
	if(head->count == 0){
		printf("List is empty!\n");
		exit(1);
	}
	
	struct node* firstnode = head->first;
	head->first = firstnode->next;
	head->count--;
	return firstnode;
}

void printList(struct linkedList* head) {
	struct node* ptr = head->first;
	printf("\n[ ");

	while(ptr != NULL) {
		printf("%d, ", ptr->element);
		ptr = ptr->next;
	}
	printf(" ]\n");
}

