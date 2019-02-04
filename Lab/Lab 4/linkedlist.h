#ifndef _LL
#define _LL
#include <stdio.h>

struct node {
	int val;
	struct node* next;
};


struct LinkedList {
	struct node* head;
};

struct LinkedList createList(int n);

struct LinkedList createCycle(struct LinkedList ls);


#endif
