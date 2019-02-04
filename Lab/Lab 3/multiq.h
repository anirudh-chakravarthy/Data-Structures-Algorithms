#ifndef _MULTIQ
#define _MULTIQ
#include <stdio.h>
#include "que.h"

struct MultiQ{
	struct Queue* q;
	int count;
};

struct Task{
	int taskid;
	struct Priority* p;
};

struct Priority {
	int val;
};

struct MultiQ createMQ(int num); // creates a list of num empty Queues

struct MultiQ addMQ(struct MultiQ mq, struct Task t); // adds t to the Q

struct Task nextMQ(struct MultiQ mq);
/* returns the front of the non-empty Q with highest priority */

struct MultiQ delNextMQ(struct MultiQ mq);
/* deletes the front of the non-empty Q in mq with the highest priority;
	returns the modified mq */

bool isEmptyMQ(struct MultiQ mq); // tests whether all the Qs in mq are empty

int sizeMQ(struct MultiQ mq); // returns the total number of items in mq

int sizeMQbyPriority(struct MultiQ mq, struct Priority p); 
// returns number of items in mq with priority p

struct Queue getQueueFromMQ(struct MultiQ mq, struct Priority p); // returns the Q with priority p

#endif
