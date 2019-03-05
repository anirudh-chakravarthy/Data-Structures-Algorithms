#ifndef _MQ
#define _MQ

#include "que.h"
#include <stdbool.h>


typedef struct {
	int val;
} Priority;


typedef struct {
	int taskid;
	Priority* p;
} Task;


typedef struct {
	struct Queue* q;
	int count;
} MultiQ;


MultiQ createMQ(int num);

MultiQ addMQ(MultiQ mq, Task t);

Task nextMQ(MultiQ mq);

MultiQ delNextMQ(MultiQ mq);

bool isEmptyMQ(MultiQ mq);

int sizeMQ(MultiQ mq);

int sizeMQbyPriority(MultiQ mq, Priority p);

struct Queue getQfromMQ(MultiQ mq, Priority p);

#endif