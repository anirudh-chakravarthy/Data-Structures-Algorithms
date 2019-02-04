#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "cycle.h"

int main() {
	struct LinkedList ls = createList(10);
	ls = createCycle(ls);
	if(testCyclic(ls))
		printf("TRUE!");
	else
		printf("FALSE");
}


