#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "alloc.h"
#include "linkedlist.h"


struct LinkedList createList(int n) {
	int arr[n];
	srand(time(NULL));
	for(int i = 0; i < n; i++) {
		arr[i] = rand();
	}

	struct LinkedList ls;
	struct node* top = (struct node*) malloc(sizeof(struct node));
	ls.head = top;
	top->val = arr[0];
	struct node* tmp;

	for(int i = 1; i < n; i++) {
		tmp = (struct node*) malloc(sizeof(struct node));
		top->next = tmp;
		if(i == n-1) {
			tmp->next = NULL;
			break;
		}
		top = tmp;
	}
	return ls;
}


struct LinkedList createCycle(struct LinkedList ls) {
	srand(time(NULL));

	int heads = rand() % 2;
	if(heads) 
		return ls;

	struct node* top = ls.head;
	int r = rand();
	while(r != top->val){
		if(top->next == NULL) {
			r = rand();
			top = ls.head;
		}
		top = top->next;
	}

	struct node* tmp = top;
	while(tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = top;
	return ls;
}



