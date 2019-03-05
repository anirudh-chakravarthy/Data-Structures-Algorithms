#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"
#include "employee.h"


void swap(Employee* e, int i, int j) {
	Employee tmp = e[i];
	e[i] = e[j];
	e[j] = tmp;
}


int partition(Employee* e, int start, int end) {
	Employee pivot = e[end];
	int i = start - 1;

	for (int j = start; j < end; j++) {
		if (e[j].empID <= pivot.empID) {
			i++;
			swap(e, i, j);
		}
	}

	swap(e, i+1, end);
	return i+1;
}


// if size < minSize, we prefer insertion sort
void quickSort(Employee* e, int size, int minSize) {
	Stack s;
	s.count = 0;
	for(int i = 0; i < MAX; i++) 
		s.arr[i] = 0;

	push(&s, 0);
	push(&s, size-1);

	while (!isEmpty(&s)) {
		int end = pop(&s);
		int start = pop(&s);
		int size = end - start + 1;
		printf("%d %d %d\n", size, start, end);

		if(size <= minSize) 
			continue;
		
		int mid = partition(e, start, end);
		push(&s, start);
		push(&s, mid-1);

		push(&s, mid);
		push(&s, end);
	}
}


// int main() {
// 	Employee e[10];
// 	int index = 0;

// 	FILE* f = fopen("10", "r");
// 	char name[11];
// 	int id;

// 	while(!feof(f)) {
// 		fscanf(f, "%s %d\n", name, &id);
// 		strcpy(e[index].name, name);
// 		e[index].empID = id;
// 		index++; 
// 	}

// 	// printList(e, 10);

// 	// int mid = partition(e, 0, 3);
// 	// printf("%d\n", mid);

// 	printf("\n");
// 	quickSort(e, 10, 1);
// 	printList(e, 10);
// }