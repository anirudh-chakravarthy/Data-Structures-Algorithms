#ifndef _HASH
#define _HASH


int hashFunction(char* string, int baseNumber, int tableSize);

int collisionCount(char** strings, int baseNumber, int tableSize, int num_strings);

char** parser(FILE* f);

#endif