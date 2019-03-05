#include <stdio.h>
#include <string.h>
#include "employee.h"


void insertionSort(Employee* e, int size) {
	for(int i = 1; i < size; i++) {
		Employee key = e[i];
		int j = i - 1;
		while(j >= 0 && e[j].empID > key.empID) {
			e[j+1] = e[j];
			j--;
		}
		e[j+1] = key;
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

// 	insertionSort(e, 10);
// 	printList(e, 10);
// }