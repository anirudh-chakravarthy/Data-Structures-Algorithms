#include <stdio.h>
#include "employee.h"


void printList(Employee* e, int size) {
	for(int i = 0; i < size; i++) {
		printf("%s, %d\n", e[i].name, e[i].empID);
	}
}