#include "linkedlist.h"

int main(int argc, char* argv[]) {
	FILE* fptr = fopen(argv[1], "r");
	struct linkedList* head = (struct linkedList*) malloc(sizeof(struct linkedList));
	
	while(!feof(fptr)) {
		int temp;
		fscanf(fptr, "%d", &temp);
		// insert temp into the linked list.
		if(!feof(fptr))
			insertFirst(head, temp);
	}

	fclose(fptr);
	printList(head);
	deleteFirst(head);
	printList(head);

//	fptr = fopen("linkedlist.txt", "w");
//	printList(head);
	// do printList function here
}
