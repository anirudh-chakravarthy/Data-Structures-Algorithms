#include <stdio.h>
#include <string.h>

#include "chainHash.h"


int hash(char* string, int baseNumber, int tableSize) {
	int length = strlen(string);
	int result = 0;
	for(int i = 0; i < length; i++) 
		result += string[i];
	result %= baseNumber;
	result %= tableSize;

	if (result < 0)
		result += tableSize;

	return result;
}


hashTable createTable() {
	hashTable h;
	h.head = (struct node**) malloc(sizeof(struct node*) * 500000); 
	h.elementCount = 0;
	h.insertionCost = 0;
	h.queryingCost = 0;
	return h;
}


int insertAll(hashTable h, char** book, int numberOfStrings) {
	int insertionCost = 0;

	for(int i = 0; i < numberOfStrings; i++) {
		int hashValue = hash(book[i], 551003, 500000);
		h.elementCount++;

		if (h.head[hashValue] == NULL) {
			struct node* newNode = (struct node*) malloc(sizeof(struct node));
			newNode->element = i;
			newNode->next = NULL;
			newNode->count = 1;

			h.head[hashValue] = newNode;
			h.head[hashValue]->next = NULL;
			continue;
		}

		// to reach matching string in the chain
		struct node* tmp = h.head[hashValue];
		int flag = 0; // set if match found
		while(tmp->next != NULL) {
			if (strcmp(book[tmp->ele], book[i])) {
				tmp->count++;
				h.queryingCost++;
				flag = 1;	
				break;			
			}
			else {
				tmp = tmp->next;
				insertionCost++;
			}
		}

		if(flag) 
			continue;

		// if no match is found
		struct node* newNode = (struct node*) malloc(sizeof(struct node));
		newNode->element = i;
		newNode->next = NULL;
		newNode->count = 1;
		tmp->next = newNode;
	}

	h.insertionCost += insertionCost;
	return insertionCost;
}