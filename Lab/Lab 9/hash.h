#ifndef _HASH
#define _HASH


int hashFunction(char* string, int baseNumber, int tableSize);

int collisionCount(char** strings, int num_strings, int baseNumber, int tableSize);


#endif