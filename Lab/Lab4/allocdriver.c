#include <stdio.h>
#include <stdlib.h>
#include "alloc.h"


int main() {
	int* arr = myalloc(sizeof(int) * 5);
	arr[0] = 1;
	// for(int i = 0; i < 5; i++) 
	// 	printf("%d ", arr[i]);
	printf("%lld\n", memoryUsed);
	myfree(arr);
	printf("%lld\n", memoryUsed);
}