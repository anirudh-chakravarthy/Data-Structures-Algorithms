#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "alloc.h"
#include "linkedlist.h"


void printList(linkedlist ls) {
	struct node* tmp = ls.head;
	for(int i = 0; i < ls.count; i++) {
		printf("%d ", tmp->element);
		tmp = tmp->next;
	}
	printf("\n");
}


int main() {
	linkedlist ls = createList(5);
	printList(ls);
}