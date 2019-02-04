#include <stdio.h>
#include "linkedlist.h"
#include "free.h"
#include "defrag.h"

#define NUM_LISTS 10
#define SIZE 999

int num_ = -1;
int arr[SIZE];


struct LinkedList initializeFreeList(int arr[], int size) {
	struct LinkedList f;
	f.head = 0;
	for(int i = 0; i < size - 3; i=i+3) {
		arr[i+1] = i + 3;
	}
	arr[size-3+1] = -1;
	return f;
}


int getChoice() {
	int choice;
	printf("\t1. Create a new list\n");
	printf("\t2. Insert a new element in a given list in sorted order\n");
	printf("\t3. Delete an element from a given list\n");
	printf("\t4. Count total elements excluding free list\n");
	printf("\t5. Count total elements of a list\n");
	printf("\t6. Display all lists\n");
	printf("\t7. Display free list\n");
	printf("\t8. Perform defragmentation\n");
	printf("\t9. Press 0 to exit\n");	
	printf("\nSelect an option: ");
	scanf("%d", &choice);
	return choice;
}


int main() {
	int choice;
	struct LinkedList list[NUM_LISTS];
	struct LinkedList freeList = initializeFreeList(arr, SIZE);
	
	do {
		choice = getChoice();
		int listID, ele;
		
		switch(choice) {
			case 1: 
				if(num_ == NUM_LISTS - 1) {
					printf("Can't create more lists\n");
					break;
				}

				num_++;
				list[num_] = createNewList();
				printf("Created a New List: List No %d\n", num_);
				printf("Enter key value to insert into the list: ");
				scanf("%d", &ele);
				insertList(arr, &freeList, &list[num_], ele);
				break;

			case 2:
				if(num_ == -1) {
					printf("Create a list first\n");
					break;
				}

				printf("Enter list you want to insert in: ");
				scanf("%d", &listID);

				if(listID > num_) {
					printf("Invalid input\n");
					break;
				}

				printf("Enter key value to be inserted: ");
				scanf("%d", &ele);
				insertList(arr, &freeList, &list[listID], ele);
				break;

			case 3: 
				if(num_ == -1) {
					printf("Create a list first\n");
					break;
				}

				printf("Enter list you want to delete from: ");
				scanf("%d", &listID);

				if(listID > num_) {
					printf("Invalid input\n");
					break;
				}

				if(list[listID].head == -1) {
					printf("Failure: List is empty!\n");
					break;
				}

				printf("Enter key value to be deleted: ");
				scanf("%d", &ele);
				deleteFromList(arr, &freeList, &list[listID], ele);
				break;

			case 4: 
				if(num_ == -1) {
					printf("Create a list first\n");
					break;
				}

				int count = 0;
				for(int i = 0; i <= num_; i++) {
					count += listSize(arr, list[i]);
				}
				printf("Total elements are: %d\n", count);
				break;

			case 5: 
				if(num_ == -1) {
					printf("Create a list first\n");
					break;
				}

				printf("Enter List number: ");
				scanf("%d", &listID);

				if(listID > num_) {
					printf("Invalid input\n");
					break;
				}

				printf("List %d has %d elements\n", listID, listSize(arr, list[listID]));
				break;

			case 6: 
				if(num_ == -1) {
					printf("Create a list first\n");
					break;
				}

				for(int i = 0; i <= num_; i++) {
					printf("Printing List %d: \n", i);
					if(list[i].head == -1) {
						printf("List is empty!\n\n");
						continue;
					}
					printf("key\tnext\tprev\n");
					displayList(arr, list[i]);
					printf("\n");
				}
				break;

			case 7: 
				printFreeList(arr, freeList);
				break;

			case 8: 
				if(num_ == -1) {
					printf("Create a list first\n");
					break;
				}

				defragment(arr, list, &freeList, num_, SIZE);
				for(int i = 0; i < SIZE; i++) 
					printf("%d ", arr[i]);
				printf("\n");
				break;

			case 0:
				printf("Exiting!\n");
				break;

			case 9: 
				printf("Exiting!\n");
				break;

			default: 
				printf("Please enter a valid choice\n");
				break;
		}
		printf("\n");

	} while(choice != 0 && choice != 9);
}