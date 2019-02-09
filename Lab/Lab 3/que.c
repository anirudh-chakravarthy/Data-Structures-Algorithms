#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "que.h"


struct Queue newQ() {
	struct Queue* q = (struct Queue*) malloc(sizeof(struct Queue));
	q->count = 0;
	q->first = NULL;
	q->last = NULL;
	return *q;
}


bool isEmptyQ(struct Queue q) {
	if(q.count == 0) 
		return true;
	return false;
}


struct Queue delQ(struct Queue q) {
	if(q.count == 0) {
		printf("Q is empty!\n");
		return q;
	}
	struct node* head = q.first;
	q.first = head->next;
	q.count--;
	free(head);
	return q;
}


struct Element front(struct Queue q) {
	if(q.count == 0) {
		printf("Q is empty!\n");
		struct Element* e = (struct Element*) malloc(sizeof(struct Element));
		e->task = NULL;
		return *e;
	}
	struct node* head = q.first;
	return head->ele;
}


struct Queue addQ(struct Queue q, struct Element e)  {
	struct node* newnode = (struct node*) malloc(sizeof(struct node));
	newnode->ele = e;
	newnode->next = NULL;

	if(lengthQ(q) == 0) {
		q.first = newnode;
		q.last = newnode;
		q.count++;
		return q;
	}

	struct node* tail = q.last;
	tail->next = newnode;
	q.last = newnode;
	q.count++;
	return q;
}


int lengthQ(struct Queue q) {
	return q.count;
}
