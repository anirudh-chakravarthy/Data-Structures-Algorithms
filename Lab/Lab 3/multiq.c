#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "multiq.h"
#include "que.h"


struct MultiQ createMQ(int num) {
	struct MultiQ* mq = (struct MultiQ*) calloc(num, sizeof(struct Queue));
	mq->count = num;

	for(int i = 0; i < num; i++) {
		// printf("HERE!\n");
		struct Queue tmp = newQ();
		// printf("HERE2\n");
		mq[i].q = &tmp;
	}
	return *mq;
}


struct MultiQ addMQ(struct MultiQ mq, struct Task t) {
	int pri = (t.p)->val;
	struct Element* e = (struct Element*) malloc(sizeof(struct Element));
	e->task = &t;
	mq.q[pri-1] = addQ(mq.q[pri-1], *e);
	return mq;
}


struct Task nextMQ(struct MultiQ mq) {
	for(int i = mq.count-1; i >= 0; i--) {
		if(isEmptyQ(mq.q[i]))
			continue;
		else {
			struct Element e = front(mq.q[i]);
			return *(e.task);
		}
	}
	printf("MultiQ is empty!\n");
	struct Task* t = (struct Task*) malloc(sizeof(struct Task));
	t->taskid = -1;
	t->p = NULL;
	return *t;
}


struct MultiQ delNextMQ(struct MultiQ mq) {
	for(int i = mq.count-1; i >= 0; i--) {
		if(isEmptyQ(mq.q[i]))
			continue;
		else {
			delQ(mq.q[i]);
			return mq;
		}
	}
	printf("MultiQ is empty!\n");
	return mq;
}


bool isEmptyMQ(struct MultiQ mq) {
	for(int i = 0; i < mq.count; i++) {
		if(!isEmptyQ(mq.q[i]))
			return false;
	}
	return true;
}


int sizeMQ(struct MultiQ mq) {
	return mq.count;
}


int sizeMQbyPriority(struct MultiQ mq, struct Priority p) {
	int pri = p.val;
	return lengthQ(mq.q[pri-1]);
}


struct Queue getQueueFromMQ(struct MultiQ mq, struct Priority p) {
	int pri = p.val;
	return mq.q[pri-1];
}
