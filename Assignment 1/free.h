#ifndef _FREE
#define _FREE
#include <stdio.h>
#include "linkedlist.h"


// Push new location onto free
void push(int arr[], struct LinkedList* free, int loc);

// pop from free
int pop(int arr[], struct LinkedList* free);

// prints free list
void printFreeList(int arr[], struct LinkedList free);

#endif