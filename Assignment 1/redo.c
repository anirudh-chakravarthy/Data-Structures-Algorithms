#include <stdio.h>
#include "linkedlist.h"
#include "free.h"
#include "defrag.h"


void defragment(int arr[], struct LinkedList list[], struct LinkedList* free, int num_lists, int size) {
	int count = 0;
	int drr[size]; // defragmented array
	for(int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	int freeIndex = free->head;

	if(freeIndex == -1) {
		printf("Success: Trivially Fragmented!");
		return;
	}

	// iterate over lists
	for(int i = 0; i <= num_lists; i++) {
		int top = list[i].head;

		if(top == -1)
			continue;

		// first element insertion
		list[i].head = count;
		drr[count] = arr[top];
		drr[count+2] = -1;
		top = arr[top+1];

		// only one element
		if(top == -1) {
			drr[count+1] = -1;
			count += 3;
			continue;
		}

		drr[count+1] = count+3;
		count += 3;

		while(top != -1) {

			// last element
			if(arr[top+1] == -1) {
				drr[count] = arr[top];
				drr[count+1] = -1;
				drr[count+2] = count-3;
				count += 3;
				break;
			}

			drr[count] = arr[top];
			drr[count+1] = count + 3;
			drr[count+2] = count - 3;
			top = arr[top+1];
			count += 3;
		}

	}

	struct LinkedList dfree;
	dfree.head = count;

	for(int i = count; i < size-3; i=i+3) {
		drr[i+1] = i+3;
	}

	drr[size-3+1] = -1;
	free = &dfree;
	for(int i = 0; i < size; i++) {
		arr[i] = drr[i];
	}
}