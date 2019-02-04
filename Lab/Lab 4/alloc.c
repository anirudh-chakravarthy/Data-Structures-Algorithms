#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "alloc.h"

unsigned long long int spaceUsed = 0;


void* myalloc(size_t size) {
	size_t* ptr = malloc(sizeof(size_t) + size);

	if(ptr == NULL)
		return (void*) ptr;

	spaceUsed += size;
	*ptr = size;
	ptr = ptr + 1;
	return (void*) ptr;
}


void myfree(void* ptr) {
	if(ptr == NULL)
		return;

	size_t* tmp = (size_t*) ptr;
	tmp = tmp - 1;
	size_t size = *tmp;
	free(tmp);
	spaceUsed -= size;
}


/*int main() {
	int* arr;
	srand(time(NULL));
	int m = (rand() % (25000-10000)) + 10000;
	arr = (int*) myalloc(m * sizeof(int));
	printf("%p %p\n", &arr[0], &arr[m-1]);
	myfree(arr);
}*/
