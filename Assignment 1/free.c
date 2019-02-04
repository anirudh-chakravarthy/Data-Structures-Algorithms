#include <stdio.h>
#include "free.h"
#include "linkedlist.h"


// push to free using stack-like implementation
void push(int arr[], struct LinkedList* free, int loc) {
	int top = free->head;
	// printf("%d", top);

	if(top == -1) {
		free->head = loc;
		return;
	}

	int nextindex = arr[top+1];
	//printf("%d\n", nextindex);

	// till last element is encountered
	while(arr[nextindex+1] != -1) {
		nextindex = arr[nextindex+1];
		//printf("%d\n", nextindex);
	}

	arr[nextindex+1] = loc;
	arr[loc+1] = -1;
}


// pop from free using stack-like implementation
int pop(int arr[], struct LinkedList* free) {
	int index = free->head;

	// if free list is empty i.e memory full
	if(index == -1) 
		return -1;
	

	int nextindex = arr[index+1];

	// only 1 element in the free list
	if(nextindex == -1) {
		free->head = -1;
		return index;
	}

	// until penultimate element in encountered
	while(arr[nextindex+1] != -1) {
		index = arr[index+1];
		nextindex = arr[nextindex+1];
	}

	arr[index+1] = -1;
	return nextindex;
}


void printFreeList(int arr[], struct LinkedList free) {
	int index = free.head;
	if(index == -1) {
		printf("Free List is empty!\n");
		return;
	}
	printf("Elements of free list are:\n");
	printf("[");
	while(index != -1) {
		if(arr[index+1] == -1) {
			printf("%d]", index);
			printf("\n");
			return;
		}
		printf("%d, ", index);
		index = arr[index+1];
	}
}