#include <stdio.h>
#include "cycle.h"
#include "linkedlist.h"


int testCyclic(struct LinkedList ls) {
	struct node* hare, tort;
	hare = tort = ls.head;

	// empty list
	if(hare == NULL)
		return 0;

	if(hare->next->next == NULL)
		return 0;

	// if list is linear, will terminate
	while(hare != NULL || hare->next == NULL) {
		hare = hare->next->next;
		tort = tort->next;
		// check for cycle
		if(hare == tort)
			return 1;
	}
	return 0;
}


