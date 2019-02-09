#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "que.h"
#include "multiq.h"


struct MultiQ loadData(FILE* fp) {
	int id, pri;
	struct MultiQ mq = createMQ(10);
	// printf("CREATED!\n");
	while(!feof(fp)) {
		// printf("Reading %d %d\n", id, pri);
		fscanf(fp, "%d,%d\n", &id, &pri);
		struct Priority* pr = (struct Priority*) malloc(sizeof(struct Priority));
		pr->val = pri;
		printf("%d\n", pr->val);
		struct Task* t = (struct Task*) malloc(sizeof(struct Task));
		t->taskid = id;
		t->p = pr; 
		// printf("%d %d\n", t->taskid, t->p->val);
		mq = addMQ(mq, *t); 
		// printf("Added!\n");
	}
	fclose(fp);
	return mq;
}


struct MultiQ testDel(struct MultiQ mq, int num) {
	for(int i = 0; i < num; i++) 
		mq = delNextMQ(mq);
	return mq;
}


int main() {
	FILE* f = fopen("./input10.txt", "r");
	// printf("File opened!\n");
	struct MultiQ mq = loadData(f);
}
