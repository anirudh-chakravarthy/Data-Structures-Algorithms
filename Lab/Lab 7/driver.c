#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "employee.h"
#include "stack.h"
#include "quickSort.h"
#include "insertionSort.h"


 int main() {
	Employee e[10];
	int index = 0;

	FILE* f = fopen("10", "r");
	char name[11];
	int id;

	while(!feof(f)) {
		fscanf(f, "%s %d\n", name, &id);
		strcpy(e[index].name, name);
		e[index].empID = id;
		index++; 
	}

	// printList(e, 10);

	// int mid = partition(e, 0, 3);
	// printf("%d\n", mid);

	// printf("\n");
	quickSort(e, 10, 1);
	insertionSort(e, 10);
	printList(e, 10);
}