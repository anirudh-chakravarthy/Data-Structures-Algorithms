#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "que.h"
#include "multiq.h"


MultiQ createMQ(int num) {
	MultiQ mq;
	mq.q = (struct Queue*) malloc(sizeof(struct Queue) * num);
	mq.count = num;

	for(int i = 0; i < num; i++) 
		mq.q[i] = newQ(); 
	return mq;
}


MultiQ addMQ(MultiQ mq, Task t) {
	int pri = t.p->val;
	mq.q[pri] = addQ(mq.q[pri], t);
	return mq;
}


Task nextMQ(MultiQ mq) {
	for(int i = mq.count; i >= 0; i--) {
		if(!isEmptyQ(mq.q[i])) 
			return front(mq.q[i]);
	}

	Task tmp;
	tmp.taskid = -1;
	tmp.p = NULL;
	return tmp;
}


MultiQ delNextMQ(MultiQ mq) {
	for(int i = mq.count; i >= 0; i++) {
		if(!isEmptyQ(mq.q[i])) 
			mq.q[i] = delQ(mq.q[i]);
	}
	return mq;
}


bool isEmptyMQ(MultiQ mq) {
	for(int i = mq.count; i >= 0; i++) {
		if(!isEmptyQ(mq.q[i])) 
			return false;
	}
	return true;
}


int sizeMQ(MultiQ mq) {
	int count = 0;
	for(int i = 0; i < mq.count; i++) {
		if(!isEmptyQ(mq.q[i]))
			count += lengthQ(mq.q[i]);
	}
	return count;
}


int sizeMQbyPriority(MultiQ mq, Priority p) {
	int pri = p.val;
	return lengthQ(mq.q[pri]);
}


struct Queue getQfromMQ(MultiQ mq, Priority p) {
	int pri = p.val;
	return mq.q[pri];
}
