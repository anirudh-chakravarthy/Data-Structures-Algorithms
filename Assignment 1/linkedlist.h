#ifndef _LINKEDLIST
#define _LINKEDLIST
#include <stdio.h>


// a doubly linked list
struct LinkedList {
	int head;
};

// to create a new list
struct LinkedList createNewList();

// to insert an element ele into a list l in sorted order
void insertList(int arr[], struct LinkedList* free, struct LinkedList* l, int ele);

// to delete an element ele from the given list l
void deleteFromList(int arr[], struct LinkedList* free, struct LinkedList* l, int ele);

// to return size of list
int listSize(int arr[], struct LinkedList l);

// to display contents of a list
void displayList(int arr[], struct LinkedList l);

#endif