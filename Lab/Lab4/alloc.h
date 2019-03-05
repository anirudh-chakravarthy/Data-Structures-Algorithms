#ifndef _ALLOC
#define _ALLOC
#include <stdio.h>

unsigned long long int memoryUsed;


void* myalloc(size_t size);

void myfree(void* ptr);

#endif