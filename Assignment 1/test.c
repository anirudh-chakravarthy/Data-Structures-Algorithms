#include <stdio.h>
#include "free.h"
#include "linkedlist.h"
#include "defrag.h"

#define SIZE 9


struct LinkedList initializeFreeList(int arr[], int size) {
	struct LinkedList f;
	f.head = 0;
	for(int i = 0; i < size - 3; i=i+3) {
		arr[i+1] = i + 3;
	}
	arr[size-3+1] = -1;
	return f;
}


int main() {
	int arr[SIZE]= {0};
	struct LinkedList free = initializeFreeList(arr, SIZE);
	for(int i = 0; i < SIZE; i++) {
		printf("%d ", arr[i]);
	}
	// struct LinkedList list;

	// pop(arr, &free);
	// printFreeList(arr, free);
	// pop(arr, &free);
	// printFreeList(arr, free);
	// pop(arr, &free);
	// printFreeList(arr, free);
	// pop(arr, &free);
	// printFreeList(arr, free);
	// pop(arr, &free);
	// printFreeList(arr, free);

	// int index = free.head;
	// printFreeList(arr, free);

	// defrag(arr, list);


	// int ele = pop(arr, &free);
	// printf("%d\n", ele);
	// ele = pop(arr, &free);
	// printf("%d\n", ele);
	// ele = pop(arr, &free);
	// printf("%d\n", ele);
	// ele = pop(arr, &free);
	// printf("%d\n", ele);
	// for(int i = 0; i < SIZE; i++){
	// 	printf("%d ", arr[i]);
	// }
	// printf("\n");

	// push(arr, free, 9);
	// for(int i = 0; i < SIZE; i++){
	// 	printf("%d ", arr[i]);
	// }
	// printf("\n");

	// struct LinkedList l = createNewList();
	// printf("%d \n", listSize(arr, l));

	// insertList(arr, free, &l, 2);
	// printf("%d \n", listSize(arr, l));
	// //displayList(arr, l);

	// insertList(arr, free, &l, 1);
	// printf("%d \n", listSize(arr, l));
	// //displayList(arr, l);

	// insertList(arr, free, &l, 3);
	// displayList(arr, l);
	// printf("%d \n", listSize(arr, l));

	// deleteFromList(arr, free, &l, 2);
	// displayList(arr, l);
	// printf("%d \n", listSize(arr, l));

	// deleteFromList(arr, free, &l, 1);
	// displayList(arr, l);

}