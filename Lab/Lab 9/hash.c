#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"


int hashFunction(char* string, int baseNumber, int tableSize) {
	int hashValue = 0;
	for(int i = 0; i < strlen(string); i++) 
		hashValue += string[i];
	
	hashValue = hashValue % baseNumber;
	hashValue = hashValue % tableSize;
	if (hashValue < 0)
		hashValue += tableSize;

	return hashValue;
}


int collisionCount(char* strings[], int baseNumber, int tableSize, int num_strings) {
	int count = 0; // to store number of collisions
	int arr[num_strings]; // store hash value for each string

	for(int i = 0; i < num_strings; i++) 
		arr[i] = hashFunction(strings[i], baseNumber, tableSize);

	for(int i = 1; i < num_strings; i++) {
		for(int j = i - 1; j >= 0; j--) {
			if(arr[i] == arr[j]) { // if clash occurs
				count++;
				break;
			}
		}
	}
	return count;
}


char** parser(FILE* f) {
	char* books[50000];
	char* word = (char*) malloc(sizeof(char) * 50); // to scan each word
	int num_strings = 0;

	while (fscanf(f, "%s", word) != EOF) {
		fgetc(f); // remove space character
		int flag = 0; // to indicate whether word contains non-alphabets

		for(int i = 0; i < strlen(word); i++) {
			if(!((word[i] >= 'A' && word[i] <= 'Z') || (word[i] >= 'a' && word[i] <= 'z'))) {
				flag = 1; // string contains a non-alphabet
				break;
			}
		}

		if(!flag) {
			books[num_strings] = (char*) malloc(sizeof(char) * strlen(word));
			strcpy(books[num_strings], word);
			num_strings++;
			printf("%s\n", word);
		}
	}
	free(word);
	printf("Number of valid strings: %d\n", num_strings);
	return books;
}


