#ifndef _EMPL
#define _EMPL


typedef struct {
	int empID;
	char name[11];
} Employee;


void printList(Employee* e, int size);

#endif