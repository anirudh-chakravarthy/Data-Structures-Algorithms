#ifndef _QUE
#define _QUE
#include <stdbool.h>
#include "multiq.h"


struct node {
	Task element;
	struct node* next;
};

struct Queue{
	int count; 
	struct node* head;
	struct node* tail;
};


struct Queue newQ();

bool isEmptyQ(struct Queue q);

struct Queue delQ(struct Queue q);

Task front(struct Queue q);

struct Queue addQ(struct Queue q, Task ele);

int lengthQ(struct Queue q);

#endif