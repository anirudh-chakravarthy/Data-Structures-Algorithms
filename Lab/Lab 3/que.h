#ifndef _QUE
#define _QUE
#include <stdio.h>
#include "multiq.h"

struct Element{
	struct Task* task;
};


struct node {
	struct Element ele;
	struct node* next; 
};


struct Queue {
	int count;
	struct node* first;
	struct node* last;
};


struct Queue newQ(); // returns an empty Queue

bool isEmptyQ(struct Queue q); // tests whether Q is empty

struct Queue delQ(struct Queue q); // deletes the element from the front of the Q

struct Element front(struct Queue q); // returns the element from the front of the Q

struct Queue addQ(struct Queue q, struct Element e); // adds e to the end of the q and returns it

int lengthQ(struct Queue q); // returns the length of the Q

#endif
