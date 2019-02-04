#include <stdio.h>
#include "linkedlist.h"
#include "free.h"


struct LinkedList createNewList() {
	struct LinkedList l;
	l.head = -1;
	return l;
}


void insertList(int arr[], struct LinkedList* free, struct LinkedList* l, int ele) {
	int index = l->head;
	int newIndex = pop(arr, free);


	if(newIndex == -1) {
		printf("Failure: Memory is Full!\n");
		return;
	}


	// if list is empty
	if(index == -1) {
		l->head = newIndex;
		arr[newIndex] = ele;
		arr[newIndex+1] = -1;
		arr[newIndex+2] = -1;
		printf("Success!\n");
		return;
	}

	arr[newIndex] = ele; 

	// to insert before first element
	if(arr[index] >= ele) {
		l->head = newIndex;
		arr[index+2] = newIndex;
		arr[newIndex+1] = index;
		arr[newIndex+2] = -1;
		printf("Success!\n");
		return;
	}


	// flag to check if last element is reached
	int flag = 0;

	// to reach appropriate element
	while(arr[index] <= ele) {
		if(arr[index+1] == -1) {
			flag = 1;
			break;
		}
		index = arr[index+1];
	}

	// inserting in middle 
	if(flag == 0) {
		int nextIndex = index;
		int prevIndex = arr[index+2];

		arr[nextIndex+2] = newIndex; // setting prev for next element
		arr[prevIndex+1] = newIndex; // setting next for previous element
		arr[newIndex+1] = nextIndex; // setting next for new element
		arr[newIndex+2] = prevIndex; // setting prev for new element
		printf("Success!\n");
		return;
	}

	// for insertion at end of list
	arr[index+1] = newIndex;
	arr[newIndex+1] = -1;
	arr[newIndex+2] = index;
	printf("Success!\n");
	
}


void deleteFromList(int arr[], struct LinkedList* free, struct LinkedList* l, int ele) {
	int index = l->head;

	if(index == -1) {
		printf("Failure: List is empty!\n");
		return;
	}

	// to delete first element
	if(arr[index] == ele) {
		int nextIndex = arr[index+1];

		// if it is the only element		
		if(nextIndex == -1) {
			l->head = -1;
			push(arr, free, index);
			printf("Success!\n");
			return;
		}

		l->head = nextIndex;
		arr[index+1] = -1;
		arr[index+2] = -1;
		arr[nextIndex+2] = -1;
		push(arr, free, index);
		printf("Success!\n");
		return;
	}

	while(arr[index] != ele) {
		if(arr[index+1] == -1) {
			printf("Failure: Element not found!\n");
			return;
		}
		index = arr[index+1];
	}

	// to delete last element
	if(arr[index+1] == -1) {
		int prevIndex = arr[index+2];
		arr[prevIndex+1] = -1;
		arr[index+2] = -1;
		push(arr, free, index);
		printf("Success!\n");
		return; 
	}


	// for middle deletion
	int nextIndex = arr[index+1];
	int prevIndex = arr[index+2];

	arr[prevIndex+1] = nextIndex;
	arr[nextIndex+2] = prevIndex;
	arr[index+1] = -1;
	arr[index+2] = -1;
	push(arr, free, index);
	printf("Success!\n");
}


int listSize(int arr[], struct LinkedList l) {
	int index = l.head;

	// if list is empty
	if(index == -1) 
		return 0;

	int count = 1;

	while(arr[index+1] != -1) {
		index = arr[index+1];
		count++;
	}
	return count;
}


void displayList(int arr[], struct LinkedList l) {
	int index = l.head;

	if(index == -1){
		printf("List is empty!\n");
		return;
	}

	while(index != -1) {
		int next = arr[index+1];
		int prev = arr[index+2];
		printf("%d\t", arr[index]);
		
		if(next == -1)
			printf("NIL\t");
		
		else 
			printf("%d\t", arr[index+1]);

		if(prev == -1)
			printf("NIL\n");

		else
			printf("%d\n", arr[index+2]);
		index = arr[index+1];
	}
	printf("\n");
}
