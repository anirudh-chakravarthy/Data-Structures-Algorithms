#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"
#include "parser.h"


int main() {
	for(int i = 0; i < 50000; i++) 
		hashTable[i] = -1;
	
	char** book;
	book = parser("aliceinwonderland.txt");
}
