#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "alloc.h"
#include "linkedlist.h"
#include "cycle.h"


bool testCyclic(linkedlist ls) {
	struct node* hare = ls.head;
	struct node* tort = hare;
	while(hare != NULL || hare->next != NULL) {
		hare = hare->next->next;
		tort = tort->next;
		if(hare == tort)
			return true;
	}
	return false;
}