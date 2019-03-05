#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "alloc.h"
#include "linkedlist.h"


linkedlist createList(int num) {
	srand(time(NULL));
	linkedlist* ls = (linkedlist*) myalloc(sizeof(linkedlist));

	struct node* tmp = (struct node*) myalloc(sizeof(struct node));
	tmp->element = rand() % 100;
	tmp->next = NULL;

	ls->head = tmp;
	ls->count = num;

	for(int i = 1; i < num; i++) {
		struct node* newNode = (struct node*) myalloc(sizeof(struct node));
		newNode->next = NULL;
		newNode->element = rand();
		tmp->next = newNode;
		tmp = newNode;
	}
	printf("Space used: %lld\n", memoryUsed);
	return *ls;
}


linkedlist createCycle(linkedlist ls) {
	srand(time(NULL));
	int heads = rand() % 1;
	if(!heads)
		return ls;

	struct node* last = ls.head;
	while(last->next != NULL)
		last = last->next;

	do {
		int r = rand() % 100;
		struct node* tmp = ls.head;
		while(tmp != NULL) {
			if(tmp->element == r) {
				last->next = tmp;
				return ls;
			}
		}
	} while(r != tmp->element);
}