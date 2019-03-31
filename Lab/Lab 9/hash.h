#ifndef _HASH
#define _HASH

int hashTable[50000];


int hash(char* string, int baseNumber, int tableSize);

int collisionCount(char** stringArray, int numberOfStrings, int baseNumber, int tableSize);

#endif