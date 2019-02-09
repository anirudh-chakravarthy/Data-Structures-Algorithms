#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "que.h"
#include "multiq.h"


struct MultiQ loadData(FILE f) {
	int id, pri;
	struct MultiQ mq = createMQ(10);
	while(fscanf(&f, "%d, %d", &id, &pri) != EOF) {
		struct Priority* p = (struct Priority*) malloc(sizeof(struct Priority));
		struct Task* t = (struct Task*) malloc(sizeof(struct Task));
		t->taskid = id;
		t->p = p; 
		addMQ(mq, *t); 
	}
	return mq;
}

struct MultiQ testDel(struct MultiQ mq, int num) {
	for(int i = 0; i < num; i++) 
		delNextMQ(mq);
	return mq;
}


int main() {
	FILE* f = fopen("input10.txt", "r");
	struct MultiQ mq = loadData(*f);
}
