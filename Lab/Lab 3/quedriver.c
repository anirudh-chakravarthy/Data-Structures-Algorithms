#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "que.h"
#include "multiq.h"


int main() {
	struct Priority* pr = (struct Priority*) malloc(sizeof(struct Priority));
	pr->val = 1;
	struct Task* t = (struct Task*) malloc(sizeof(struct Task));
	t->taskid = 100;
	t->p = pr; 
	struct Element* e = (struct Element*) malloc(sizeof(struct Element));
	e->task = t;

	struct Queue q = newQ();
	printf("%d\n", lengthQ(q));
	q = addQ(q, *e);
	printf("%d\n", lengthQ(q));

}