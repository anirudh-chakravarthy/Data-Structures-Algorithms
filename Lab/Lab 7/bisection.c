#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <assert.h>
#include <math.h>

#include "employee.h"
#include "stack.h"
#include "quickSort.h"
#include "insertionSort.h"


typedef struct{
	double IStime;
	double QStime;
} times;


times testRun(Employee* list, int size) {
	Employee copy1[size], copy2[size];
	for(int i = 0; i < size; i++) {
		copy1[i] = list[i];
		copy2[i] = list[i];
	}

	struct timeval t1, t2;
	double IStime = 0.0, QStime = 0.0;
	
	for(int i = 0; i < 50; i++) {
		gettimeofday(&t1, NULL); 
		insertionSort(copy1, size);
		gettimeofday(&t2, NULL);
		
		IStime += (t2.tv_sec - t1.tv_sec) * 1000.0;  // sec to ms
		IStime += (t2.tv_usec - t1.tv_usec) / 1000.0; // us to ms
		
		for(int i = 0; i < size; i++) 
			copy1[i] = list[i];
	}

	for(int i = 0; i < 50; i++) {
		gettimeofday(&t1, NULL); 
		quickSort(copy2, size, 1);
		gettimeofday(&t2, NULL);
		
		QStime += (t2.tv_sec - t1.tv_sec) * 1000.0;  // sec to ms
		Qstime += (t2.tv_usec - t1.tv_usec) / 1000.0; // us to ms
		
		for(int i = 0; i < size; i++) 
			copy2[i] = list[i];
	}

	printf("Total time for insertion sort is %lf ms.\n", IStime / 50);
	printf("Total time for quick sort is %lf ms.\n", QStime / 50);

	times t;
	t.IStime = IStime;
	t.QStime = QStime;

	return t;
}


int estimateCutoff(Employee* list, int size) {
	int min = 5;
	int max = size;

	times tt1 = testRun(list, min); 
	assert(tt1.IStime < tt1.QStime);

	times tt2 = testRun(list, max);
	assert(tt2.IStime > tt2.QStime);

	do {
		int mid = (min + max) / 2;
		min = mid;
		times tt = testRun(list, mid);
	} while(fabs(tt.IStime - tt.QStime) >= 0.0005)

	return mid;
}