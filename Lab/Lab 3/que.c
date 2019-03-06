#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "que.h"
#include "multiq.h"


struct Queue newQ() {
	struct Queue* q = (struct Queue*) malloc(sizeof(struct Queue));
	q->head = NULL;
	q->tail = NULL;
	q->count = 0;
	return *q;
}


bool isEmptyQ(struct Queue q) {
	if (q.count == 0)
		return true;
	return false;
}


struct Queue delQ(struct Queue q) {
	if(q.count == 0) {
		printf("Q is empty!\n");
		return q;
	}

	q.count--;
	printf("%d", q.count);
	q.head = q.head->next;
	return q;
}


Task front(struct Queue q) {
	if(q.head == NULL) {
		Task t;
		t.taskid = -1;
		t.p = NULL;
		return t;
	}
	return q.head->element;
}


struct Queue addQ(struct Queue q, Task ele) {
	struct node* newNode = (struct node*) malloc(sizeof(struct node));
	newNode->element = ele;
	newNode->next = NULL;

	if(q.count == 0) {
		q.head = newNode;
		q.tail = newNode;
		q.count++;
		return q;
	}

	q.tail->next = newNode;
	q.tail = newNode;
	q.count++;
	return q;
}


int lengthQ(struct Queue q) {
	return q.count; 
}
