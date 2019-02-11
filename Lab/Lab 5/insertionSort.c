#include <stdio.h>
#include "creditcard.h"
#include "insertionSort.h"


void insertionSort(struct CreditCard* c, int n) {
	struct CreditCard record = c[n-1];
	if(n > 1)
		insertionSort(c, n-1);
	insertInOrder(c, record, n);
}
