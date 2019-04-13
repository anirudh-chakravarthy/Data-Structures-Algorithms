#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"


int hashFunction(char* string, int baseNumber, int tableSize) {
	int result = 0;

	for(int i = 0; i < strlen(string); i++) 
		result += string[i];
	result %= baseNumber;
	result %= tableSize;

	if(result < 0)
		result += tableSize;

	return result;
}


int collisionCount(char** strings, int num_strings, int baseNumber, int tableSize) {
	
	// to store hash Value of each string
	int arr[num_strings];
	int count = 0;
	
	for(int i = 0; i < num_strings; i++) 
		arr[i] = hashFunction(strings[i], baseNumber, tableSize);
	
	for(int i = 1; i < num_strings; i++) {
		for(int j = i-1; j >= 0; j--) {
			if(arr[i] == arr[j]) {
				count++;
				break;
			}
		}
	}
	return count;
}