#include <stdio.h>
#include <stdlib.h>
#include "alloc.h"

unsigned long long int memoryUsed = 0;


void* myalloc(size_t size) {
	size_t* ptr = (size_t*) malloc(sizeof(size_t) + size);

	if (ptr == NULL) 
		return (void*) ptr;

	ptr[0] = size;
	memoryUsed += size;
	ptr++;
	return (void*) ptr;
}


void myfree(void* ptr) {
	size_t* tmp = (size_t*) ptr;
	tmp--;
	memoryUsed -= *tmp;
	free(tmp);
}