#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"
#include "chain.h"


Hashtable* createTable(int tableSize) {
	Hashtable* t = (Hashtable*) malloc(sizeof(Hashtable));
	t->head = (struct node**) malloc(sizeof(struct node*) * tableSize);
	for(int i = 0; i < tableSize; i++) 
		t->head[i] = NULL;

	t->elementCount = 0;
	t->insertionCost = 0;
	t->queryingCost = 0;
	return t;
}


Hashtable* insert(Hashtable* t, char** book, int index, char** strings, int num_strings) {
	int insertionCost = 0;

	for(int i = 0; i < num_strings; i++) {
		int hashValue = hashFunction(strings[i], 5023, 5000);
		struct node* tmp = t->head[hashValue];

		while(tmp != NULL) {
			if(strcmp(book[tmp->key], book[index]) == 0) {
				tmp->count++;
				t->insertionCost += insertionCost;
				printf("Found: %s\n", book[index]);
				return t;
			}
			insertionCost++;

			// to store last node
			if(tmp->next == NULL)
				break;
			tmp = tmp->next;
		}

		struct node* newNode = (struct node*) malloc(sizeof(struct node));
		newNode->key = index;
		newNode->count = 1;
		newNode->next = NULL;
		t->elementCount++;
		printf("Inserted: %s\n", book[index]);

		if(t->head[hashValue] == NULL)
			t->head[hashValue] = newNode;

		else
			tmp->next = newNode;
	}

	t->insertionCost += insertionCost;
	return t;
}


int insertAll(Hashtable* t, char** book) {
	int insertionCost = t->insertionCost;
	for(int i = 0; i < 22698; i++) {
		char** strings = (char**) malloc(sizeof(char*));
		strings[0] = (char*) malloc(sizeof(char) * strlen(book[i]));
		strcpy(strings[0], book[i]);
		t = insert(t, book, i, strings, 1);
	}
	return t->insertionCost - insertionCost;
}


struct node* lookup(Hashtable* t, char** book, char* string) {
	int hashValue = hashFunction(string, 5023, 5000);
	struct node* tmp = t->head[hashValue];
	int queryingCost = 0;

	while(tmp != NULL) {
		if(strcmp(book[tmp->key], string) == 0) {
			printf("Found: %s at index %d\n", string, tmp->key);
			t->queryingCost += queryingCost;
			return tmp;
		}
		queryingCost++;
		tmp = tmp->next;
	}

	t->queryingCost += queryingCost;
	return tmp;
}


int lookupAll(Hashtable* t, char** book, char** strings, int num_strings, double m) {
	t->queryingCost = 0;
	num_strings = (int) (num_strings * m);

	for(int i = 0; i < num_strings; i++) 
		lookup(t, book, strings[i]);
	
	return t->queryingCost;
}


Hashtable* cleanup(FILE* f, Hashtable* t, char** book) {
	char* word = (char*) malloc(sizeof(char) * 50);

	while(fscanf(f, "%s\n", word) != EOF) {
		int hashValue = hashFunction(word, 5023, 5000);
		struct node* tmp = t->head[hashValue];

		// node is empty
		if(tmp == NULL) {
			printf("String: %s not found\n", word);
			continue;
		}

		// only 1 node
		if(tmp->next == NULL) {
			if(strcmp(book[tmp->key], word) == 0) {
				tmp->count--;
				printf("String: %s deleted\n", word);
				if(tmp->count == 0) {
					t->elementCount--;
					free(tmp);
				}
			}
			printf("String: %s not found\n", word);
			continue;
		}

		// deletion from head of list
		if(strcmp(book[tmp->key], word) == 0) {
			tmp->count--;
			printf("String: %s deleted\n", word);
			if(tmp->count == 0) {
				t->elementCount--;
				t->head[hashValue] = tmp->next;
				free(tmp);
			}
			continue;
		}

		struct node* prev = tmp;
		tmp = tmp->next;
		int flag = 0;

		while(tmp != NULL) {
			if(strcmp(book[tmp->key], word) == 0) {
				tmp->count--;
				flag = 1;
				printf("String: %s deleted\n", word);
				if(tmp->count == 0) {
					t->elementCount--;
					prev->next = tmp->next;
					free(tmp);
				}
				break;
			}	
			prev = prev->next;
			tmp = tmp->next;
		}

		if(!flag)
			printf("String: %s not found\n", word);
	}
	free(word);
	return t;
}
