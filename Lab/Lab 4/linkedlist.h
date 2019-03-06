#ifndef _LL
#define _LL


struct node {
	int element;
	struct node* next;
};


typedef struct {
	int count;
	struct node* head;
} linkedlist;


linkedlist createList(int num);

linkedlist createCycle(linkedlist ls);

#endif