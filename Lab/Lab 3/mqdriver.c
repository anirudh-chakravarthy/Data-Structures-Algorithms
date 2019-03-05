#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "que.h"
#include "multiq.h"


Task createTask(int taskid, int pri) {
	Priority* p = (Priority*) malloc(sizeof(Priority));
	p->val = pri;

	Task t;
	t.taskid = taskid;
	t.p = p;
	return t;
}


int main() {
	MultiQ mq = createMQ(5);
	// printf("%d\n", sizeMQ(mq));
	Task t1 = createTask(123, 1);
	Task t2 = createTask(123, 2);

	// Priority* p = (Priority*) malloc(sizeof(Priority));
	// p->val = 1;

	mq = addMQ(mq, t1);
	mq = addMQ(mq, t2);
	printf("%d\n", sizeMQ(mq));
	mq = delNextMQ(mq);
	// printf("%d\n", sizeMQbyPriority(mq, *p));
}