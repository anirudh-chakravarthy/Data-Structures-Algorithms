#ifndef _QS
#define _QS

#include "employee.h"

void swap(Employee* e, int i, int j);

int partition(Employee* e, int start, int end);

void quickSort(Employee* e, int size, int minSize);

#endif