#include <stdio.h>
#include "stack.h"


void push(Stack* s, int start) {
	int index = s->count;
	if(index == MAX) {
		printf("Stack is full\n");
		return;
	}

	s->arr[index] = start;
	s->count++;
}


int pop(Stack* s) {
	int index = s->count;
	if(isEmpty(s)) {
		printf("Stack is empty\n");
		return -1;
	}

	s->count--;
	return s->arr[index-1];
}


int isEmpty(Stack* s) {
	if (s->count == 0)
		return 1;
	return 0;
}
