#ifndef _STACK
#define _STACK

#define MAX 500


typedef struct {
	int arr[MAX];
	int count;
} Stack;


void push(Stack* s, int start);

int pop(Stack* s);

int isEmpty(Stack* s);

#endif