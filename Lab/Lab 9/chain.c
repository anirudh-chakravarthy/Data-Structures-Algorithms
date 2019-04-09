#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"
#include "chain.h"


table* createTable() {
	table* t = (table*) malloc(sizeof(table));
	t->head = (struct node**) malloc(sizeof(struct node*) * 50000);
	t->elementCount = 0;
	t->insertionCost = 0;
	t->queryingCost = 0;
	return t;
} 


table* insert(table* t, char** books, char* string, int index) {
	int insertionCost = 0;
	int hashValue = hashFunction(string, 53591, 50000);
	struct node* tmp = t->head[hashValue];
	int flag = 0;

	// table has no entry at the specified index
	if(tmp == NULL) {
		struct node* newNode = (struct node*) malloc(sizeof(struct node));
		newNode->key = index;
		newNode->next = NULL;
		newNode->count = 1;

		t->head[index] = newNode;
		t->elementCount++;
		printf("\tInserted %s\n\n", string);
		return t;
	}

	// find whether entry exists in the table
	while(tmp != NULL) {
		if(strcmp(books[tmp->key], books[index]) == 0) {
			tmp->count++;
			flag = 1;
			printf("\tEntry %s already exists %d times\n\n", string, tmp->count);
			break;
		}

		// if not found even in last node
		if(tmp->next == NULL)
			break;

		tmp = tmp->next;
		insertionCost++;
	}

	// entry doesn't exist so add it at end of chain
	if(!flag) {
		struct node* newNode = (struct node*) malloc(sizeof(struct node));
		newNode->key = index;
		newNode->next = NULL;
		newNode->count = 1;
		tmp->next = newNode;
		t->elementCount++;
		printf("\tInserted %s at the end\n\n", string);
	}
	t->insertionCost += insertionCost;
	return t;
}


int insertAll(table* t, char** books, int num_strings) {
	for(int i = 0; i < num_strings; i++) {
		printf("Inserting String no.: %d, String: %s\n", i, books[i]);
		t = insert(t, books, books[i], i);
	}
	return t->insertionCost;
}


struct node* lookup(table* t, char** books, char* string) {
	int hashValue = hashFunction(string, 53591, 50000);
	struct node* tmp = t->head[hashValue];
	int queryingCost = 0;
	
	while(tmp != NULL) {
		if(strcmp(books[tmp->key], string) == 0) {
			t->queryingCost += queryingCost;
			return tmp;			
		}
		tmp = tmp->next;
		queryingCost++;
	}
	return NULL;
}


int lookupAll(table* t, char** books, char** strings, int num_strings, double percent) {
	num_strings = (int) (num_strings * percent);
	t->queryingCost = 0;
	for(int i = 0; i < num_strings; i++)
		lookup(t, books, strings[i]);

	return t->queryingCost;
}


table* cleanup(FILE* f, table* t, char** books) {
	char word[50];
	while(fscanf(f, "%s\n", word) != EOF) {
		int hashValue = hashFunction(word, 53591, 50000);
		struct node* tmp = t->head[hashValue];

		// entry doesn't exist
		if(tmp == NULL) {
			printf("String %s not found\n", word);
			continue;
		}

		// only 1 node
		if(tmp->next == NULL) {
			if(strcmp(books[tmp->key], word) == 0) {
				tmp->count--;
				printf("String %s deleted\n", word);
				if(tmp->count == 0) {
					t->elementCount--;
					free(tmp);
				}
			}
			continue;
		}

		struct node* prev = tmp;
		tmp = tmp->next;
		int flag = 0;

		while(tmp != NULL) {
			if(strcmp(books[tmp->key], word) == 0) {
				tmp->count--;
				flag = 1;
				printf("String %s deleted\n", word);
				if(tmp->count == 0) {
					t->elementCount--;
					prev->next = tmp->next;
					free(tmp);
				}
				break;
			}

			tmp = tmp->next;
			prev = prev->next;
		}

		// element not found
		if(!flag) 
			printf("String %s not found\n", word);
	}

	return t;
}

