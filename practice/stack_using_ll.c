#include <stdio.h>
#include <stdlib.h>

struct node {
	int ele;
	struct node* next;
};

struct LinkedList {
	struct node* head;
	struct node* tail;
};


struct Stack {
	struct LinkedList* first;
	struct LinkedList* second;
};


void push(struct Stack s, int element) {
	struct node* newele = (struct node*) malloc(sizeof(struct node));
	newele->ele = element;
	newele->next = NULL;
	s.second->tail = newele;
}


int pop(struct Stack s) {
	if(s.first->head == NULL) {
		printf("Stack is already empty!");
		return -1;
	}

	if(s.second->head == NULL) {
		struct node* tmp = s.first->head;
		while(tmp->next != s.first->tail) 
			tmp = tmp->next;
		tmp->next = NULL;
		int element = s.first->tail->ele;
		free(s.first->tail);
		s.first->tail = tmp;
		return element;
	}

	struct node* tmp = s.second->head;
	while(tmp->next != s.second->tail)
		tmp = tmp->next;
	tmp->next = NULL;
	int element = s.second->tail->ele;
	free(s.second->tail);
	s.second->tail = tmp;
	return element;
}


void printStack(struct Stack s) {
	struct LinkedList* one = s.first;
	struct LinkedList* two = s.second;

	if(one->head == NULL && two->head == NULL) {
		printf("Stack is empty\n");
		return;
	}

	while(one->head != NULL) {
		printf("%d ", one->head->ele);
		one->head = one->head->next;
	}

	while(two->head != NULL) {
		printf("%d", two->head->ele);
		two->head = two->head->next;
	}
	printf("\n");
}


struct Stack returnStack() {
	struct node a, b;
	a.ele = 1;
	b.ele = 2;
	a.next = &b;
	b.next = NULL;

	struct LinkedList first;
	first.head = &a;
	first.tail = &b;

	a.ele = 3;
	b.ele = 4;
	a.next = &b;
	b.next = NULL;

	struct LinkedList second;
	second.head = &a;
	second.tail = &b;

	struct Stack s;
	s.first = &first;
	s.second = &second;
	return s;
}


int main() {
	struct Stack s = returnStack();
	push(s, 5);
	printStack(s);
	pop(s);
	printStack(s);
}
