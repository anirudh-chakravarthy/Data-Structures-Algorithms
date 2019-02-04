#include <stdio.h>
#include <stdlib.h>
#include "que.h"
#include "multiq.h"

MultiQ loadData(FILE f) {
	int id, pri;
	struct MultiQ mq = createMQ(10);
	while(fscanf(&f, "%d, %d", &id, &p) != EOF) {
		struct Priority* p = (struct Priority*) malloc(sizeof(struct Priority));
		struct Task* t = (struct Task*) malloc(sizeof(struct Task));
		t->taskid = id;
		t->p = p; 
		addMQ(mq, *t); 
	}
	return mq;
}

MultiQ testDel(MultiQ mq, int num) {
	for(int i = 0; i < num; i++) 
		delNextMQ(mq);
}


int main() {
	FILE* f = fopen("input10.txt", "r");
	struct MultiQ mq = loadData(f);
}
