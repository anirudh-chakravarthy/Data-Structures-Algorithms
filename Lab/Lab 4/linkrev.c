#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "alloc.h"
#include "linkedlist.h"
#include "cycle.h"


bool testCyclic(linkedlist ls) {
	if(ls.count == 0)
		return false;

	struct node* curr = ls.head->next;
	struct node* prev = ls.head;

	while(curr != NULL) {
		if(curr == ls.head)
			return true;
		struct node* tmp = curr;
		curr = curr->next;
		tmp->next = prev;
		prev = tmp;
	}
	reurn false;
}