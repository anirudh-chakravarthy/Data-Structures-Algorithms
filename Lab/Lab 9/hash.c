#include <stdio.h>
#include <string.h>

#include "hash.h"


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


int collisionCount(char** stringArray, int numberOfStrings, int baseNumber, int tableSize) {
	int count = 0;
	for(int i = 0; i < numberOfStrings; i++) {
		int result = hash(stringArray[i], baseNumber, tableSize);
		if (hashTable[i] != -1)
			count++;
		else
			hashTable[i] = result;
	}
	return count;
}
