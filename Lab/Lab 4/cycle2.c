#include <stdio.h>
#include "linkedlist.h"
#include "cycle.h"


int testCyclic(struct LinkedList ls) {
	struct LinkedList l = ls;
	struct node* tmp = ls.head->next;
	struct node* prev = ls.head;

	struct node* curr, tmp2;
	tmp2 = *prev;
	curr= tmp;
	prev = prev->next;
	tmp = tmp->next;
	curr->next = tmp2;
	tmp2->next = NULL;

	while(tmp != NULL) {
		if(tmp == ls.head)
			return 1;
		current = tmp;
		tmp2 = prev;
		tmp = tmp->next;
		prev = prev->next;
		current->next = tmp2;
	}
	ls.head = prev;
	return 0;
}
