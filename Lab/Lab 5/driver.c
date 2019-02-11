#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "creditcard.h"
#include "insertionSort.h"


int main(int argc, char** argv) {
	struct timeval t1, t2;
	double elapsedTime;
	gettimeofday(&t1, NULL);

	if(argc == 1) {
		printf("Enter an input file!\n");
		return 0;
	}

	if(argc > 2) {
		printf("Too many input files!\n");
		return 0;
	}


	FILE* f = fopen(argv[1], "r");
	struct CreditCard* c = readRecord(f);
	insertionSort(c, count);

	// for(int i = 0; i < count; i++) {
	// 	printf("%lld\n", c[i].cardNo);
	// }

	gettimeofday(&t2, NULL);

	// compute and print the elapsed time in millisec
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;  // sec to ms
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0; // us to ms
	printf("Total time is %lf ms.\n", elapsedTime);
	return 0;
}